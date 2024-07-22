from mob_rob_loca_msgs.srv import GoToStation 
from mob_rob_loca.submodules.utils import get_config_yaml
import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from tf_transformations import quaternion_from_euler, euler_from_quaternion

config_path = '/ros2_ws/src/EM_fleetmanager/src/mob_rob_loca/config/stations.yaml' #'config/stations.yaml'
stations = get_config_yaml(config_path)

class NavService(Node):
    def __init__(self):
        super().__init__('minimal_service')
        self.srv = self.create_service(GoToStation, 'go_to_station', self.move_request)
        self.navigator = BasicNavigator()
        self.navigator._waitForNodeToActivate('bt_navigator')
        
    def move_request(self, request, response):
        self.get_logger().info('Incoming request\na: %s b: %s' % (request.station, request.robot_id))
        response.result_id = self.move( station=request.station, robot_id=request.robot_id)
        self.get_logger().info(f'Sending back response: {response}')
        return response

    def move(self, station: str, robot_id: str):
        if station not in stations:
            self.get_logger().error('Goal has an invalid station request!')
            return 1
        goal_pose = self.set_pose(station)
        self.navigator.goToPose(goal_pose)

        i = 0
        while not self.navigator.isTaskComplete():
            # Do something with the feedback OPTIONAL
            i = i + 1
            feedback = self.navigator.getFeedback()
            if feedback and i % 5 == 0:
                pass
            if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                self.navigator.cancelNav()

        # Do something depending on the return code
        result = self.navigator.getResult()
        self.get_logger().info(f"Result: {result}")
        if result == TaskResult.SUCCEEDED: 
            result = 0 # sets to 1 when success, to match sched code it's reversed to 0
            self.get_logger().info('Goal succeeded!')
        elif result == TaskResult.CANCELED:
            self.get_logger().error('Goal was canceled!')
            return result.value
        elif result == TaskResult.FAILED:
            self.get_logger().error('Goal failed, returning home!')
            return result.value
        else:
            result = 1
            self.get_logger().error('Goal has an invalid return status!')

        return result
        
    def set_pose(self, station):
        """
        Defines the ROS pose message for the goal.
        """
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.pose.position.x = stations[station]['pos_x']
        goal_pose.pose.position.y = stations[station]['pos_y']

        yaw = stations[station]['yaw']
        quaternion = quaternion_from_euler(0.0, 0.0, yaw)
        self.get_logger().info(f"Station: {station}, quaternion: {quaternion}")
        goal_pose.pose.orientation.x = 0.0
        goal_pose.pose.orientation.y = 0.0
        goal_pose.pose.orientation.z = quaternion[2]
        goal_pose.pose.orientation.w = quaternion[3]
        return goal_pose

def main(args=None):
    rclpy.init(args=args)
    nav_service = NavService()
    rclpy.spin(nav_service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()