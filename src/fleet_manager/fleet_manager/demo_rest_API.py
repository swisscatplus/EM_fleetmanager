"""
demo_rest_api.py  -  REST API to send the robot to a station (demo day).

WHY a new one (and not fleet_manager/rest_api.py):
    rest_api.py only replays FIXED paths from tracker/config/paths.yaml (path_id per station pair).
    For LC MS <-> OmniFire those paths (108 / 118) are disabled and wrong (their "OmniFire" end is
    Chemspeed's spot), and fixed paths cannot turn in place.
    This server instead uses YOUR planner + path_sender (the code that already works with
    `python3 path_sender.py -p goal:=...`): each move is planned from where the robot REALLY is.

Put this file in the SAME folder as path_sender.py and path_planner.py (demo_loop.py is NOT needed)
(/ros2_ws/src/fleet_manager/fleet_manager in the fleet_manager container), then:

    python3 demo_rest_api.py --ros-args -p robot:=robot1 -p port:=8001

Port 8001 because the old rest_api.py already uses 8000 in the same container.

Endpoints (JSON, http://<laptop IP>:8001):
    GET  /api/v1/health          ready? (robot localized + tracker running)
    GET  /api/v1/stations        station names, which ones can be used
    GET  /api/v1/pose            current robot pose (x, y, yaw) -> handy to MEASURE a docking pose
    GET  /api/v1/status          what the robot is doing now + last move
    GET  /api/v1/moves/<id>      one move
    POST /api/v1/moves           {"station_end": "OmniFire"}               start a move, answers at once (202)
                                 {"station_end": "OmniFire", "wait": true} answers only when the move is over
                                 "station_start" is optional (same format as the old API): only checked,
                                 the robot always plans from its real position.
    POST /api/v1/stop            stop the robot now, cancel the move

Station names are forgiving: "LCMS", "lc ms", "LC_MS" all mean "LC MS"; "omnifire" = "OmniFire".

How it works (2 threads):
    - main thread  : ROS. PathSender (path_sender.py) runs its usual 10 Hz loop; a second timer
                     (manage) starts moves, sees when they end, checks the robot is at the station,
                     retries once if not.
    - HTTP thread  : answers requests. It NEVER touches the robot directly: it puts the request in
                     a queue, and the ROS thread does it. So the two threads cannot fight.

Ctrl+C stops the robot (like path_sender). Emergency stop is still Ctrl+C in the up_stack terminal.
"""

import itertools
import json
import math
import queue
import threading
import time
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

import rclpy
from nav_msgs.msg import Path

from path_sender import PathSender, wrap

SETTLE = 0.5         # s to wait after a trip, before checking the robot is at the station (TF catches up)
RETRY_WAIT = 3.0     # s before trying a failed move again
START_CHECK = 0.30   # m: robot further than this from station_start -> warning in the answer
HISTORY = 50         # moves kept for GET /moves/<id>
AT_STATION_DIST = 0.15   # m: robot this close to the docking point = move OK
AT_STATION_YAW = 0.3     # rad (~17 deg)


def reset_for_trip(node, goal):
    """put the PathSender back in its starting state, with a new goal (its loop then drives there)"""
    node.goal = goal
    node.state = "plan"
    node.done = False
    node.n_plans = 0
    node.steps, node.step = [], None
    node.step_start = node.settle_until = 0.0
    node.final_turn = False
    node.tail = []                              # turn + creep left at a sideways station (SFC QTOF)
    node.still_pose, node.still_since = None, 0.0
    node.final_points, node.errors = [], []
    node.last_log = 0.0
    node.driven = Path()                        # new trail in RViz for each move
    node.driven.header.frame_id = "map"


def at_station(node, goal):
    """True if the robot really is at the station (position AND heading)"""
    pose = node.robot_pose()
    if pose is None:
        return False
    gx, gy, gyaw = node.planner.stations[goal]
    return math.dist(pose[:2], (gx, gy)) < AT_STATION_DIST and abs(wrap(pose[2] - gyaw)) < AT_STATION_YAW


def canon(name):
    """'LC MS', 'lcms', 'LC_MS' -> 'lcms'  (to compare station names)"""
    return "".join(c for c in str(name).lower() if c.isalnum())


class MoveManager:
    """Everything about moves. manage() runs in the ROS thread; the other methods are called by HTTP."""

    def __init__(self, node, retries):
        self.node = node
        self.retries = retries
        self.lock = threading.Lock()        # protects active / moves / pose (read by HTTP)
        self.requests = queue.Queue()       # HTTP -> ROS thread
        self.ids = itertools.count(1)
        self.active = None                  # the move being done, or None
        self.moves = {}                     # id -> move (dict)
        self.pose = None                    # last robot pose (x, y, yaw), updated by the ROS thread
        names = list(node.planner.stations) + list(node.planner.skipped)
        self.by_canon = {canon(n): n for n in names}

    # ------------------------------------------------------------------ called by HTTP threads
    def station(self, name):
        return self.by_canon.get(canon(name))

    def ready(self):
        """(True/False, reason)"""
        if self.pose is None:
            return False, f"no TF map -> {self.node.robot}/base_link (robot not started / not localized)"
        x, y, yaw = self.pose
        if abs(x) < 0.005 and abs(y) < 0.005 and abs(yaw) < 0.01:
            return False, "robot not localized yet (pose = map origin): the camera must see a marker"
        if self.node.path_pub.get_subscription_count() == 0:
            return False, f"tracker not running (nobody listens on /{self.node.robot}/path)"
        return True, "ok"

    def request_move(self, payload):
        """returns (http status, answer dict, move or None)"""
        end_raw = payload.get("station_end") or payload.get("goal")
        if not end_raw:
            return HTTPStatus.UNPROCESSABLE_ENTITY, {"success": False, "message": "station_end is required"}, None
        goal = self.station(end_raw)
        if goal is None:
            return HTTPStatus.NOT_FOUND, {"success": False,
                                          "message": f"unknown station '{end_raw}'",
                                          "stations": sorted(self.by_canon.values())}, None
        if goal in self.node.planner.skipped:
            return HTTPStatus.CONFLICT, {"success": False,
                                         "message": f"'{goal}' has no docking pose in stations.yaml yet: "
                                                    "measure it (GET /api/v1/pose at the station) and fill it in"}, None
        ok, why = self.ready()
        if not ok:
            return HTTPStatus.SERVICE_UNAVAILABLE, {"success": False, "message": why}, None

        warnings = []
        start_raw = payload.get("station_start")
        if start_raw:
            start = self.station(start_raw)
            if start is None or start not in self.node.planner.stations:
                warnings.append(f"station_start '{start_raw}' unknown or without pose: ignored")
            else:
                sx, sy, _ = self.node.planner.stations[start]
                d = math.dist(self.pose[:2], (sx, sy))
                if d > START_CHECK:
                    warnings.append(f"robot is {d:.2f} m from {start}: it plans from where it really is")

        with self.lock:
            if self.active is not None:
                return HTTPStatus.CONFLICT, {"success": False,
                                             "message": f"robot busy: move {self.active['id']} to "
                                                        f"{self.active['station_end']} in progress",
                                             "active": self.public(self.active)}, None
            move = {"id": next(self.ids), "station_start": start_raw, "station_end": goal,
                    "status": "queued", "success": None, "message": "", "warnings": warnings,
                    "attempts": 0, "created": time.time(), "started": None, "finished": None,
                    "done_event": threading.Event(), "phase_until": 0.0}
            self.active = move
            self.moves[move["id"]] = move
            for old in sorted(self.moves)[:-HISTORY]:
                del self.moves[old]
        self.requests.put(("move", move))
        return HTTPStatus.ACCEPTED, self.public(move), move

    def request_stop(self):
        self.requests.put(("stop", None))

    def public(self, move):
        """the move as JSON (without the internal fields)"""
        if move is None:
            return None
        out = {k: v for k, v in move.items() if k not in ("done_event", "phase_until")}
        end = move["finished"] or time.time()
        out["duration_s"] = round(end - move["started"], 1) if move["started"] else None
        return out

    def status(self):
        with self.lock:
            last = max(self.moves.values(), key=lambda m: m["id"]) if self.moves else None
            ok, why = self.ready()
            return {"ready": ok, "ready_reason": why,
                    "busy": self.active is not None,
                    "robot_step": self.node.state if self.active else "idle",   # plan / turn / leg / final / creep ...
                    "pose": self.pose_dict(),
                    "active": self.public(self.active),
                    "last": self.public(last)}

    def pose_dict(self):
        if self.pose is None:
            return None
        x, y, yaw = self.pose
        return {"x": round(x, 3), "y": round(y, 3), "yaw": round(yaw, 4), "yaw_deg": round(math.degrees(yaw), 1)}

    # ------------------------------------------------------------------ ROS thread (timer, 10 Hz)
    def manage(self):
        node = self.node
        pose = node.robot_pose()
        with self.lock:
            self.pose = pose

        # 1. requests from HTTP
        while True:
            try:
                kind, move = self.requests.get_nowait()
            except queue.Empty:
                break
            if kind == "stop":
                self.stop_robot()
                if self.active is not None:
                    self.finish(False, "stopped by POST /api/v1/stop")
            elif kind == "move" and move is self.active:
                self.start(move)

        # 2. follow the active move
        move = self.active
        if move is None:
            return
        now = time.monotonic()
        if move["status"] == "moving" and node.done:
            node.state = "idle"                       # PathSender does nothing until the next start
            move["status"] = "checking"
            move["phase_until"] = now + SETTLE
        elif move["status"] == "checking" and now > move["phase_until"]:
            if at_station(node, move["station_end"]):
                node.summary()
                self.finish(True, f"arrived at {move['station_end']}")
            else:
                self.stop_robot()
                if move["attempts"] <= self.retries:
                    node.get_logger().warn(f"move {move['id']}: not at {move['station_end']}, "
                                           f"trying again in {RETRY_WAIT:.0f} s")
                    move["status"] = "retry_wait"
                    move["phase_until"] = now + RETRY_WAIT
                else:
                    self.finish(False, f"not at {move['station_end']} after {move['attempts']} attempt(s): "
                                       "check the robot (localization? stuck?)")
        elif move["status"] == "retry_wait" and now > move["phase_until"]:
            self.start(move)

    def start(self, move):
        move["attempts"] += 1
        move["status"] = "moving"
        if move["started"] is None:
            move["started"] = time.time()
        reset_for_trip(self.node, move["station_end"])   # PathSender: state = "plan" -> its loop drives
        self.node.get_logger().info(f"===== move {move['id']} -> {move['station_end']} "
                                    f"(attempt {move['attempts']}) =====")

    def stop_robot(self):
        node = self.node
        node.stop_everything()          # stops a turn/creep, or clears the tracker path
        node.clear_tracker()
        node.stop_robot()
        node.state = "idle"
        node.done = True

    def finish(self, success, message):
        with self.lock:
            move = self.active
            move["status"] = "succeeded" if success else "failed"
            move["success"] = success
            move["message"] = message
            move["finished"] = time.time()
            self.active = None
        # two separate lines: ROS refuses info AND error from the same line of code
        if success:
            self.node.get_logger().info(f"move {move['id']} -> {move['station_end']}: {message}")
        else:
            self.node.get_logger().error(f"move {move['id']} -> {move['station_end']}: {message}")
        move["done_event"].set()


def make_handler(manager):
    class Handler(BaseHTTPRequestHandler):
        protocol_version = "HTTP/1.1"

        def do_GET(self):
            path = self.path.split("?", 1)[0].rstrip("/")
            if path == "/api/v1/health":
                ok, why = manager.ready()
                self.send(HTTPStatus.OK if ok else HTTPStatus.SERVICE_UNAVAILABLE,
                          {"status": "ok" if ok else "not ready", "reason": why, "busy": manager.active is not None})
            elif path == "/api/v1/status":
                self.send(HTTPStatus.OK, manager.status())
            elif path == "/api/v1/pose":
                pose = manager.pose_dict()
                self.send(HTTPStatus.OK if pose else HTTPStatus.SERVICE_UNAVAILABLE,
                          pose or {"message": "no robot pose (TF) yet"})
            elif path == "/api/v1/stations":
                p = manager.node.planner
                self.send(HTTPStatus.OK, {
                    "usable": {n: {"x": x, "y": y, "yaw": yaw} for n, (x, y, yaw) in p.stations.items()},
                    "no_docking_pose_yet": list(p.skipped)})
            elif path.startswith("/api/v1/moves/"):
                try:
                    move = manager.moves.get(int(path.rsplit("/", 1)[1]))
                except ValueError:
                    move = None
                if move is None:
                    self.send(HTTPStatus.NOT_FOUND, {"message": "unknown move id"})
                else:
                    self.send(HTTPStatus.OK, manager.public(move))
            else:
                self.send(HTTPStatus.NOT_FOUND, {"message": f"unknown endpoint {path}"})

        def do_POST(self):
            path = self.path.split("?", 1)[0].rstrip("/")
            try:
                payload = self.read_json()
            except ValueError as e:
                self.send(HTTPStatus.BAD_REQUEST, {"success": False, "message": str(e)})
                return
            if path == "/api/v1/stop":
                manager.request_stop()
                self.send(HTTPStatus.OK, {"success": True, "message": "stop sent"})
            elif path == "/api/v1/moves":
                code, body, move = manager.request_move(payload)
                if move is not None and payload.get("wait"):
                    # answer only when the move is over (keep the HTTP client's timeout long!)
                    move["done_event"].wait(float(payload.get("timeout_s", 900)))
                    body = manager.public(move)
                    code = (HTTPStatus.OK if move["success"] else
                            HTTPStatus.GATEWAY_TIMEOUT if move["success"] is None else
                            HTTPStatus.INTERNAL_SERVER_ERROR)
                self.send(code, body)
            else:
                self.send(HTTPStatus.NOT_FOUND, {"message": f"unknown endpoint {path}"})

        def do_OPTIONS(self):
            self.send(HTTPStatus.NO_CONTENT, None)

        def read_json(self):
            n = int(self.headers.get("Content-Length", "0") or 0)
            if n <= 0:
                return {}
            try:
                data = json.loads(self.rfile.read(n).decode("utf-8"))
            except json.JSONDecodeError as e:
                raise ValueError(f"invalid JSON: {e}") from e
            if not isinstance(data, dict):
                raise ValueError("JSON body must be an object")
            return data

        def send(self, code, body):
            data = b"" if body is None else json.dumps(body).encode("utf-8")
            self.send_response(int(code))
            self.send_header("Access-Control-Allow-Origin", "*")
            self.send_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS")
            self.send_header("Access-Control-Allow-Headers", "Content-Type")
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(data)))
            self.end_headers()
            if data:
                self.wfile.write(data)

        def log_message(self, fmt, *args):
            pass                                   # no line per HTTP request in the terminal

    return Handler


def main():
    # handle Ctrl+C ourselves, so ROS is still running when we send the stop (same as path_sender)
    try:
        from rclpy.signals import SignalHandlerOptions
        rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    except (ImportError, TypeError):
        rclpy.init()

    node = PathSender()
    node.state, node.done = "idle", True           # PathSender would otherwise drive to its default goal at once
    port = int(node.declare_parameter("port", 8001).value)
    retries = int(node.declare_parameter("retries", 1).value)
    manager = MoveManager(node, retries)
    node.create_timer(0.1, manager.manage)

    server = ThreadingHTTPServer(("0.0.0.0", port), make_handler(manager))
    server.daemon_threads = True
    threading.Thread(target=server.serve_forever, daemon=True).start()
    log = node.get_logger()
    log.info(f"REST API on http://0.0.0.0:{port}/api/v1   robot {node.robot}")
    log.info(f"stations: {', '.join(node.planner.stations)}"
             + (f"   (no pose yet: {', '.join(node.planner.skipped)})" if node.planner.skipped else ""))

    interrupted = False
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        interrupted = True
    finally:
        if interrupted:
            try:
                manager.stop_robot()
                rclpy.spin_once(node, timeout_sec=0.2)  # let the stop message go out
                log.warn("Ctrl+C: robot stopped")
            except Exception as e:
                print("could not send the stop:", e, "-> stop the robot from the up_stack terminal")
        server.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()