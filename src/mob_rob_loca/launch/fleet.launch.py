from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    package_name = 'mob_rob_loca'

    return LaunchDescription([
        launch_ros.actions.Node(
            package=package_name,
            executable='go_to_server',
            output='screen'
        ),
])
