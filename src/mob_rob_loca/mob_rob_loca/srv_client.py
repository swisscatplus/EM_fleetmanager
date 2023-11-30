import rclpy
from rclpy.node import Node
from mob_rob_loca_interfaces.srv import UR

class UR_Service(Node):

    def __init__(self):
        super().__init__('ur_service')
        self.srv = self.create_service(UR, 'calibrate', self.calibrate_callback)

    def calibrate_callback(self, request, response):
        # get the pose from the camera using Cognex and insert them here
        response.pos_x, response.pos_y, response.r_z = (0, 0, 0)#[TO DO] [m m deg]
        # self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))

        return response


def main():
    rclpy.init()

    minimal_service = UR_Service()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()

# #     Client :

# import sys

# from example_interfaces.srv import UR_Calibration
# import rclpy
# from rclpy.node import Node


# class UR_Client(Node):

#     def __init__(self):
#         super().__init__('ur_client')
#         self.cli = self.create_client(UR_Calibration, 'calibrate')
#         while not self.cli.wait_for_service(timeout_sec=1.0):
#             self.get_logger().info('service not available, waiting again...')
#         self.req = UR_Calibration.Request()

#     # send calibrate request
#     def send_request(self):
#         self.future = self.cli.call_async(self.req)
#         rclpy.spin_until_future_complete(self, self.future)
#         return self.future.result()


# def main():
#     rclpy.init()

#     minimal_client = UR_Client()
#     response = minimal_client.send_request(int(sys.argv[1]), int(sys.argv[2]))
#     minimal_client.get_logger().info(
#         'Result of calibration: ( %d , %d , %d )' %
#         (response.pos_x, response.pos_y, response.r_z))

#     minimal_client.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()

# def action_callback(future):
#     # Check action feedback
#     # You can implement logic based on the action feedback here
#     if future.done():
#         # Action completed, call the service
#         # call_service()


# # def call_service(node):
# #     # Create a service client
# #     service_client = node.create_client(UR_Calibration, 'ur_calibration')

# #     # Wait for the service to be available
# #     if not service_client.wait_for_service(timeout_sec=1.0):
# #         raise RuntimeError('Service not available')

# def main():
#     rclpy.init()
#     node = rclpy.create_node('ur_handler')

#     # Create an action client
#     action_client = node.create_client(UR, 'ur_handler')

#     # Wait for the action server to be available
#     if not action_client.wait_for_server(timeout_sec=1.0):
#         raise RuntimeError('Action server not available')

#     # Prepare action goal
#     goal_msg = UR.Goal()
#     # Populate your action goal here

#     # Send the action goal
#     future = action_client.send_goal_async(goal_msg, feedback_callback=action_callback)

#     # Spin the node
#     rclpy.spin_until_future_complete(node, future)

#     # Clean up
#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()