import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from launch_ros.substitutions import FindPackageShare
import os
import yaml

###########################################
params_path = 'config/rpi_cam_on_robot.yaml'
package_name = 'mob_rob_loca'
###########################################

pkg_share = FindPackageShare(package=package_name).find(package_name)
config_file_path = os.path.join(pkg_share, params_path)

class MarkerPublisher(Node):
    """
    This node publishes markers to visualize the ArUco markers in RViz.
    """
    def __init__(self):
        super().__init__('marker_publisher')
        with open(config_file_path, 'r') as file:
            self.config = yaml.safe_load(file)

        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.marker_id = 0

    def timer_callback(self):
        for _, params in self.config['aruco_params'].items():
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = 'markers'
            marker.id = self.marker_id
            marker.type = Marker.CUBE
            marker.action = Marker.ADD
            marker.pose.position.x = params['t_x']
            marker.pose.position.y = params['t_y']
            marker.pose.position.z = 0.0
            marker.pose.orientation.x = 0.0
            marker.pose.orientation.y = 0.0
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
            marker.scale.x = 0.1
            marker.scale.y = 0.1
            marker.scale.z = 0.1
            marker.color.a = 1.0
            marker.color.r = 1.0
            marker.color.g = 0.0
            marker.color.b = 0.0

            self.publisher.publish(marker)
            self.marker_id += 1

def main(args=None):
    rclpy.init(args=args)
    node = MarkerPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()