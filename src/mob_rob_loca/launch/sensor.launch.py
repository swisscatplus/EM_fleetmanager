import os
from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    
    convert_sens_type = Node(
        package='mob_rob_loca',
        executable='convert_sens_type',
        output='screen',
    )

    return LaunchDescription([
        convert_sens_type
    ])

