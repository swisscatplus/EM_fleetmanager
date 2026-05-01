#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
import os


PACKAGE_NAME = 'fleet_manager'


def generate_launch_description():
    launch_dir = os.path.join(get_package_share_directory(PACKAGE_NAME), 'launch')
    rviz_config = os.path.join(
        get_package_share_directory(PACKAGE_NAME),
        'rviz',
        'fleet_manager.rviz',
    )

    maps_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_dir, 'maps.launch.py'))
    )
    markers_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_dir, 'markers.launch.py'))
    )
    use_rviz = LaunchConfiguration('use_rviz')

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        condition=IfCondition(use_rviz),
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_rviz',
            default_value='true',
            description='Launch RViz with the fleet_manager visualization config.',
        ),
        maps_launch,
        markers_launch,
        rviz_node,
    ])
