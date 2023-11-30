import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from mob_rob_loca.action import UR_com


class UR_Request(Node):

    def __init__(self):
        super().__init__('UR_EM_request')
        self._action_client = ActionClient(self, UR_com, 'ur_com')

    def send_goal(self):
        goal_msg = UR_com.Goal()

        self._action_client.wait_for_server()

        return self._action_client.send_goal_async(goal_msg)


def main(args=None):
    rclpy.init(args=args)

    action_client = UR_Request()

    future = action_client.send_goal()

    rclpy.spin_until_future_complete(action_client, future)


if __name__ == '__main__':
    main()

