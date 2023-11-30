import sys

from mob_rob_loca_interfaces.srv import UR
import rclpy
from rclpy.node import Node


class UR_Client(Node):

    def __init__(self):
        super().__init__('ur_client')
        self.cli = self.create_client(UR, 'calibrate')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = UR.Request()

    # send calibrate request
    def send_request(self):
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


def main():
    rclpy.init()

    minimal_client = UR_Client()
    response = minimal_client.send_request(int(sys.argv[1]), int(sys.argv[2]))
    minimal_client.get_logger().info(
        'Result of calibration: ( %d , %d , %d )' %
        (response.pos_x, response.pos_y, response.r_z))

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()