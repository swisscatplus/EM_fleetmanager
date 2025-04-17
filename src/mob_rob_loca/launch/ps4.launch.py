from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='mob_rob_loca',  # Replace with your actual package name
            executable='ps4_teleop',
            name='ps4_teleop_node',
            output='screen'
        )
    ])
