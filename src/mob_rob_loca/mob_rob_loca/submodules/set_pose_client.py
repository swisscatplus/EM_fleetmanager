import sys

from robot_localization.srv import SetPose
import rclpy
from rclpy.node import Node


class SetPose_Client(Node):

    def __init__(self, pose_to_set):
        super().__init__('set_pose_client')
        self.pose_to_set = pose_to_set
        self.cli = self.create_client(SetPose, 'set_pose')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = SetPose.Request()

    def send_request(self):
        self.req.pose = self.pose_to_set
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


# def main(args=None):
#     rclpy.init(args=args)

    # minimal_client = SetPose_Client()
    # minimal_client.send_request()
    # minimal_client.get_logger().info('New pose set')

    # minimal_client.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()