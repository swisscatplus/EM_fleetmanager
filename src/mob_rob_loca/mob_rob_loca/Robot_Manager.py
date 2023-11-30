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

from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from tf_transformations import quaternion_from_euler
import rclpy
from rclpy.duration import Duration
from submodules.RobotPlatform import Station, Robot
from submodules.Goal_Manager import Goal_Manager
from submodules.socket_client import SocketClient
import time

"""
Basic navigation demo to go to waypoints.
"""

def main():
    rclpy.init()
    
    station_request = 'NMR' # virtual request

    goal_man = Goal_Manager(station_request)

    navigator = BasicNavigator()

    navigator._waitForNodeToActivate('bt_navigator')

    navigator.goToPose(goal_man.goal_pose)

    j = 0

    while not navigator.isTaskComplete():
        # Do something with the feedback
        j = j + 1
        feedback = navigator.getFeedback()
        if feedback and j % 5 == 0:
            print(feedback)

    # Do something depending on the return code
    result = navigator.getResult()
    if result == TaskResult.SUCCEEDED:
        print('Goal succeeded!')
    elif result == TaskResult.CANCELED:
        print('Goal was canceled! Waiting for new orders!')
    elif result == TaskResult.FAILED:
        print('Goal failed, returning home!')
    else:
        print('Goal has an invalid return status!')

        # Here implement actions to do before going to next goal

    navigator.lifecycleShutdown()

    exit(0)


if __name__ == '__main__':
    main()
