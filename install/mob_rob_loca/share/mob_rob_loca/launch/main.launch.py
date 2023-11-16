import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import GroupAction
from launch_ros.actions import PushRosNamespace


def generate_launch_description():

   main_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory('mob_rob_loca'), 'launch'),
         '/localization.launch.py'])
      )
   
   robot_1_launch = GroupAction(
     actions=[
         PushRosNamespace('robot1'),
         main_launch,
      ]
   )

   return LaunchDescription([
      robot_1_launch
   ])
