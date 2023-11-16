import os
from rclpy.node import Node
from launch import LaunchDescription
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
import tf2_ros
import rclpy
import time

def get_share_file(package_name, file_name):
    return os.path.join(get_package_share_directory(package_name), file_name)

def generate_launch_description():
    rob_loca_dir = get_package_share_directory('mob_rob_loca')
    map_path = os.path.join(rob_loca_dir, 'maps', 'circuit.yaml')
    keepout_mask_path = os.path.join(rob_loca_dir, 'maps', 'keepout_mask.yaml')
    nav2_params_path = os.path.join(rob_loca_dir, 'params/no_map_params.yaml')
    nav2_dir = FindPackageShare(package='nav2_bringup').find('nav2_bringup') 
    nav2_launch_dir = os.path.join(nav2_dir, 'launch') 
    lifecycle_nodes = ['costmap_filter_info_server']
    use_sim_time = False
    autostart = True

    start_ros2_navigation_cmd = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(os.path.join(nav2_launch_dir, 'bringup_launch.py')),
    launch_arguments = {'map': map_path,
                        'use_sim_time': use_sim_time,
                        'params_file': nav2_params_path,
                        'autostart': autostart}.items())
    
    return LaunchDescription([
        start_ros2_navigation_cmd
    ])
