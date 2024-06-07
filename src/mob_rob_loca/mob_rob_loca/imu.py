# imu_publisher/imu_pub.py
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from std_msgs.msg import Header

class ImuPublisher(Node):
    def __init__(self):
        super().__init__('imu_pub')
        self.publisher_ = self.create_publisher(Imu, 'edi/imu', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.publish_imu_data)
        self.get_logger().info('IMU Publisher has been started.')

    def publish_imu_data(self):
        imu_msg = Imu()
        imu_msg.header = Header()
        imu_msg.header.stamp = self.get_clock().now().to_msg()
        imu_msg.header.frame_id = 'imu'

        # Setting all IMU data to 0
        imu_msg.orientation.x = 0.0
        imu_msg.orientation.y = 0.0
        imu_msg.orientation.z = 0.0
        imu_msg.orientation.w = 0.0
        imu_msg.angular_velocity.x = 0.0
        imu_msg.angular_velocity.y = 0.0
        imu_msg.angular_velocity.z = 0.0
        imu_msg.linear_acceleration.x = 0.0
        imu_msg.linear_acceleration.y = 0.0
        imu_msg.linear_acceleration.z = 0.0

        self.publisher_.publish(imu_msg)
        self.get_logger().debug('Publishing IMU data: %s' % imu_msg)

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = ImuPublisher()
    rclpy.spin(imu_publisher)
    imu_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
