from glas.nodes.base import BaseNode
import subprocess
import time
import re

class MoveToStation(BaseNode):
    """
    This class is a node that represents the action of moving the robot to a station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)
        self.process = subprocess.Popen(['bash'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        self.target_srv = 'GoToStation' + '_Response'
        self.srv_received = False
        self.result_id = None
        self.cmpt = 0
        

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:

        self.logger.info("Executing MoveToStation...")
        robot_id = args["robot_id"]
        station = args['station_end']
        result = self.move_to(robot_id, station) #self.move_to(args)
        
        self.logger.info(f"Task id: {task_id}")
        self.logger.info(f"Robot {robot_id} moved to {station} with result {result}")
        return result, None, None
    
    def move_to(self, robot_id, station) -> int:
        """
        This method returns the error id of the service, 0 if success.
        """
        self.logger.info("Moving available EM to station")

        robot_id = "robot_id"
        source = "source /opt/ros/humble/setup.bash"
        source2 = "source install/setup.bash"
        cmd = f'ros2 service call /go_to_station mob_rob_loca_msgs/srv/GoToStation "{{station: {station}, robot_id: {robot_id}}}"'

        self.logger.debug(f"Command: {cmd}")
        full_command = f"bash -c '{source} && {source2} && {cmd}'"
        
        result = subprocess.run(full_command, shell=True, capture_output=True, text=True)
        self.logger.debug(f"Result: {result}, and code: {result.returncode}")

        out = result.stdout.split("\n")

        resp_idx = out.index("response:")
        
        pattern = re.compile(r"result_id=(\d)")
        err_code = pattern.search(out[resp_idx+1])

        print(err_code.group(1))
        if err_code:
            return int(err_code.group(1))

        return 0

