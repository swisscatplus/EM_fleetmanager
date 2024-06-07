import rclpy # Python Client Library for ROS 2
from rclpy.node import Node # Handles the creation of nodes
from geometry_msgs.msg import Pose, PoseWithCovarianceStamped # Message type for publishing robot pose
import cv2 as cv # OpenCV library
from tf_transformations import quaternion_from_euler
from launch_ros.substitutions import FindPackageShare
from mob_rob_loca.submodules.utils import get_config_yaml
from mob_rob_loca.submodules.detect_aruco_pc import CameraVisionStation, detector
import os
# ################# CONFIG #################
# station_id = 'station_1'
package_name = 'mob_rob_loca'
params_path = 'config/rpi_cam_on_robot.yaml'
cam_port = 0 # worked for me, use 0 if you want to use the embedded wembcam of the computer, or try other numbers
timer_period = 0.1  # seconds
# ##########################################

pkg_share = FindPackageShare(package=package_name).find(package_name)
config_file_path = os.path.join(pkg_share, params_path)

class RobotCamPublisher(Node):
  """
  Create an ImagePublisher class, which is a subclass of the Node class.
  """
  def __init__(self):
    """
    Class constructor to set up the node
    """
    
    super().__init__('robot_cam_publisher')
    self.get_logger().info(f'Starting node', once=True)
    self.declare_parameter('config_file_path', config_file_path) #default value to config_file_path if not found
    config_path = self.get_parameter('config_file_path').get_parameter_value().string_value
    self.config = get_config_yaml(config_path)

    self.cam = CameraVisionStation(config=self.config)

    self.cam_publisher = self.create_publisher(PoseWithCovarianceStamped, '/edi/cam', 10)
    
    self.timer = self.create_timer(timer_period, self.publish_frame)
    
    self.cap = cv.VideoCapture(cam_port)
    self.cap.set(cv.CAP_PROP_AUTOFOCUS, 0) #remove autofocus
  
  def publish_frame(self):
    ret, frame = self.cap.read()
      
    if ret:
      gray_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)  # Convert frame to grayscale
      markerCorners, markerIds, _ = detector.detectMarkers(gray_frame)  # Detect markers in grayscale frame
      # print('markerIds:', markerIds)
      if markerIds is not None:
            robot_pose, robot_angle = self.cam.get_robot_pose(frame, markerCorners, markerIds)
            if robot_pose is not None:
              print(robot_pose)
              pose = PoseWithCovarianceStamped()
              pose.header.frame_id = 'camera'
              pose.header.stamp = self.get_clock().now().to_msg()
              pose.pose.pose.position.x = robot_pose[0]
              pose.pose.pose.position.y = robot_pose[1]
              pose.pose.pose.orientation.x, pose.pose.pose.orientation.y, pose.pose.pose.orientation.z, pose.pose.pose.orientation.w,  = quaternion_from_euler(0, 0, robot_angle)

              self.get_logger().debug('ID: {0}, robot_pose: {1}, robot_angle: {2}'.format(markerIds, robot_pose, robot_angle))
            
              self.cam_publisher.publish(pose)
                

def main(args=None):
  rclpy.init()
  robot_cam_publisher = RobotCamPublisher()
  rclpy.spin(robot_cam_publisher)
  robot_cam_publisher.destroy_node()
  rclpy.shutdown()
   
if __name__ == '__main__':
  main()