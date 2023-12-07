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
    imu_config = os.path.join(get_package_share_directory('bno055'),'config','bno055_params.yaml')

    marvelmind_ros2_config_file = get_share_file(
        package_name='marvelmind_ros2', file_name='config/marvelmind_ros2_config.yaml'
    )

    marvelmind_ros2_config = DeclareLaunchArgument(
        'marvelmind_ros2_config_file',
        default_value=marvelmind_ros2_config_file,
        description='Path to config file for marvelmind_ros2_config parameters'
    )

    marvelmind_ros2_node = Node(
        package='marvelmind_ros2',
        executable='marvelmind_ros2',
        output='screen',
        arguments=['--ros-args', '--log-level', 'rclcpp:=WARN', '--log-level', 'hedgehog_logger:=INFO'],
        parameters=[LaunchConfiguration('marvelmind_ros2_config_file')],
    )

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
        # marvelmind_ros2_config,  # comment both lines when testing, avoids getting repetitive log messages
        # marvelmind_ros2_node,
        marv2ekf_node,
        ticks2odom_node,
    ])
