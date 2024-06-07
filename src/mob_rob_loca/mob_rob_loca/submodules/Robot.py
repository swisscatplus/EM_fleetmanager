from geometry_msgs.msg import PoseStamped
from enum import Enum

BATTERY_THRESHOLD = 30

class RobotType(Enum):
        TRANSPORTER = 0
        RESCUER = 1 
        CLEANER = 2

class Robot:
    def __init__(self, name_id: str, is_operational: bool, ) -> None:
        self.name_id = name_id
        self.is_operational = is_operational # to be true if the robot can be used, false if needs maintenance
        self.pose = None
        self.is_occupied = False
        self.battery_level = 100 #%

    def __repr__(self) -> str:
         return f"{self.name_id} - {self.robot_type}"
         
    def update_pose(self, pose: PoseStamped) -> None:
        self.pose = pose

    def check_availability(self, station_name: str) -> bool:
        if self.battery_level < BATTERY_THRESHOLD:
            return False
        return not self.is_occupied and self.is_operational
    
class EM(Robot):
    def __init__(self, name_id: str, is_operational: bool) -> None:
        super().__init__(name_id, is_operational)
        # self.info(f"Initialized EM {name_id}")
        self.robot_type = RobotType.TRANSPORTER
        self.task_id = None # defines if the robot has a task assigned or not, hence if it's available or not