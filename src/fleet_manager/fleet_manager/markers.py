#!/usr/bin/env python3

import math
import os

from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import TransformStamped
import numpy as np
import rclpy
from rclpy.node import Node
import tf2_ros

# tf_transformations on ROS Humble still references the removed NumPy aliases.
if not hasattr(np, 'float'):
    np.float = float

import tf_transformations
import yaml


PACKAGE_NAME = 'fleet_manager'
CONFIG_NAMESPACE = 'fleet_manager'


class MarkersNode(Node):
    def __init__(self) -> None:
        super().__init__('markers_node')

        config_file = os.path.join(
            get_package_share_directory(PACKAGE_NAME),
            'config',
            'markers.yaml',
        )

        self.get_logger().info(f'Loading marker configuration from: {config_file}')
        with open(config_file, 'r', encoding='utf-8') as file:
            config = yaml.safe_load(file)

        tracks = (
            config.get(CONFIG_NAMESPACE, {})
            .get('ros__parameters', {})
            .get('tracks', {})
        )

        self._static_broadcaster = tf2_ros.StaticTransformBroadcaster(self)
        self.publish_transforms(tracks)

    def publish_transforms(self, tracks: dict) -> None:
        static_transforms = []

        for track_id, track_data in tracks.items():
            qx, qy, qz, qw = tf_transformations.quaternion_from_euler(
                0.0,
                0.0,
                track_data.get('yaw', 0.0),
            )

            ts_track = TransformStamped()
            ts_track.header.stamp = self.get_clock().now().to_msg()
            ts_track.header.frame_id = 'map'
            ts_track.child_frame_id = f'track_{track_id}'
            ts_track.transform.translation.x = track_data.get('t_x', 0.0)
            ts_track.transform.translation.y = track_data.get('t_y', 0.0)
            ts_track.transform.translation.z = 0.0
            ts_track.transform.rotation.x = qx
            ts_track.transform.rotation.y = qy
            ts_track.transform.rotation.z = qz
            ts_track.transform.rotation.w = qw
            static_transforms.append(ts_track)

            for marker_id, marker_data in track_data.get('markers', {}).items():
                qx_m, qy_m, qz_m, qw_m = tf_transformations.quaternion_from_euler(
                    math.pi,
                    0.0,
                    marker_data.get('yaw', 0.0) + math.pi,
                )

                ts_marker = TransformStamped()
                ts_marker.header.stamp = self.get_clock().now().to_msg()
                ts_marker.header.frame_id = f'track_{track_id}'
                ts_marker.child_frame_id = f'aruco_{marker_id}'
                ts_marker.transform.translation.x = marker_data.get('t_x', 0.0)
                ts_marker.transform.translation.y = marker_data.get('t_y', 0.0)
                ts_marker.transform.translation.z = marker_data.get('t_z', 0.375)
                ts_marker.transform.rotation.x = qx_m
                ts_marker.transform.rotation.y = qy_m
                ts_marker.transform.rotation.z = qz_m
                ts_marker.transform.rotation.w = qw_m
                static_transforms.append(ts_marker)

        self._static_broadcaster.sendTransform(static_transforms)
        self.get_logger().info(f'Published {len(static_transforms)} static transforms.')


def main(args=None) -> None:
    rclpy.init(args=args)
    node = MarkersNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
