#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import pygame
import time


def apply_deadzone(value, threshold=0.05):
    return value if abs(value) > threshold else 0.0

class PS4ControllerTeleop(Node):
    def __init__(self):
        super().__init__('ps4_controller_teleop')
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)

        # Init pygame
        pygame.init()
        pygame.joystick.init()
        if pygame.joystick.get_count() == 0:
            self.get_logger().error("No joystick detected. Is the PS4 controller connected?")
            exit(1)

        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        self.get_logger().info(f"Detected controller: {self.joystick.get_name()}")

        self.timer = self.create_timer(0.1, self.publish_cmd_vel)  # 10 Hz

        # Tunable parameters
        self.linear_scale = 0.2  # m/s
        self.angular_scale = 1.0  # rad/s

    def publish_cmd_vel(self):
        pygame.event.pump()  # Refresh joystick state

        left_stick_y = apply_deadzone(-self.joystick.get_axis(1))
        left_stick_x = apply_deadzone(self.joystick.get_axis(0))
        right_stick_x = -apply_deadzone(self.joystick.get_axis(3))

        msg = Twist()
        msg.linear.x = left_stick_y * self.linear_scale
        msg.linear.y = left_stick_x * self.linear_scale
        msg.angular.z = right_stick_x * self.angular_scale

        self.publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = PS4ControllerTeleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down PS4 teleop node.")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
