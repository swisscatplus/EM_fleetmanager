import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


pkg_name = 'mob_rob_loca'

def generate_launch_description():
   rob_loca_dir = get_package_share_directory(pkg_name)
   map_path = os.path.join(rob_loca_dir, 'maps', 'circuit.yaml')
   nav2_params_path = os.path.join(rob_loca_dir, 'nav_params/nav_params.yaml')

   sensor_conv_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory(pkg_name), 'launch'),
         '/sensor.launch.py'])
      )
   rviz_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory(pkg_name), 'launch'),
         '/rviz.launch.py'])
      )
   ekf_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory(pkg_name), 'launch'),
         '/ekf.launch.py'])
      )
   maps_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory(pkg_name), 'launch'),
         '/maps.launch.py'])
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
   fleet_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory(pkg_name), 'launch'),
         '/fleet.launch.py'])
      )
   
   return LaunchDescription([
      sensor_conv_launch,
      ekf_launch,
      rviz_launch,
      maps_launch,
      nav_launch,
      fleet_launch,
   ])
