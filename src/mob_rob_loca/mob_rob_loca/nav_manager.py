#! /usr/bin/env python3
# Copyright 2021 Samsung Research America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
from launch_ros.substitutions import FindPackageShare
from .submodules.Goal_Manager import Goal_Manager
from mob_rob_loca.submodules.utils import get_config_yaml
import logging
import os
import yaml

"""
Basic navigation demo to go to waypoints.
"""
package_name = 'mob_rob_loca'
params_path = '/home/coderey/EM_navigation/src/mob_rob_loca/config/stations.yaml' #'config/rpi_cam_on_robot.yaml' 

logger = logging.getLogger('ROBOT_MANAGER')

pkg_share = FindPackageShare(package=package_name).find(package_name)
config_file_path = os.path.join(pkg_share, params_path)

# cam_config = yaml.load(open('config/rpi_cam_on_robot.yaml'), Loader=yaml.FullLoader)
config = get_config_yaml(config_file_path)

def move_robot_to_station():
    rclpy.init()
    navigator = BasicNavigator()
    navigator._waitForNodeToActivate('bt_navigator')
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.pose.position.x = 4.452
    goal_pose.pose.position.y = 7.5
    print('goal_pose: x=%f, y=%f', goal_pose.pose.position.x, goal_pose.pose.position.y)
    navigator.goToPose(goal_pose)
    
    result =  0 #navigator.getResult()
    if result == TaskResult.SUCCEEDED:
        print('Arrived at Camera Station!')
        print('Goal succeeded!')
    elif result == TaskResult.CANCELED:
        print('Goal was canceled! Waiting for new orders!')
    elif result == TaskResult.FAILED:
        print('Goal failed, returning home!')
    else:
        print('Goal has an invalid return status!')

    rclpy.shutdown()
    return result

def main():
    move_robot_to_station()


if __name__ == '__main__':
    main()