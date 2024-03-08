import os
from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch.substitutions import LaunchConfiguration, FindExecutable
from launch_ros.actions import Node

def get_share_file(package_name, file_name):
    return os.path.join(get_package_share_directory(package_name), file_name)

def generate_launch_description():
    rob_loca_dir = get_package_share_directory('mob_rob_loca')

    get_plot_data_node = Node(
        package='mob_rob_loca',
        executable='sub_plot',
        name='sub_plot',
    )

    return LaunchDescription([
        get_plot_data_node,
    ])
