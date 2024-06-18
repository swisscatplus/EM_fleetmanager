import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Get the launch directory
    package_name = 'mob_rob_loca'
    pkg_dir = get_package_share_directory(package_name)
    map_path = os.path.join(pkg_dir, 'maps', 'circuit.yaml')
    nav2_params_path = os.path.join(pkg_dir, 'params/nav_params.yaml')
    urdf_path = os.path.join(pkg_dir, 'urdf/edison.urdf')
    rvizconfig = LaunchConfiguration('rvizconfig', default=os.path.join(pkg_dir, 'rviz', 'loca.rviz'))
    ekf_params_path = 'params/ekf_em.yaml'
    pkg_share = FindPackageShare(package=package_name).find(package_name)
    robot_localization_file_path = os.path.join(pkg_share, ekf_params_path)
    # Create our own temporary YAML files that include substitutions
    lifecycle_nodes = ['map_server','filter_mask_server', 'costmap_filter_info_server']

    # Parameters
    namespace = LaunchConfiguration('namespace')
    use_sim_time = LaunchConfiguration('use_sim_time')
    autostart = LaunchConfiguration('autostart')
    params_file = LaunchConfiguration('params_file')
    mask_yaml_file = LaunchConfiguration('mask')

    # Declare the launch arguments
    declare_namespace_cmd = DeclareLaunchArgument(
        'namespace',
        default_value='',
        description='Top-level namespace')

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation (Gazebo) clock if true')

    declare_autostart_cmd = DeclareLaunchArgument(
        'autostart', default_value='true',
        description='Automatically startup the nav2 stack')

    declare_params_file_cmd = DeclareLaunchArgument(
        'params_file',
        default_value=os.path.join(pkg_dir, 'params', 'keepout_params.yaml'),
        description='Full path to the ROS 2 parameters file to use')

    declare_mask_yaml_file_cmd = DeclareLaunchArgument(
        'mask',
        default_value=os.path.join(pkg_dir, 'maps', 'keepout_mask.yaml'),
        description='Full path to filter mask yaml file to load')

    # Make re-written yaml
    param_substitutions = {
        'use_sim_time': use_sim_time,
        'yaml_filename': mask_yaml_file}

    configured_params = RewrittenYaml(
        source_file=params_file,
        root_key=namespace,
        param_rewrites=param_substitutions,
        convert_types=True)

    convert_sens_type = Node(
        package=package_name,
        executable='convert_sens_type',
        output='screen',
    )

    ekf_odom = Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node_odom',
            output='screen',
            parameters=[robot_localization_file_path],
            remappings=[('/odometry/filtered', 'odometry/filt')],
        )
    ekf_map = Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node_map',
            output='screen',
            parameters=[robot_localization_file_path],
            remappings=[('/odometry/filtered', 'odometry/global')],
    )
    rviz_node = Node(
           executable='rviz2',
        arguments=['-d', rvizconfig],
        output='screen',
        remappings=[('/odom', '/odometry/global')],
    )                 

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='both',
        parameters=[{'robot_description': open(urdf_path, 'r').read()}],
        remappings = [('/tf', 'tf'), ('tf_static', 'tf_static')],
    )

    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        arguments=[urdf_path],
        remappings = [('/tf', 'tf'), ('tf_static', 'tf_static')],
    )

    markers_node = Node(
        package=package_name,
        executable='markers',
        name='markers',
    )

    # Nodes launching commands
    start_lifecycle_manager_cmd = Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_costmap_filters',
            namespace=namespace,
            output='screen',
            emulate_tty=True,  # https://github.com/ros2/launch/issues/188
            parameters=[{'use_sim_time': use_sim_time},
                        {'autostart': autostart},
                        {'node_names': lifecycle_nodes}])

    start_map_server_cmd = Node(
            package='nav2_map_server',
            executable='map_server',
            name='filter_mask_server',
            namespace=namespace,
            output='screen',
            emulate_tty=True,  # https://github.com/ros2/launch/issues/188
            parameters=[configured_params])

    start_costmap_filter_info_server_cmd = Node(
            package='nav2_map_server',
            executable='costmap_filter_info_server',
            name='costmap_filter_info_server',
            namespace=namespace,
            output='screen',
            emulate_tty=True,  # https://github.com/ros2/launch/issues/188
            parameters=[configured_params])
    
    map_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[{'yaml_filename': map_path,
                     'frame_id': 'map'}],
    )

    nav_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory('nav2_bringup'), 'launch'),
         '/navigation_launch.py']),
         launch_arguments= {
                        'map': map_path,
                        'use_sim_time': 'false',
                        'params_file': nav2_params_path,
                        'autostart': 'true',
                        }.items()
      )
    ld = LaunchDescription()

    ld.add_action(convert_sens_type)
    
    ld.add_action(ekf_odom)
    ld.add_action(ekf_map)

    ld.add_action(rviz_node)
    ld.add_action(robot_state_publisher_node)
    ld.add_action(joint_state_publisher_node)
    ld.add_action(markers_node)

    ld.add_action(declare_namespace_cmd)
    ld.add_action(declare_use_sim_time_cmd)
    ld.add_action(declare_autostart_cmd)
    ld.add_action(declare_params_file_cmd)
    ld.add_action(declare_mask_yaml_file_cmd)

    ld.add_action(start_lifecycle_manager_cmd)
    ld.add_action(map_node)
    ld.add_action(start_map_server_cmd)
    ld.add_action(start_costmap_filter_info_server_cmd)
    ld.add_action(nav_launch)

    return ld