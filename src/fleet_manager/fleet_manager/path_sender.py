"""
ROS 2 node: drive the robot from its CURRENT position to a station, step by step,
and let you follow in RViz how well it tracks the path.

Run (inside the fleet_manager container, with the tracker running):
    python3 path_sender.py --ros-args -p goal:="LC MS" -p robot:=robot1

How it works (a loop):
    1. read the robot pose from TF  map -> robot1/base_link
    2. ask the planner for a plan:  planner.plan_from_pose(x, y, yaw, goal)
       a plan is a list of STEPS, e.g.
            drive forward   robot -> top_right_t
            turn in place   to -90 deg (at top_right_t)
            drive backward  top_right_t -> Battery
    3. do ONLY THE FIRST STEP:
         turn  -> this node publishes rotation commands on /robot1/cmd_vel
         drive -> the leg is sent to the tracker (MPC) on /robot1/path
    4. when the step is finished, go back to 1 (plan again from where the robot really is).
       Planning again after each step corrects small errors (robot stopped a few cm off).
    The LAST leg (into the station) is followed until the robot has arrived.

RViz:  /robot1/planned_path (whole plan)   /robot1/driven_path (where the robot really went)
Ctrl+C: stops the robot (stops a turn, clears the tracker path) and prints a summary.

Needs the tracker change (tracker_mpc.py sends ONE stop when idle, not 8 per second),
otherwise the tracker's zeros on cmd_vel fight the turns.
"""

import math

import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile
from rclpy.time import Time
from tf2_ros import Buffer, TransformListener

from fleet_interfaces.msg import Path2D, Pose2D
from geometry_msgs.msg import PoseStamped, Twist
from nav_msgs.msg import Path

from path_planner import Planner, describe

# turn in place
TURN_TOL = 0.05     # rad (~3 deg): the turn is finished when the yaw error is below this
TURN_GAIN = 1.5     # angular speed = TURN_GAIN * yaw error ...
MAX_W = 0.5         # ... limited to this (rad/s) ...
MIN_W = 0.15        # ... and never slower than this, otherwise the robot stops before the end
TURN_TIMEOUT = 30.0  # s

# end of a leg (not the last one)
LEG_DONE = 0.06     # m: close enough to the end of the leg
LEG_NEAR = 0.15     # m: ... or this close AND stopped (the tracker sometimes stops a few cm off)
STILL_TIME = 1.5    # s without moving = stopped
SETTLE_TIME = 0.5   # s to wait after a step, before planning again (TF catches up)

# arrival at the station (last leg)
ARRIVED = 0.10      # m from the docking point, and stopped
MAX_PLANS = 10      # safety: never plan more than this for one trip


def yaw_from_quaternion(q):
    return math.atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))


def wrap(a):
    """angle brought back between -pi and pi"""
    return math.atan2(math.sin(a), math.cos(a))


def distance_to_path(p, points):
    """shortest distance from point p to the polyline 'points' (metres)"""
    best = math.inf
    for a, b in zip(points[:-1], points[1:]):
        dx, dy = b[0] - a[0], b[1] - a[1]
        L2 = dx * dx + dy * dy
        t = 0.0 if L2 == 0 else max(0.0, min(1.0, ((p[0] - a[0]) * dx + (p[1] - a[1]) * dy) / L2))
        best = min(best, math.dist(p, (a[0] + t * dx, a[1] + t * dy)))
    return best


class PathSender(Node):
    def __init__(self):
        super().__init__("path_sender")

        # parameters (-p name:=value)
        self.goal = self.declare_parameter("goal", "LC MS").value
        self.robot = self.declare_parameter("robot", "robot1").value
        graph_file = self.declare_parameter(
            "graph_file", "/ros2_ws/src/tracker/config/map_pois.yaml").value
        stations_file = self.declare_parameter(
            "stations_file", "/ros2_ws/src/fleet_manager/config/stations.yaml").value

        self.planner = Planner(graph_file, stations_file)
        if self.goal not in self.planner.stations:
            raise SystemExit(f"unknown station '{self.goal}', known: {', '.join(self.planner.stations)}")

        # TF: where is the robot
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # publishers
        self.path_pub = self.create_publisher(Path2D, f"/{self.robot}/path", 1)              # tracker
        self.cmd_pub = self.create_publisher(Twist, f"/{self.robot}/cmd_vel", 10)            # turns
        latched = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)            # RViz gets it even if opened later
        self.planned_pub = self.create_publisher(Path, f"/{self.robot}/planned_path", latched)
        self.driven_pub = self.create_publisher(Path, f"/{self.robot}/driven_path", latched)

        # state machine:  plan -> turn / leg / final -> settle -> plan ...
        self.state = "plan"
        self.done = False
        self.n_plans = 0
        self.step = None             # the step being done
        self.step_start = 0.0        # time the step started
        self.settle_until = 0.0

        # stillness (to know when the robot has stopped)
        self.still_pose = None
        self.still_since = 0.0

        # recording
        self.final_points = []       # points of the last leg (to measure tracking error)
        self.driven = Path()
        self.driven.header.frame_id = "map"
        self.errors = []
        self.last_log = 0.0

        self.timer = self.create_timer(0.1, self.tick)                                         # 10 times per second

    # ------------------------------------------------------------------ helpers
    def now(self):
        return self.get_clock().now().nanoseconds * 1e-9

    def robot_pose(self):
        """(x, y, yaw) of the robot in the map, or None if TF is not available yet"""
        try:
            tf = self.tf_buffer.lookup_transform("map", f"{self.robot}/base_link", Time())
        except Exception:
            return None
        t = tf.transform
        return t.translation.x, t.translation.y, yaw_from_quaternion(t.rotation)

    def to_nav_path(self, points):
        msg = Path()
        msg.header.frame_id = "map"
        msg.header.stamp = self.get_clock().now().to_msg()
        for x, y in points:
            p = PoseStamped()
            p.header = msg.header
            p.pose.position.x, p.pose.position.y = float(x), float(y)
            p.pose.orientation.w = 1.0
            msg.poses.append(p)
        return msg

    def send_leg(self, points, direction):
        """send one drive leg to the tracker"""
        flag = Pose2D.FORWARD if direction == "forward" else Pose2D.BACKWARD
        msg = Path2D()
        msg.header.frame_id = "map"
        msg.header.stamp = self.get_clock().now().to_msg()
        for px, py in points:
            p = Pose2D()
            p.header = msg.header
            p.x, p.y = float(px), float(py)
            p.direction_flag = flag
            msg.poses.append(p)
        self.path_pub.publish(msg)

    def clear_tracker(self):
        """empty path: the tracker stops and forgets the current leg"""
        msg = Path2D()
        msg.header.frame_id = "map"
        msg.header.stamp = self.get_clock().now().to_msg()
        self.path_pub.publish(msg)

    def stop_robot(self):
        self.cmd_pub.publish(Twist())

    def update_still(self, pose):
        """True if the robot has not moved more than 1 cm / 2 deg for STILL_TIME seconds"""
        now = self.now()
        if (self.still_pose is None or math.dist(pose[:2], self.still_pose[:2]) > 0.01
                or abs(wrap(pose[2] - self.still_pose[2])) > 0.035):
            self.still_pose, self.still_since = pose, now
        return now - self.still_since > STILL_TIME

    def record(self, pose):
        """trail of where the robot really went (a point every 2 cm)"""
        x, y, _ = pose
        last = self.driven.poses[-1].pose.position if self.driven.poses else None
        if last is None or math.dist((last.x, last.y), (x, y)) > 0.02:
            p = PoseStamped()
            p.header.frame_id = "map"
            p.header.stamp = self.get_clock().now().to_msg()
            p.pose.position.x, p.pose.position.y = x, y
            p.pose.orientation.w = 1.0
            self.driven.poses.append(p)
            self.driven.header.stamp = p.header.stamp
            self.driven_pub.publish(self.driven)

    # ------------------------------------------------------------------ main loop
    def tick(self):
        pose = self.robot_pose()
        if pose is None:
            self.get_logger().info(f"waiting for TF map -> {self.robot}/base_link ...", throttle_duration_sec=2.0)
            return
        self.record(pose)
        still = self.update_still(pose)

        if self.state == "plan":
            self.plan_and_start(pose)
        elif self.state == "turn":
            self.do_turn(pose)
        elif self.state == "leg":
            self.do_leg(pose, still)
        elif self.state == "final":
            self.do_final(pose, still)
        elif self.state == "settle" and self.now() > self.settle_until:
            self.state = "plan"

    # ------------------------------------------------------------------ 1-3: plan, start the first step
    def plan_and_start(self, pose):
        if self.path_pub.get_subscription_count() == 0:
            self.get_logger().info(f"waiting for the tracker on /{self.robot}/path ...", throttle_duration_sec=2.0)
            return
        self.n_plans += 1
        if self.n_plans > MAX_PLANS:
            self.get_logger().error(f"planned {MAX_PLANS} times without arriving: giving up")
            self.done = True
            return

        x, y, yaw = pose
        result = self.planner.plan_from_pose(x, y, yaw, self.goal)
        for w in result["warnings"]:
            self.get_logger().warn(w)
        if not result["ok"]:
            self.get_logger().error("no plan, nothing sent (see the warning above)")
            self.done = True
            return
        if not result["steps"]:
            self.get_logger().info(f"already at {self.goal}")
            self.done = True
            return

        self.get_logger().info(f"plan #{self.n_plans} from ({x:.2f}, {y:.2f}, {math.degrees(yaw):.0f} deg) "
                               f"to {self.goal}:")
        for line in describe(result):
            self.get_logger().info("    " + line)
        self.planned_pub.publish(self.to_nav_path(result["points"]))

        self.step = result["steps"][0]
        self.step_start = self.now()
        if self.step["type"] == "turn":
            self.state = "turn"
        elif self.step["last"]:
            self.final_points = self.step["points"]
            self.send_leg(self.step["points"], self.step["direction"])
            self.state = "final"
            self.get_logger().info("last leg sent, following the robot... (Ctrl+C stops it)")
        else:
            self.send_leg(self.step["points"], self.step["direction"])
            self.state = "leg"

    # ------------------------------------------------------------------ turn in place
    def do_turn(self, pose):
        err = wrap(self.step["yaw"] - pose[2])
        if abs(err) < TURN_TOL:
            self.stop_robot()
            self.get_logger().info(f"turn done ({math.degrees(pose[2]):.0f} deg)")
            self.next_step()
            return
        if self.now() - self.step_start > TURN_TIMEOUT:
            self.stop_robot()
            self.get_logger().error("turn takes too long: stopped (check the localization / the tracker)")
            self.done = True
            return
        w = max(MIN_W, min(MAX_W, TURN_GAIN * abs(err)))
        cmd = Twist()
        cmd.angular.z = math.copysign(w, err)          # shortest way round
        self.cmd_pub.publish(cmd)
        self.get_logger().info(f"turning: {math.degrees(err):5.1f} deg to go", throttle_duration_sec=1.0)

    # ------------------------------------------------------------------ a leg that is not the last one
    def do_leg(self, pose, still):
        end = self.step["points"][-1]
        d = math.dist(pose[:2], end)
        self.get_logger().info(f"leg {self.step['direction']}: {d:.2f} m to the end of the leg",
                               throttle_duration_sec=1.0)
        if d < LEG_DONE or (d < LEG_NEAR and still):
            self.clear_tracker()
            self.get_logger().info(f"leg done ({d * 100:.0f} cm from its end)")
            self.next_step()
            return
        length = sum(math.dist(p, q) for p, q in zip(self.step["points"][:-1], self.step["points"][1:]))
        if self.now() - self.step_start > 30.0 + 3.0 * length / 0.15:
            self.clear_tracker()
            self.get_logger().error("leg takes too long: stopped (robot stuck or tracker not following)")
            self.done = True

    def next_step(self):
        self.state = "settle"
        self.settle_until = self.now() + SETTLE_TIME

    # ------------------------------------------------------------------ last leg: into the station
    def do_final(self, pose, still):
        x, y, _ = pose
        err = distance_to_path((x, y), self.final_points)
        self.errors.append(err)
        gx, gy, _ = self.planner.stations[self.goal]
        to_goal = math.dist((x, y), (gx, gy))
        now = self.now()
        if now - self.last_log > 1.0:                                                         # print once per second
            self.get_logger().info(f"off path: {err * 100:5.1f} cm   |   to goal: {to_goal:.2f} m")
            self.last_log = now
        if to_goal < ARRIVED and still:
            self.get_logger().info(f"arrived at {self.goal}")
            self.done = True

    # ------------------------------------------------------------------ end
    def stop_everything(self):
        """Ctrl+C or error: the robot must not keep moving"""
        if self.state == "turn":
            self.stop_robot()
        elif self.state in ("leg", "final"):
            self.clear_tracker()

    def summary(self):
        if not self.errors:
            return
        pose = self.robot_pose()
        gx, gy, gyaw = self.planner.stations[self.goal]
        print("\n========== summary (last leg) ==========")
        print(f"plans made: {self.n_plans}")
        print(f"off path: max {max(self.errors) * 100:.1f} cm, mean {sum(self.errors) / len(self.errors) * 100:.1f} cm")
        if pose:
            x, y, yaw = pose
            dyaw = abs(wrap(yaw - gyaw))
            print(f"final position error vs {self.goal}: {math.dist((x, y), (gx, gy)) * 100:.1f} cm "
                  f"(dx {(x - gx) * 100:+.1f} cm, dy {(y - gy) * 100:+.1f} cm), "
                  f"heading error {math.degrees(dyaw):.1f} deg")
        print("========================================")


def main():
    # handle Ctrl+C ourselves, so ROS is still running when we send the stop
    try:
        from rclpy.signals import SignalHandlerOptions
        rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    except (ImportError, TypeError):
        rclpy.init()
    node = PathSender()
    interrupted = False
    try:
        while rclpy.ok() and not node.done:
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        interrupted = True
    finally:
        if interrupted:
            try:
                node.stop_everything()
                rclpy.spin_once(node, timeout_sec=0.2)  # let the stop message go out
                node.get_logger().warn("Ctrl+C: robot stopped")
            except Exception as e:                      # ROS already shut down
                print("could not send the stop:", e, "-> stop the robot from the up_stack terminal")
        node.summary()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()