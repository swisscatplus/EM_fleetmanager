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
from submodules.socket_client import SocketClient
import logging
from tf_transformations import quaternion_from_euler
import rclpy
import configparser

# Create a ConfigParser object
config = configparser.ConfigParser()

# Specify the path to the config file
config_file = '/home/coderey/ros2_ws/src/mob_rob_loca/config/robot_params.ini'

# Read the config file
config.read(config_file)


"""
Sequencing of robot actions
"""

class Goal_Manager:
    def __init__(self, goal_station):
        # self.station_params = stations[goal_name]
        self.goal_pose_rec = [0.0, 0.0, 0.0]
        self.goal_pose_rec[0] = float(config.get(goal_station, 'pos_x'))
        self.goal_pose_rec[1] = float(config.get(goal_station, 'pos_y'))
        self.goal_pose_rec[2] = float(config.get(goal_station, 'yaw'))

        self.port_in_server = config.get(goal_station, 'port')
        self.cam_server = config.get('Server', 'cam_ip')
        self.goal_pose = PoseStamped()
        self.status = None

        self.set_ros_goal_pose() 
        self.calibrate_pos()

        print('goal_pose_rec: ', self.goal_pose_rec)
        print('port_in_server: ', self.port_in_server)
        print('goal_pose: ', self.goal_pose.pose)
        print('------------------')

    def set_ros_goal_pose(self):
        """
        Creates a PoseStamped object representing the goal pose of the station.

        """
        # self.goal_pose = PoseStamped()
        self.goal_pose.header.frame_id = 'map'
        self.goal_pose.pose.position.x = self.goal_pose_rec[0]
        self.goal_pose.pose.position.y = self.goal_pose_rec[1]

        quat = quaternion_from_euler(0.0, 0.0, self.goal_pose_rec[2])
        self.goal_pose.pose.orientation.z = quat[2]
        self.goal_pose.pose.orientation.w = quat[3]  

    def calibrate_pos(self):
        cli = SocketClient("PC_Yannis", self.cam_server, int(self.port_in_server))
        logging.info('Connecting to server for calibration')
        cli.connect()
        logging.info('Sending calibration request')
        cli.send_data("Calibrate")
        received_data = cli.receive_data()
        logging.info(received_data)  


def main():
    rclpy.init()
    
    station_request = 'NMR' # virtual request

    goal_man = Goal_Manager(station_request)

    exit(0)

if __name__ == '__main__':
    main()
