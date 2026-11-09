"""
ekf_test.py  -  measure how good the robot's odometry (EKF) is. Changes nothing on the robot.

Put it next to path_sender.py (/ros2_ws/src/fleet_manager/fleet_manager in the fleet_manager
container) and run ONE of the two tests:

  TEST 1 - standing still (robot not touched, motors not commanded):
      python3 ekf_test.py --ros-args -p mode:=still -p duration:=120.0

  TEST 2 - while driving (start it, then drive trips with path_sender or demo_loop in another
           terminal; press Ctrl+C here when done):
      python3 ekf_test.py --ros-args -p mode:=drive

What each test measures
-----------------------
TEST 1  The correct answer is "nothing moves". So everything that changes is sensor error:
        - heading drift of the EKF       (TF  robot1/odom -> robot1/base_link)
        - gyro bias = mean turning rate the IMU reports while still   (/robot1/bno055/imu)
        - what the wheels report while still (should be exactly 0)    (/robot1/odomWheel)
        If "heading drift" ~= "gyro bias x time", the drift comes from the gyro.

TEST 2  Each time the camera ACCEPTS a marker, it publishes where the robot really is
        (/robot1/localization/vision_base_pose, raw measurement). Between two such measurements
        we compare:
            how the robot moved according to the CAMERA      (the truth, +- a few cm)
            how it moved according to the EKF (odom frame)   (what we test)
        Both motions are expressed in the robot's own frame at the start of the segment
        (forward / sideways / turn), so they can be compared directly.
        This tests ONLY the odometry: the camera smoothing and gating play no role.

Ctrl+C: stops and prints the summary. Results are also saved in a .csv file.
"""

import csv
import math
import statistics
import time

import rclpy
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from rclpy.time import Time
from sensor_msgs.msg import Imu
from tf2_ros import Buffer, TransformListener

MIN_SEGMENT = 0.30   # m: compare camera vs EKF only once the robot moved at least this much (camera noise ~ cm)


# ---------------------------------------------------------------- small 2D helpers
def wrap(a):
    """angle brought back between -pi and pi"""
    return math.atan2(math.sin(a), math.cos(a))


def yaw_of(q):
    """yaw (rad) from a quaternion"""
    return math.atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))


def relative_motion(p1, p2):
    """
    how the robot moved from pose p1 to pose p2, seen FROM THE ROBOT at p1:
        forward (m), sideways (m, + = to the left), turn (rad, + = to the left)
    p1, p2 = (x, y, yaw) in the same fixed frame
    """
    dx, dy = p2[0] - p1[0], p2[1] - p1[1]
    c, s = math.cos(p1[2]), math.sin(p1[2])
    return c * dx + s * dy, -s * dx + c * dy, wrap(p2[2] - p1[2])


class EkfTest(Node):
    def __init__(self):
        super().__init__("ekf_test")
        self.mode = self.declare_parameter("mode", "still").value              # still | drive
        self.duration = float(self.declare_parameter("duration", 120.0).value)  # s, for mode still
        robot = self.declare_parameter("robot", "robot1").value
        self.odom_frame = f"{robot}/odom"
        self.base_frame = f"{robot}/base_link"

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # data recorded
        self.gyro_z = []          # IMU turning rate samples (rad/s)
        self.wheel_vx = []        # wheel forward speed samples (m/s)
        self.wheel_vth = []       # wheel turning rate samples (rad/s)
        self.start_pose = None    # EKF pose at the start (test 1)
        self.start_time = None
        self.last_print = 0.0
        self.segments = []        # test 2 results
        self.anchor = None        # test 2: (camera pose, EKF pose) at the start of the current segment
        self.cam_count = 0
        self.tf_misses = 0
        self.done = False

        self.create_subscription(Imu, f"/{robot}/bno055/imu", self.on_imu, qos_profile_sensor_data)
        self.create_subscription(Odometry, f"/{robot}/odomWheel", self.on_wheels, 10)
        if self.mode == "drive":
            self.create_subscription(PoseStamped, f"/{robot}/localization/vision_base_pose", self.on_camera, 10)
        self.create_timer(0.5, self.tick)
        self.get_logger().info(f"TEST mode={self.mode}  (Ctrl+C to stop and print the summary)")

    # ------------------------------------------------------------------ inputs
    def on_imu(self, msg):
        self.gyro_z.append(msg.angular_velocity.z)

    def on_wheels(self, msg):
        self.wheel_vx.append(msg.twist.twist.linear.x)
        self.wheel_vth.append(msg.twist.twist.angular.z)

    def ekf_pose(self, stamp=None):
        """EKF pose (x, y, yaw) in the odom frame, at time `stamp` (None = latest), or None"""
        try:
            tf = self.tf_buffer.lookup_transform(self.odom_frame, self.base_frame,
                                                 Time() if stamp is None else Time.from_msg(stamp))
        except Exception:
            return None
        t = tf.transform
        return t.translation.x, t.translation.y, yaw_of(t.rotation)

    # ------------------------------------------------------------------ TEST 1: still
    def tick(self):
        if self.mode != "still":
            return
        pose = self.ekf_pose()
        if pose is None:
            self.get_logger().info(f"waiting for TF {self.odom_frame} -> {self.base_frame} ...",
                                   throttle_duration_sec=2.0)
            return
        now = time.monotonic()
        if self.start_pose is None:
            self.start_pose, self.start_time = pose, now
            self.gyro_z.clear(); self.wheel_vx.clear(); self.wheel_vth.clear()   # count from now
            self.get_logger().info(f"recording for {self.duration:.0f} s - do NOT touch the robot")
            return
        t = now - self.start_time
        if now - self.last_print > 10.0:
            self.last_print = now
            dyaw = math.degrees(wrap(pose[2] - self.start_pose[2]))
            dpos = math.dist(pose[:2], self.start_pose[:2]) * 100
            self.get_logger().info(f"t={t:5.0f} s   heading drift {dyaw:+6.2f} deg   position drift {dpos:5.1f} cm")
        if t >= self.duration:
            self.end_pose, self.end_time = pose, now
            self.done = True

    def summary_still(self):
        if self.start_pose is None:
            print("no data (TF never arrived)")
            return
        end = getattr(self, "end_pose", None) or self.ekf_pose() or self.start_pose
        t = (getattr(self, "end_time", None) or time.monotonic()) - self.start_time
        dyaw = math.degrees(wrap(end[2] - self.start_pose[2]))
        dpos = math.dist(end[:2], self.start_pose[:2]) * 100
        print("\n================ TEST 1: standing still ================")
        print(f"duration                 : {t:.0f} s")
        print(f"EKF heading drift        : {dyaw:+.2f} deg   ->  {dyaw / t * 60:+.2f} deg/min")
        print(f"EKF position drift       : {dpos:.1f} cm")
        if self.gyro_z:
            bias = statistics.mean(self.gyro_z)
            noise = statistics.pstdev(self.gyro_z)
            print(f"gyro bias (mean z)       : {bias:+.5f} rad/s  ->  {math.degrees(bias) * 60:+.2f} deg/min "
                  f"(noise {noise:.4f} rad/s, {len(self.gyro_z)} samples)")
            print(f"  -> drift expected from the gyro alone: {math.degrees(bias) * t:+.2f} deg")
        else:
            print("gyro                     : NO IMU messages received - check the topic name")
        if self.wheel_vx:
            print(f"wheels while still       : max |vx| {max(map(abs, self.wheel_vx)):.4f} m/s, "
                  f"max |vth| {max(map(abs, self.wheel_vth)):.4f} rad/s  (should be 0)")
        else:
            print("wheels                   : NO odomWheel messages received - check the topic name")
        print("========================================================")
        print("How to read it:  heading drift < ~1 deg/min = fine.")
        print("                 heading drift ~= 'expected from the gyro' -> the drift is the gyro bias.")

    # ------------------------------------------------------------------ TEST 2: drive
    def on_camera(self, msg):
        cam = (msg.pose.position.x, msg.pose.position.y, yaw_of(msg.pose.orientation))
        ekf = self.ekf_pose(msg.header.stamp)           # EKF pose at the moment the picture was taken
        if ekf is None:
            ekf = self.ekf_pose()                       # fallback: latest (small timing error)
            self.tf_misses += 1
        if ekf is None:
            return
        self.cam_count += 1
        if self.anchor is None:
            self.anchor = (cam, ekf)
            self.get_logger().info("first camera measurement received - drive now")
            return
        cam0, ekf0 = self.anchor
        if math.dist(cam[:2], cam0[:2]) < MIN_SEGMENT and abs(wrap(cam[2] - cam0[2])) < math.radians(20):
            return                                      # not moved enough yet: camera noise would dominate

        fc, sc, tc = relative_motion(cam0, cam)          # truth (camera)
        fo, so, to = relative_motion(ekf0, ekf)          # EKF
        seg = {"forward_cam": fc, "forward_ekf": fo, "side_cam": sc, "side_ekf": so,
               "turn_cam": math.degrees(tc), "turn_ekf": math.degrees(to),
               "pos_error_cm": math.dist((fc, sc), (fo, so)) * 100,
               "turn_error_deg": math.degrees(wrap(to - tc))}
        self.segments.append(seg)
        self.get_logger().info(
            f"segment {len(self.segments):2d}: camera {fc:+.2f} m fwd, {seg['turn_cam']:+6.1f} deg | "
            f"EKF {fo:+.2f} m fwd, {seg['turn_ekf']:+6.1f} deg | "
            f"error {seg['pos_error_cm']:4.1f} cm, {seg['turn_error_deg']:+5.1f} deg")
        self.anchor = (cam, ekf)

    def summary_drive(self):
        print("\n================ TEST 2: driving ================")
        print(f"camera measurements accepted: {self.cam_count}   segments compared: {len(self.segments)}"
              + (f"   (TF timing fallbacks: {self.tf_misses})" if self.tf_misses else ""))
        if not self.segments:
            print("no segment: the camera accepted fewer than 2 measurements while the robot moved "
                  f"> {MIN_SEGMENT} m (markers not visible? check /robot1/localization/vision_base_pose)")
            return
        segs = self.segments
        print(f"position error per segment : mean {statistics.mean(s['pos_error_cm'] for s in segs):.1f} cm, "
              f"max {max(s['pos_error_cm'] for s in segs):.1f} cm")
        print(f"turn error per segment     : mean {statistics.mean(abs(s['turn_error_deg']) for s in segs):.1f} deg, "
              f"max {max(abs(s['turn_error_deg']) for s in segs):.1f} deg")

        # distance scale: total forward distance, camera vs EKF (straight-ish segments only)
        straight = [s for s in segs if abs(s["turn_cam"]) < 10 and abs(s["forward_cam"]) > MIN_SEGMENT]
        if straight:
            dc = sum(abs(s["forward_cam"]) for s in straight)
            de = sum(abs(s["forward_ekf"]) for s in straight)
            print(f"distance on straight parts : camera {dc:.2f} m, EKF {de:.2f} m  ->  EKF/camera = {de / dc:.3f}")
            side = statistics.mean(s["side_ekf"] - s["side_cam"] for s in straight) * 100
            print(f"sideways drift on straights: {side:+.1f} cm per segment (+ = EKF thinks it went more LEFT)")
        # turn scale: total turning, camera vs EKF (segments with a real turn)
        turning = [s for s in segs if abs(s["turn_cam"]) >= 30]
        if turning:
            tcam = sum(abs(s["turn_cam"]) for s in turning)
            tekf = sum(abs(s["turn_ekf"]) for s in turning)
            print(f"turning (segments >= 30deg): camera {tcam:.0f} deg, EKF {tekf:.0f} deg  ->  EKF/camera = {tekf / tcam:.3f}")
        print("=================================================")
        print("How to read it:")
        print("  position error a few cm per segment          -> odometry fine, problems come from the camera side")
        print("  EKF/camera distance far from 1.00 (> 3 %)    -> wheel scale (right/left_wheel_odom_scale)")
        print("  steady sideways drift on straights           -> the two wheels are not equal (one scale)")
        print("  EKF/camera turning far from 1.00, big turn errors -> gyro / turning")

        name = f"ekf_test_drive_{time.strftime('%Y%m%d_%H%M%S')}.csv"
        with open(name, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(segs[0]))
            w.writeheader()
            w.writerows(segs)
        print(f"segments saved in {name}")


def main():
    try:
        from rclpy.signals import SignalHandlerOptions
        rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    except (ImportError, TypeError):
        rclpy.init()
    node = EkfTest()
    try:
        while rclpy.ok() and not node.done:
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        pass
    finally:
        node.summary_still() if node.mode == "still" else node.summary_drive()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()