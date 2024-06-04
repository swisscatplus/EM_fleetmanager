import rclpy # Python Client Library for ROS 2
from rclpy.node import Node # Handles the creation of nodes
from nav_msgs.msg import Odometry
from mob_rob_loca.submodules.Robot import Robot, RobotType, EM

class FleetManager(Node):
  """
  Create an ImagePublisher class, which is a subclass of the Node class.
  """
  def __init__(self):
    """
    Class constructor to set up the node
    """
    
    super().__init__('robot_cam_publisher')
    self.get_logger().info(f'Starting node', once=True)
    # Initializes the fleet
    self.robot_namespaces = ['robot_1', 'robot_2', 'robot_3'] # to be configured from yaml

    self.robots = {EM(name_id=namespace, is_operational=True) for namespace in self.robot_namespaces}
    self.get_logger().info(f"Initialized robots: {self.robots}")
    self.verbose = True
    
    # Subscribes to the different odometry topics of the EMs
    self.subscribers = []
    for namespace in self.robot_namespaces:
        odom_topic = f"{namespace}/odometry_filtered"
        self.get_logger().debug(f"Subscribing to topic: {odom_topic}")
        subscriber = self.create_subscription(
            Odometry,
            odom_topic,
            lambda msg, ns=namespace: self.odom_callback(msg, ns),
            10)
        self.subscribers.append(subscriber)

    
                
    def odom_callback(self, msg, namespace):
        if self.verbose:
            self.get_logger().info(f"Received odometry from {namespace}: {msg}")
        # don't know if useful yet, or if we only update prior some action ex service call
        for robot in self.robots:
            if robot.name_id == namespace: #safety check
                robot.update_pose(msg.pose.pose)
                break

def main(args=None):
  rclpy.init()
  fleet_manager = FleetManager()
  rclpy.spin(fleet_manager)
  fleet_manager.destroy_node()
  rclpy.shutdown()
   
if __name__ == '__main__':
  main()