from mob_rob_loca_msgs.srv import GoToStation     # CHANGE

import rclpy
from rclpy.node import Node


class MinimalService(Node):

    def __init__(self):
        super().__init__('minimal_service')
        self.srv = self.create_service(GoToStation, 'go_to_station', self.callback)        # CHANGE

    def callback(self, request, response):
        response.result_id = 10                                              # CHANGE
        self.get_logger().info('Incoming request\na: %s b: %s' % (request.station, request.robot_id)) # CHANGE

        return response

def main(args=None):
    rclpy.init(args=args)

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()

if __name__ == '__main__':
    main()