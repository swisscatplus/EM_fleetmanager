"""
ROS 2 node: plan a path from the robot's CURRENT position to a station,
send it to the tracker (MPC), and let you follow in RViz how well the robot tracks it.

Run (inside the fleet_manager container, with the tracker running):
    python3 path_sender.py --ros-args -p goal:="LC MS" -p robot:=robot1

What it does:
    1. reads the robot pose from TF  map -> robot1/base_link
    2. planner.plan_from_pose(x, y, yaw, goal)
    3. publishes the path as Path2D on /robot1/path            (for the tracker)
    4. publishes the same path on /robot1/planned_path         (for RViz, nav_msgs/Path)
    5. keeps running and records where the robot really goes:
         /robot1/driven_path  (for RViz, nav_msgs/Path)
       + prints the distance between the robot and the planned path
    Ctrl+C: prints a summary (max / mean error, final error at the station).
    Note: Ctrl+C here does NOT stop the robot; the tracker keeps driving.
          Emergency stop = Ctrl+C in the up_stack.sh terminal.
"""

import math

import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile
from rclpy.time import Time
from tf2_ros import Buffer, TransformListener

from fleet_interfaces.msg import Path2D, Pose2D
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Path

from path_planner import Planner


def yaw_from_quaternion(q):
    return math.atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))


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

        # TF: where is the robot
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # publishers
        self.path_pub = self.create_publisher(Path2D, f"/{self.robot}/path", 1)              # tracker
        latched = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)            # RViz gets it even if opened later
        self.planned_pub = self.create_publisher(Path, f"/{self.robot}/planned_path", latched)
        self.driven_pub = self.create_publisher(Path, f"/{self.robot}/driven_path", latched)

        # state
        self.sent = False
        self.done = False            # True if nothing was sent (no path / wrong heading): stop the node
        self.points = []             # planned points
        self.driven = Path()
        self.driven.header.frame_id = "map"
        self.errors = []             # distance robot <-> planned path, one value per tick
        self.last_log = 0.0

        self.timer = self.create_timer(0.2, self.tick)                                         # 5 times per second

    # ------------------------------------------------------------------ helpers
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

    # ------------------------------------------------------------------ main loop
    def tick(self):
        pose = self.robot_pose()
        if pose is None:
            self.get_logger().info(f"waiting for TF map -> {self.robot}/base_link ...", throttle_duration_sec=2.0)
            return
        if not self.sent:
            self.try_send(pose)
        else:
            self.follow(pose)

    def try_send(self, pose):
        x, y, yaw = pose
        if self.path_pub.get_subscription_count() == 0:
            self.get_logger().info(f"waiting for the tracker on /{self.robot}/path ...", throttle_duration_sec=2.0)
            return

        result = self.planner.plan_from_pose(x, y, yaw, self.goal)
        for w in result["warnings"]:
            self.get_logger().warn(w)
        if "points" not in result:
            self.get_logger().error("no path, nothing sent")
            self.done = True
            return
        if not result["ok"]:
            self.get_logger().error("arrival heading would be wrong, nothing sent (needs a 180 deg turn first)")
            self.done = True
            return

        # 1. path for the tracker (Path2D)
        flag = Pose2D.FORWARD if result["direction"] == "forward" else Pose2D.BACKWARD
        msg = Path2D()
        msg.header.frame_id = "map"
        msg.header.stamp = self.get_clock().now().to_msg()
        for px, py in result["points"]:
            p = Pose2D()
            p.header = msg.header
            p.x, p.y = float(px), float(py)
            p.direction_flag = flag
            msg.poses.append(p)
        self.path_pub.publish(msg)

        # 2. same path for RViz (nav_msgs/Path)
        self.points = result["points"]
        self.planned_pub.publish(self.to_nav_path(self.points))

        self.sent = True
        self.get_logger().info(
            f"sent {len(msg.poses)} points: ({x:.2f}, {y:.2f}) -> {self.goal}, {result['direction']}, "
            f"route {' -> '.join(result['route'])}")
        self.get_logger().info("following the robot... (Ctrl+C for the summary)")

    def follow(self, pose):
        x, y, _ = pose

        # trail of where the robot really went (add a point every 2 cm)
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

        # how far from the planned path / from the goal
        err = distance_to_path((x, y), self.points)
        self.errors.append(err)
        to_goal = math.dist((x, y), self.points[-1])
        now = self.get_clock().now().nanoseconds * 1e-9
        if now - self.last_log > 1.0:                                                         # print once per second
            self.get_logger().info(f"off path: {err * 100:5.1f} cm   |   to goal: {to_goal:.2f} m")
            self.last_log = now

    def summary(self):
        if not self.errors:
            return
        pose = self.robot_pose()
        gx, gy, gyaw = self.planner.stations[self.goal]
        print("\n========== summary ==========")
        print(f"off path: max {max(self.errors) * 100:.1f} cm, mean {sum(self.errors) / len(self.errors) * 100:.1f} cm")
        if pose:
            x, y, yaw = pose
            dyaw = abs((yaw - gyaw + math.pi) % (2 * math.pi) - math.pi)
            print(f"final position error vs {self.goal}: {math.dist((x, y), (gx, gy)) * 100:.1f} cm "
                  f"(dx {(x - gx) * 100:+.1f} cm, dy {(y - gy) * 100:+.1f} cm), "
                  f"heading error {math.degrees(dyaw):.1f} deg")
        print("=============================")


def main():
    rclpy.init()
    node = PathSender()
    try:
        while rclpy.ok() and not node.done:
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        pass
    finally:
        node.summary()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()