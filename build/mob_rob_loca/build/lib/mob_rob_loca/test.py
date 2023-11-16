# from geometry_msgs.msg import PoseStamped
from enum import Enum

class Station:
    def __init__(self, posX, posY, orientationZ, orientationW):
        """
        Initializes a Station object with a given position and orientation.

        Args:
        - posX: float, the x-coordinate of the station's position
        - posY: float, the y-coordinate of the station's position
        - orientationZ: float, the z-coordinate of the station's orientation
        - orientationW: float, the w-coordinate of the station's orientation
        """
        self.position = {
            "x": posX,
            "y": posY,
            "z": 0.0
        }
        self.orientation = {
            "x": 0.0,
            "y": 0.0,
            "z": orientationZ,
            "w": orientationW
        }
        self.is_occupied = False # True if a robot is currently on the station
        
    
class Robot:
    Type = {
        "transporter": 0,
        "rescuer": 1,
        "cleaner": 2
    }
    
    State = {
        "standby": 0,
        "moving": 1,
        "on_station": 2,
        "returning_home": 3,
        "error": 4
    }

    def __init__(self, robot_type=Type["transporter"], state=State["standby"], goals=[], empty=True):
        self.robot_type = robot_type
        self.state = state
        self.goal_poses = goals
        self.is_empty = empty #  False if the robot carries a load. No meaning for the cleaner type
        self.sample_ID = 0 # corresponds to the ID number of the actual sample being carried, specific to the transporter type, set to 0 for other types
        # self.current_pose = current_pose not sure if needed 
        # self.current_goal = None # not sure if needed
        # self.battery_level = 90.0 # not sure if needed                                                                                                                                                                                                    
        # self.lights = False # if we put lights, can be specified here whether we want to enable them or not, again not sure if needed

def main(args=None):
    robot_1 = Robot()

if __name__ == '__main__':
    main()