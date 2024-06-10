from mob_rob_loca_msgs.srv import GoToStation 
from mob_rob_loca.submodules.utils import get_config_yaml
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult

config_path = '/home/coderey/EM_navigation/src/mob_rob_loca/config/stations.yaml' #'config/stations.yaml'
stations = get_config_yaml(config_path)

class NavService(Node):

    def __init__(self):
        super().__init__('minimal_service')
        self.srv = self.create_service(GoToStation, 'go_to_station', self.callback)        # CHANGE
        self.navigator = BasicNavigator()
        self.navigator._waitForNodeToActivate('bt_navigator')
    def callback(self, request, response):
        # response.result_id = 0                                              # CHANGE
        self.get_logger().info('Incoming request\na: %s b: %s' % (request.station, request.robot_id)) # CHANGE
        response.result_id = self.move(robot_id=request.robot_id, station=request.station)
        self.get_logger().info(f'Sending back response: {response}')
        return response

    def move(self, robot_id: str, station: str):
        
        
        goal_pose = self.set_pose(station)
        print(goal_pose.pose.position.x)
        # self.get_logger().info(f'goal_pose: x=%f, y=%f', goal_pose.pose.position.x, goal_pose.pose.position.y)
        self.navigator.goToPose(goal_pose)

        i = 0
        while not self.navigator.isTaskComplete():

            # Do something with the feedback 
            i = i + 1
            feedback = self.navigator.getFeedback()
            if feedback and i % 5 == 0:
                pass
                # print(feedback) # nav2_msgs.action.FollowWaypoints_Feedback(current_waypoint=0)
                # print('Executing current waypoint: ' +
                    #   str(feedback.current_waypoint + 1) + '/' + str(len(goal_poses)))
                # now = self.navigator.get_clock().now()
            # if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
            #     navigator.cancelNav()

        # Do something depending on the return code
        result = self.navigator.getResult()
        if result == TaskResult.SUCCEEDED:
            self.get_logger().info('Goal succeeded, going to next waypoint!')
        elif result == TaskResult.CANCELED:
            self.get_logger().error('Goal was canceled!')
        elif result == TaskResult.FAILED:
            self.get_logger().error('Goal failed, returning home!')
        else:
            self.get_logger().error('Goal has an invalid return status!')

        # self.navigator.destroy_node()

        return 0 #result
        # navigator.lifecycleShutdown()

        # exit(0)
        
    def set_pose(self, station):
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.pose.position.x = stations[station]['pos_x']
        goal_pose.pose.position.y = stations[station]['pos_y']
        return goal_pose

def main(args=None):
    rclpy.init(args=args)
    nav_service = NavService()
    rclpy.spin(nav_service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()