from geometry_msgs.msg import PoseStamped
from .socket_client import SocketClient
import logging
from tf_transformations import quaternion_from_euler
import configparser
import rclpy
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
        self.goal_station = goal_station

        self.port_in_server = config.get(goal_station, 'port')
        self.cam_server = config.get('Server', 'cam_ip')
        self.goal_pose = PoseStamped()
        self.status = None

        self.set_ros_goal_pose() 
        self.calibrate_pos()

        print('port_in_server: ', self.port_in_server)
        print('goal_pose: ', self.goal_pose.pose)
        print('------------------')

    def set_ros_goal_pose(self):
        """
        Creates a PoseStamped object representing the goal pose of the station.

        """
        # self.goal_pose = PoseStamped()
        self.goal_pose.header.frame_id = 'map'
        self.goal_pose.pose.position.x = float(config.get(self.goal_station, 'pos_x'))
        self.goal_pose.pose.position.y = float(config.get(self.goal_station, 'pos_y'))

        yaw_rad = float(config.get(self.goal_station, 'yaw'))
        quat = quaternion_from_euler(0.0, 0.0, yaw_rad)
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

# def main():
#     rclpy.init()
    
#     station_request = 'NMR' # virtual request

#     goal_man = Goal_Manager(station_request)

#     exit(0)

# if __name__ == '__main__':
#     main()

