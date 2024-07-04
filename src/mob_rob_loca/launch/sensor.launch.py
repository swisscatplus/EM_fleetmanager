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
    cam_config = os.path.join(rob_loca_dir,'config','loca.yaml')

    # namespace = LaunchConfiguration('namespace')
 
    # namespace_arg = DeclareLaunchArgument(
    #     'namespace',
    #     default_value='',
    #     description='Specifying namespace for individual robot'
    # )

    config_file = DeclareLaunchArgument(
            'config_file',
            default_value=cam_config,
            description='Path to the config file'
        )
    
    convert_sens_type = Node(
        package='mob_rob_loca',
        executable='convert_sens_type',
        output='screen',
        parameters=[LaunchConfiguration('config_file')]
    )

    test_node = Node(
        package='mob_rob_loca',
        executable='test_node',
        output='screen',
        parameters=[LaunchConfiguration('config_file')]
    )

    return LaunchDescription([
        config_file,
        # convert_sens_type,
        test_node
    ])
