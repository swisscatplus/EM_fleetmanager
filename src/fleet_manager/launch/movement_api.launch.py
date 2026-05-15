#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


PACKAGE_NAME = 'fleet_manager'


def generate_launch_description():
    routes_config = LaunchConfiguration('routes_config')
    stations_config = LaunchConfiguration('stations_config')
    roads_config = LaunchConfiguration('roads_config')
    host = LaunchConfiguration('host')
    port = LaunchConfiguration('port')

    default_routes_config = PathJoinSubstitution([
        FindPackageShare(PACKAGE_NAME),
        'config',
        'routes.yaml',
    ])
    default_stations_config = PathJoinSubstitution([
        FindPackageShare(PACKAGE_NAME),
        'config',
        'stations.yaml',
    ])
    default_roads_config = PathJoinSubstitution([
        FindPackageShare(PACKAGE_NAME),
        'config',
        'roads.yaml',
    ])

    api_node = Node(
        package=PACKAGE_NAME,
        executable='rest_api',
        name='fleet_manager_rest_api',
        output='screen',
        arguments=[
            '--config',
            routes_config,
            '--stations-config',
            stations_config,
            '--roads-config',
            roads_config,
            '--host',
            host,
            '--port',
            port,
        ],
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'routes_config',
            default_value=default_routes_config,
            description='Fleet Manager station-pair to path-id route config.',
        ),
        DeclareLaunchArgument(
            'stations_config',
            default_value=default_stations_config,
            description='Fleet Manager station geometry config.',
        ),
        DeclareLaunchArgument(
            'roads_config',
            default_value=default_roads_config,
            description='Fleet Manager road geometry config.',
        ),
        DeclareLaunchArgument(
            'host',
            default_value='0.0.0.0',
            description='REST API bind address.',
        ),
        DeclareLaunchArgument(
            'port',
            default_value='8000',
            description='REST API bind port.',
        ),
        api_node,
    ])
