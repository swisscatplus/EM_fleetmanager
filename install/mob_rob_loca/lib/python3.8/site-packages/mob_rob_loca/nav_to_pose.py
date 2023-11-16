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
#
# Modified by AutomaticAddison.com

import time  # Time library
from enum import Enum
from geometry_msgs.msg import PoseStamped # Pose with ref frame and timestamp
from rclpy.duration import Duration # Handles time for ROS 2
import rclpy # Python client library for ROS 2
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult

'''
Navigates a robot from an initial pose to a goal pose.
'''

class Stations(Enum):
    OMNI = {
        "position": {
            "x": 2.0,
            "y": 0.53,
            "z": 0.0
        },
        "orientation": {
            "x": 0.0,
            "y": 0.0,
            "z": 0.0,
            "w": 1.0
        }
    }
    
    NMR = {
        "position": {
            "x": 2.0,
            "y": 0.0,
            "z": 0.0
        },
        "orientation": {
            "x": 0.0,
            "y": 0.0,
            "z": 0.0,
            "w": 1.0
        }
    }

# Function to create a goal_pose from a Stations enum
def create_goal_pose(station=Stations.OMNI):

    if station in Stations:
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        pose_data = station.value
        goal_pose.pose.position.x = pose_data["position"]["x"]
        goal_pose.pose.position.y = pose_data["position"]["y"]
        goal_pose.pose.position.z = pose_data["position"]["z"]
        goal_pose.pose.orientation.x = pose_data["orientation"]["x"]
        goal_pose.pose.orientation.y = pose_data["orientation"]["y"]
        goal_pose.pose.orientation.z = pose_data["orientation"]["z"]
        goal_pose.pose.orientation.w = pose_data["orientation"]["w"]
        return goal_pose
    
    else:
        raise ValueError("Invalid station provided")
    
def main():

  # Start the ROS 2 Python Client Library
  rclpy.init()

  # Launch the ROS 2 Navigation Stack
  navigator = BasicNavigator()
 
  # Activate navigation, if not autostarted. This should be called after setInitialPose()
  # or this will initialize at the origin of the map and update the costmap with bogus readings.
  # If autostart, you should `waitUntilNav2Active()` instead.
  # navigator.lifecycleStartup()

  # Wait for navigation to fully activate. Use this line if autostart is set to true.
  #navigator.waitUntilNav2Active()
  navigator._waitForNodeToActivate('bt_navigator') # don't use waitUntilNav2Active() because amcl is not used to get the localization of the robot

  goal_station = create_goal_pose(Stations.OMNI)

  while True:
        # Go to the goal pose in infinite loop, oscillates between OMNI and NMR
        navigator.goToPose(goal_station)
        navigator.goThroughPoses
        i = 0

        # Keep doing stuff as long as the robot is moving towards the goal
        while not navigator.isTaskComplete():
            ################################################
            #
            # Implement some code here for your application!
            #
            ################################################

            # Do something with the feedback
            i = i + 1
            feedback = navigator.getFeedback()
            if feedback and i % 5 == 0:
                print('Distance remaining: ' + '{:.2f}'.format(
                    feedback.distance_remaining) + ' meters.')

            # Some navigation timeout to demo cancellation
            if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                navigator.cancelNav()


        # Do something depending on the return code
        result = navigator.getResult()
        if result == TaskResult.SUCCEEDED:
            print('Goal succeeded!, going to next goal')
            # changes goal
            if goal_station.pose.position.y == Stations.OMNI.value["position"]["y"]:
                goal_station = create_goal_pose(Stations.NMR)
            else:
                goal_station = create_goal_pose(Stations.OMNI)
        elif result == TaskResult.CANCELED:
            print('Goal was canceled!, resetting goal after sleep of 5 seconds')
        elif result == TaskResult.FAILED:
            print('Goal was failed!, resetting goal after sleep of 5 seconds')
            time.sleep(5)
        else:
            print('Goal has an invalid return status!')   

  # Shut down the ROS 2 Navigation Stack
  navigator.lifecycleShutdown()

  exit(0)

if __name__ == '__main__':
  main()