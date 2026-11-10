"""
demo_loop.py  -  loop the robot between stations, WITHOUT the REST API.

Reuses PathSender (path_sender.py) as it is: one trip = one run of its state machine.
After each trip the state is reset and the next station becomes the goal.

Run (inside the fleet_manager container, tracker running), from this folder:

    python3 demo_loop.py --ros-args -p robot:=robot1 -p stations:="OmniFire,LC MS"

Optional parameters (-p name:=value):
    stations      comma separated list, visited in order, forever      (default "OmniFire,LC MS")
    pause         seconds waited at each station (arm takes the plate) (default 5.0)
    laps          number of laps, 0 = until Ctrl+C                     (default 0)
    max_failures  stop after this many failed trips in a row           (default 2)

Ctrl+C: stops the robot and ends the loop.
"""

import math
import time

import rclpy
from nav_msgs.msg import Path

from path_sender import PathSender

AT_STATION_DIST = 0.15   # m: robot this close to the docking point = trip OK


def reset_trip(node, goal):
    """put PathSender back in its initial state, with a new goal"""
    node.goal = goal
    node.state = "plan"
    node.done = False
    node.n_plans = 0
    node.steps = []
    node.step = None
    node.final_turn = False
    node.tail = []
    node.still_pose = None
    node.final_points = []
    node.errors = []
    node.driven = Path()
    node.driven.header.frame_id = "map"


def arrived(node, goal):
    """PathSender sets done=True on arrival AND on errors: check where the robot really is"""
    pose = node.robot_pose()
    if pose is None:
        return False
    gx, gy, _ = node.planner.stations[goal]
    return math.dist(pose[:2], (gx, gy)) < AT_STATION_DIST


def spin_for(node, seconds):
    end = time.monotonic() + seconds
    while rclpy.ok() and time.monotonic() < end:
        rclpy.spin_once(node, timeout_sec=0.1)


def main():
    try:
        from rclpy.signals import SignalHandlerOptions
        rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    except (ImportError, TypeError):
        rclpy.init()
    node = PathSender()
    log = node.get_logger()

    names = node.declare_parameter("stations", "OmniFire,LC MS").value
    pause = float(node.declare_parameter("pause", 5.0).value)
    laps = int(node.declare_parameter("laps", 0).value)
    max_failures = int(node.declare_parameter("max_failures", 2).value)

    stations = [s.strip() for s in names.split(",") if s.strip()]
    unknown = [s for s in stations if s not in node.planner.stations]
    if len(stations) < 2 or unknown:
        log.error(f"need 2+ known stations, got {stations}; unknown: {unknown}; "
                  f"known: {', '.join(node.planner.stations)}")
        node.destroy_node()
        rclpy.shutdown()
        return

    ok = failed = in_a_row = 0
    i = 0
    t0 = time.monotonic()
    try:
        while rclpy.ok() and (not laps or i < laps * len(stations)):
            goal = stations[i % len(stations)]
            log.info(f"=== trip {i + 1} -> {goal} ===")
            reset_trip(node, goal)
            while rclpy.ok() and not node.done:
                rclpy.spin_once(node, timeout_sec=0.1)
            spin_for(node, 0.5)                                  # TF catches up before we check
            if arrived(node, goal):
                ok, in_a_row = ok + 1, 0
                i += 1
                log.info(f"at {goal}, waiting {pause:.0f} s")
                spin_for(node, pause)
            else:
                failed, in_a_row = failed + 1, in_a_row + 1
                if in_a_row >= max_failures:
                    log.error("too many failures in a row: loop stopped. Check the robot, then run again.")
                    break
                log.warn("trip failed, trying the same station again in 5 s")
                spin_for(node, 5.0)
    except KeyboardInterrupt:
        try:
            node.stop_everything()
            rclpy.spin_once(node, timeout_sec=0.2)               # let the stop message go out
            log.warn("Ctrl+C: robot stopped")
        except Exception as e:
            print("could not send the stop:", e, "-> stop the robot from the up_stack terminal")
    print(f"\n{ok} trips OK, {failed} failed, {(time.monotonic() - t0) / 60:.1f} min")
    node.destroy_node()
    if rclpy.ok():
        rclpy.shutdown()


if __name__ == "__main__":
    main()
