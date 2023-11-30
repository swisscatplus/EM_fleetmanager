import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from mob_rob_loca.action import UR_com


class UR_Handler(Node):

    def __init__(self):
        super().__init__('UR_EM_handler')
        self._action_server = ActionServer(
            self,
            UR_com,
            'ur_com',
            self.execute_callback)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')

        feedback_msg = UR_com.Feedback()

        feedback_msg.processing = 'Processing...'

        self.get_logger().info('Feedback: {0}'.format(feedback_msg.processing))

        goal_handle.publish_feedback(feedback_msg)

        goal_handle.succeed()

        result = UR_com.Result()

        result.success = True

        return result


def main(args=None):
    rclpy.init(args=args)

    ur_handler = UR_Handler()

    rclpy.spin(ur_handler)


if __name__ == '__main__':
    main()