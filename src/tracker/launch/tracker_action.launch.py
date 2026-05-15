from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace


def generate_launch_description():
    robot_name = LaunchConfiguration('robot_name')
    robot_namespace = LaunchConfiguration('robot_namespace')
    map_frame = LaunchConfiguration('map_frame')
    base_link_frame = LaunchConfiguration('base_link_frame')
    paths_config = LaunchConfiguration('paths_config')

    tracker_node = Node(
        package='tracker',
        executable='tracker',
        name='tracker',
        output='screen',
        parameters=[{
            'robot_name': robot_name,
            'map_frame': map_frame,
            'base_link_frame': base_link_frame,
            'paths_config': paths_config,
        }],
        arguments=['--ros-args', '--log-level', 'info'],
    )

    return LaunchDescription([
        DeclareLaunchArgument('robot_name', default_value='robot1'),
        DeclareLaunchArgument('robot_namespace', default_value='robot1'),
        DeclareLaunchArgument('map_frame', default_value='map'),
        DeclareLaunchArgument('base_link_frame', default_value='base_link'),
        DeclareLaunchArgument('paths_config', default_value='paths.yaml'),
        GroupAction([
            PushRosNamespace(robot_namespace),
            tracker_node,
        ]),
    ])
