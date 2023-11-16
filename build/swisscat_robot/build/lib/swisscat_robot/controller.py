import rclpy
from rclpy.node import Node
import math
from geometry_msgs.msg import Twist, PoseWithCovariance
from nav_msgs.msg import Odometry
from tf2_ros import Buffer, TransformListener
from tf_transformations import euler_from_quaternion
import numpy as np
from rclpy.qos import QoSProfile
import time
from geometry_msgs.msg import PoseStamped

VERBOSE = True # time log of main loop
DIST_THRESH = 0.3

class DiffDriveRobot(Node):

    def __init__(self, robot_name='edymobile', init_pos=[-3.18, -3.595], init_heading=0.0, init_vel_cmd=[0.0, 0.0],
                 velocity=0.1):
        super().__init__('controller')
        self.robot_name = robot_name

        # Pose
        self.pose_x = init_pos[0]
        self.pose_y = init_pos[1]
        self.theta = init_heading

        # Velocity command
        self.cmd_vel = Twist()
        self.cmd_vel.linear.x = init_vel_cmd[0]
        self.cmd_vel.angular.z = init_vel_cmd[1]
        self.vel_desired = velocity
        self.vel_direction = 1

        # Position goal
        self.goal = PoseStamped()
        self.target_x = None
        self.target_y = None
        self.goal_reached = False
        self.dist_to_goal = None

        # Control gains
        self.Ka = 0.1
        self.Kv = 0.2
        self.ki = 0.00008
        self.kd = 0.001
        self.tot_error = 0.0

        qos_profile = QoSProfile(depth=10)

        # Subscribers
        self.odom_sub = self.create_subscription(Odometry, 'odom', self.poseCallBack, qos_profile)
        self.goal_sub = self.create_subscription(PoseStamped, 'navigate_to_pose/goal', self.goalCallBack, qos_profile)

        # Publishers
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', qos_profile)

        # TF2 Buffer and Listener
        self.tfBuffer = Buffer()
        self.tfListener = TransformListener(self.tfBuffer, self)

        timer_frequency = 1.0
        self.timer = self.create_timer(1.0 / timer_frequency, self.main_loop)

######################################### set target and set_cmd_vel useless atm #########################################
    def set_target(self, target_x, target_y):
        self.target_x = target_x
        self.target_y = target_y
        self.goal_reached = False

    def set_cmd_vel(self, v, w):
        self.cmd_vel.linear.x = float(v)
        self.cmd_vel.angular.z = float(w)
##########################################################################################################################

    def compute_vel(self):
        self.dist_to_goal = math.sqrt((self.target_x - self.pose_x) ** 2 + (self.target_y - self.pose_y) ** 2)

        self.get_logger().debug(self.robot_name + ': Current pose x: ' + str(self.pose_x))
        self.get_logger().debug(self.robot_name + ': New x target: ' + str(self.target_x))
        self.get_logger().debug(self.robot_name + ': Current pose y: ' + str(self.pose_y))
        self.get_logger().debug(self.robot_name + ': New y target: ' + str(self.target_y))

        if abs(self.target_x - self.pose_x) > DIST_THRESH or abs(self.target_y - self.pose_y) > DIST_THRESH or min(
                abs(self.target_y - self.pose_y), abs(self.target_x - self.pose_x)) > 0.1:
            heading = math.atan2(self.target_y - self.pose_y, self.target_x - self.pose_x)
            alpha = heading - self.theta

            self.get_logger().debug(self.robot_name + ': heading to goal ' + str(heading))
            self.get_logger().debug(self.robot_name + ': theta robot in map ' + str(self.theta))

            if abs(alpha) > math.pi:
                alpha -= 2 * math.pi
            elif alpha < -math.pi:
                alpha += 2 * math.pi

            self.tot_error += alpha

            if abs(alpha) > 0.5 * math.pi:
                self.vel_direction = -1
            else:
                self.vel_direction = 1

            v_error = self.vel_desired * self.vel_direction - self.cmd_vel.linear.x
            change_dir = (abs(alpha) > 0.05 * math.pi and abs(alpha) < 0.8 * math.pi)

            self.get_logger().debug(self.robot_name + ': change dir ? ' + str(change_dir))

            self.cmd_vel.linear.x = (self.vel_desired * self.vel_direction + self.Kv * v_error) * (not change_dir)
            self.cmd_vel.angular.z = -self.Ka * (alpha + 4 * np.sign(alpha) * change_dir) * np.sign(self.vel_desired * self.vel_direction)

        else:
            self.get_logger().debug(self.robot_name + ': Goal reached')
            self.goal_reached = True
            self.cmd_vel.linear.x, self.cmd_vel.angular.z = 0.0, 0.0
            self.tot_error = 0

    def poseCallBack(self, odom_msg):
        '''
        Gets pose information from robot odometry topic
        '''
        self.pose_x = odom_msg.pose.pose.position.x
        self.pose_y = odom_msg.pose.pose.position.y
        (roll, pitch, self.theta) = euler_from_quaternion(
            [odom_msg.pose.pose.orientation.x, odom_msg.pose.pose.orientation.y, odom_msg.pose.pose.orientation.z,
             odom_msg.pose.pose.orientation.w])

    def goalCallBack(self, navigateToPoseGoal_msg):
        '''
        Gets next goal sent by fleet manager
        '''
        self.goal = navigateToPoseGoal_msg
        self.target_x = self.goal.pose.position.x
        self.target_y = self.goal.pose.position.y

    def main_loop(self):
        start_time = time.time()
        if self.target_x is None or self.target_y is None: 
            self.cmd_vel.linear.x, self.cmd_vel.angular.z = 0.0, 0.0
        else:
            self.compute_vel()
        """         self.get_logger().debug("Target X : " + self.target_x + "Target Y : " + self.target_y)
            self.get_logger().debug(self.robot_name + ' Forward Velocity command: ' +
                                            str(self.cmd_vel.linear.x) + ' angular: ' +
                                            str(self.cmd_vel.angular.z)) 
                                            """
            
        self.cmd_vel_pub.publish(self.cmd_vel)
        elapsed_time = time.time() - start_time
        if VERBOSE:
            self.get_logger().info("Main loop time: {0} [sec]".format(elapsed_time))


def main(args=None):
    rclpy.init(args=args)
    controller_node = DiffDriveRobot()
    controller_node.get_logger().info("Initiates node")
    rclpy.spin(controller_node)
    controller_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
