#!/usr/bin/env python3

import os
import yaml

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
import tf2_ros

from ament_index_python.packages import get_package_share_directory
import tf_transformations


class MarkersNode(Node):
    def __init__(self):
        super().__init__('markers_node')

        # Load YAML
        pkg_share_dir = get_package_share_directory('mob_rob_loca')
        config_file = os.path.join(pkg_share_dir, 'config', 'markers.yaml')

        self.get_logger().info(f'Loading marker configuration from: {config_file}')
        with open(config_file, 'r') as f:
            config = yaml.safe_load(f)

        tracks = (
            config.get('mob_rob_loca', {})
                  .get('ros__parameters', {})
                  .get('tracks', {})
        )

        self._static_broadcaster = tf2_ros.StaticTransformBroadcaster(self)
        self.publish_transforms(tracks)

    def publish_transforms(self, tracks):
        static_transforms = []

        for track_id, track_data in tracks.items():
            # Publish map → track_X
            t_x = track_data.get("t_x", 0.0)
            t_y = track_data.get("t_y", 0.0)
            yaw = track_data.get("yaw", 0.0)

            qx, qy, qz, qw = tf_transformations.quaternion_from_euler(0.0, 0.0, yaw)

            ts_track = TransformStamped()
            ts_track.header.stamp = self.get_clock().now().to_msg()
            ts_track.header.frame_id = "map"
            ts_track.child_frame_id = f"track_{track_id}"
            ts_track.transform.translation.x = t_x
            ts_track.transform.translation.y = t_y
            ts_track.transform.translation.z = 0.0
            ts_track.transform.rotation.x = qx
            ts_track.transform.rotation.y = qy
            ts_track.transform.rotation.z = qz
            ts_track.transform.rotation.w = qw

            static_transforms.append(ts_track)

            # Now publish track_X → aruco_ID
            markers = track_data.get("markers", {})
            for marker_id, marker_data in markers.items():
                m_tx = marker_data.get("t_x", 0.0)
                m_ty = marker_data.get("t_y", 0.0)
                m_tz = marker_data.get("t_z", 0.375)
                m_yaw = marker_data.get("yaw", 0.0)

                qx_m, qy_m, qz_m, qw_m = tf_transformations.quaternion_from_euler(0.0, 0.0, m_yaw)

                ts_marker = TransformStamped()
                ts_marker.header.stamp = self.get_clock().now().to_msg()
                ts_marker.header.frame_id = f"track_{track_id}"
                ts_marker.child_frame_id = f"aruco_{marker_id}"
                ts_marker.transform.translation.x = m_tx
                ts_marker.transform.translation.y = m_ty
                ts_marker.transform.translation.z = m_tz
                ts_marker.transform.rotation.x = qx_m
                ts_marker.transform.rotation.y = qy_m
                ts_marker.transform.rotation.z = qz_m
                ts_marker.transform.rotation.w = qw_m

                static_transforms.append(ts_marker)

        # Broadcast all
        self._static_broadcaster.sendTransform(static_transforms)
        self.get_logger().info(f'Published {len(static_transforms)} static transforms.')


def main(args=None):
    rclpy.init(args=args)
    node = MarkersNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
