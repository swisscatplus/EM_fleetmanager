#!/usr/bin/env python3

import os
import rclpy
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid
from geometry_msgs.msg import Pose, Point, Quaternion
import cv2
import numpy as np
from ament_index_python.packages import get_package_share_directory

class CustomMapPublisher(Node):
    def __init__(self):
        super().__init__('custom_map_publisher')
        self.publisher = self.create_publisher(OccupancyGrid, 'map', 10)
        # Publish map every 1 second (adjust as needed)
        self.timer = self.create_timer(1.0, self.publish_map)

        map_params = os.path.join(
            get_package_share_directory('mob_rob_loca'),
            'maps',
            'circuit_mr.png'
        )
        # Parameters: adjust these to match your map file and settings
        self.map_file = map_params  # full path to your map image
        self.resolution = 0.05  # meters per pixel
        self.origin = [-10.0, -10.0, 0.0]  # x, y, yaw (set yaw=0 for now)

        # Load the map image and convert it to occupancy data
        self.load_map()

    def load_map(self):
        # Load image in grayscale mode
        image = cv2.imread(self.map_file, cv2.IMREAD_GRAYSCALE)
        if image is None:
            self.get_logger().error("Unable to load map image from: " + self.map_file)
            return

        self.height, self.width = image.shape

        # Convert image to binary occupancy grid:
        # Assume white (255) represents free space and black (0) represents occupied.
        # You might want to adjust the threshold values.
        thresh_value = 200  # adjust threshold if needed
        _, binary = cv2.threshold(image, thresh_value, 255, cv2.THRESH_BINARY)

        # Create occupancy grid data:
        # ROS occupancy grid convention:
        #   - Free: 0
        #   - Occupied: 100
        #   - Unknown: -1
        # Here, we map white to free and black to occupied.
        occupancy = []
        for row in binary:
            for pixel in row:
                if pixel == 255:
                    occupancy.append(0)
                else:
                    occupancy.append(100)

        self.occupancy_data = occupancy
        self.get_logger().info(f"Loaded map: {self.width}x{self.height} cells")

    def publish_map(self):
        # Build the OccupancyGrid message
        map_msg = OccupancyGrid()
        map_msg.header.stamp = self.get_clock().now().to_msg()
        map_msg.header.frame_id = "map"  # The fixed frame for the map

        # Set metadata
        map_msg.info.resolution = self.resolution
        map_msg.info.width = self.width
        map_msg.info.height = self.height

        # Set the map origin
        map_msg.info.origin.position.x = self.origin[0]
        map_msg.info.origin.position.y = self.origin[1]
        map_msg.info.origin.position.z = 0.0
        # For simplicity, we use an identity orientation (no rotation)
        map_msg.info.origin.orientation = Quaternion(w=1.0, x=0.0, y=0.0, z=0.0)

        # Set the occupancy data
        map_msg.data = self.occupancy_data

        # Publish the message
        self.publisher.publish(map_msg)
        self.get_logger().info("Published custom map.")

def main(args=None):
    rclpy.init(args=args)
    node = CustomMapPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
