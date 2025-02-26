#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # Get the package share directory (adjust the package name as necessary)
    pkg_share = get_package_share_directory('mob_rob_loca')

    # Optionally, if you want to pass a map file as a parameter you could do so here.
    # For example, if your node accepted a parameter called 'map_file' you might do:
    # map_file = os.path.join(pkg_share, 'maps', 'your_map.png')

    return LaunchDescription([
        Node(
            package='mob_rob_loca',
            executable='map',  # The name of your executable node
            name='custom_map_publisher',
            output='screen',
            # Uncomment and adjust the parameters below if your node supports parameters.
            # parameters=[{'map_file': map_file, 'resolution': 0.05, 'origin': [-10.0, -10.0, 0.0]}],
        )
    ])
