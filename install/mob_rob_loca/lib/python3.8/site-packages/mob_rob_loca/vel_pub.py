import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist

DURATION_SEC = 5

class OdomPubNode(Node):
    def __init__(self):
        super().__init__('odom_pub_node')
        self.cmd_vel_sub = self.create_subscription(Twist, 'cmd_vel', self.cmd_vel_callback, 10)
        self.odom_publi = self.create_publisher(Twist, 'wheel/speed', 10)
        self.wheel_odom = Twist()
        self.wheel_odom.linear.x = 0.0
        self.wheel_odom.linear.y = 0.0
        self.wheel_odom.linear.z = 0.0
        self.wheel_odom.angular.x = 0.0
        self.wheel_odom.angular.y = 0.0
        self.wheel_odom.angular.z = 0.0

        timer_frequency = 1.0
        self.timer = self.create_timer(1.0 / timer_frequency, self.publish_data)

    def cmd_vel_callback(self, msg):
        self.wheel_odom.linear.x = msg.linear.x 
        self.wheel_odom.angular.z = msg.angular.z 

    def publish_data(self):
        self.odom_publi.publish(self.wheel_odom)

def main(args=None):
    rclpy.init(args=args)
    vel_pub_node = OdomPubNode()
    rclpy.spin(vel_pub_node)
    vel_pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
