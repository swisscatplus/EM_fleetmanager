import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    markers_node = Node(
        package='mob_rob_loca',
        executable='markers',
        name='markers',
        output='screen'
    )

    return LaunchDescription([
        markers_node,
    ])
