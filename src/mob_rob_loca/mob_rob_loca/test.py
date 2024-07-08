import rclpy # Python Client Library for ROS 2
from rclpy.node import Node # Handles the creation of nodes
from geometry_msgs.msg import Pose, PoseWithCovarianceStamped # Message type for publishing robot pose
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import cv2 as cv # OpenCV library
from rclpy.executors import ExternalShutdownException
from tf_transformations import quaternion_from_euler
from mob_rob_loca.submodules.detect_aruco_pc import CameraVisionStation, detector
from launch_ros.substitutions import FindPackageShare
import yaml
import os
import sys

# ################# CONFIG #################
package_name = 'rpi_pkg'
params_path = 'config/loca.yaml'
timer_period = 0.2  # seconds, corresponds to publisher frequency
# ##########################################

pkg_share = FindPackageShare(package=package_name).find(package_name)
config_file_path = os.path.join(pkg_share, params_path)
calib_mat_file_path = os.path.join(pkg_share, 'config', 'cameraMatrix.pkl')
calib_dist_file_path = os.path.join(pkg_share, 'config', 'dist.pkl')

class RobotCamPublisher(Node):
  """
  Create an ImagePublisher class, which is a subclass of the Node class.
  """
  def __init__(self):
    """
    Class constructor to set up the node
    """
    super().__init__('rpi_cam')
    
    self.size = (640, 480) # size of the frame
    self.cap = cv.VideoCapture(0)
    self.cap.set(cv.CAP_PROP_AUTOFOCUS, 0) #remove autofocus

    # Declare and get parameters
    self.declare_parameter('config_file', '/home/coderey/EM_navigation/install/mob_rob_loca/share/mob_rob_loca/config/cam.yaml')
    config_file = self.get_parameter('config_file').get_parameter_value().string_value

    # Load parameters from YAML file
    if os.path.exists(config_file):
        with open(config_file, 'r') as file:
            params = yaml.safe_load(file)
            self.get_logger().info(f"Loaded parameters: {params}")

        node_params = params.get(self.get_name(), {}).get('ros__parameters', {})

        # Example: Accessing specific parameters
        cam_params = node_params.get('cam_params', {})
        lens_position = cam_params.get('lens_position', 2.32)
        aruco_params = node_params.get('aruco_params', {})

        self.get_logger().info(f"lens position: {lens_position}")

    else:
        self.get_logger().error(f"Config file {config_file} does not exist")
    
    self.cam = CameraVisionStation(cam_params=cam_params, aruco_params=aruco_params, cam_frame=self.size)
    self.cam_publisher = self.create_publisher(PoseWithCovarianceStamped, 'edi/cam', 5)
    
    self.timer = self.create_timer(timer_period, self.publish_frame)

  def get_cam_config(self, config_file_path=None):
      with open(config_file_path, 'r') as file:
          data = yaml.safe_load(file)
      return data
  
  def publish_frame(self):
    ret, frame = self.cap.read()
      
    if ret:
        gray_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)  # Convert frame to grayscale

        markerCorners, markerIds, _ = detector.detectMarkers(gray_frame)  # Detect markers in grayscale frame

        if markerIds is not None:
            robot_pose, robot_angle = self.cam.get_robot_pose(gray_frame, markerCorners, markerIds)
            
            if robot_pose is not None:
                    pose = PoseWithCovarianceStamped()
                    pose.header.frame_id = 'map'
                    pose.header.stamp = self.get_clock().now().to_msg()
                    pose.pose.pose.position.x = robot_pose[0]
                    pose.pose.pose.position.y = robot_pose[1]
                    pose.pose.pose.orientation.x, pose.pose.pose.orientation.y, pose.pose.pose.orientation.z, pose.pose.pose.orientation.w  = quaternion_from_euler(0, 0, robot_angle)
                    pose.pose.covariance = [0.001, 0.0, 0.0, 0.0, 0.0, 0.0,
                                            0.0, 0.001, 0.0, 0.0, 0.0, 0.0,
                                            0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
                                            0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 
                                            0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 
                                            0.0, 0.0, 0.0, 0.0, 0.0, 0.001]
                    self.get_logger().debug('ID:' +  str(pose.pose.pose.orientation))
                    self.get_logger().debug('robot_pose:' +  str(pose))
                    self.cam_publisher.publish(pose)

def main(args=None):
  rclpy.init()
  robot_cam_publisher = RobotCamPublisher()
  try:
    rclpy.spin(robot_cam_publisher)
  except KeyboardInterrupt:
    robot_cam_publisher.destroy_node()
  except ExternalShutdownException:
    sys.exit(1)
   
if __name__ == '__main__':
  main()

