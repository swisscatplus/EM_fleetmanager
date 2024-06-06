import os
from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def get_share_file(package_name, file_name):
    return os.path.join(get_package_share_directory(package_name), file_name)

def generate_launch_description():
    rob_loca_dir = get_package_share_directory('mob_rob_loca')
    imu_config = os.path.join(rob_loca_dir,'config','bno055_params.yaml')
    # imu_config = os.path.join(get_package_share_directory('bno055'),'config','bno055_params.yaml')

    ticks2odom_node = Node(
        package='mob_rob_loca',
        executable='ticks2odom',
        output='screen',
    )

    marv2ekf_node = Node(
        package='mob_rob_loca',
        executable='marv2ekf',
        output='screen',
    )

    return LaunchDescription([
        # marv2ekf_node,
        ticks2odom_node,
    ])
