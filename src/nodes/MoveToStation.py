from task_scheduler.nodes.base import BaseNode
# from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
# from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
# from mob_rob_loca.mob_rob_loca.nav_manager import move_robot_to_station
# import rclpy
import time
import subprocess

class MoveToStation(BaseNode):
    """
    This class is a node that represents the action of moving the robot to a station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.debug('Arguments:')
        self.logger.debug(task_id)
        self.logger.info("Moving available EM to station")
        robot_id = src.get_id_at('station')
        result = self.move_to(robot_id) #self.move_to(args)
        self.logger.info(f"Robot moved to station with result {result}")
        # payload = {"robot_id": robot_id, "station": args["station_end"]}
        return 0, None, None
    
    def move_to(self, robot_id):
        """
        This method returns the error id of the service, 0 if success.
        """
        #call client to move robot to station
        # time.sleep(2)
        try:
            source = "source /opt/ros/humble/setup.bash"
            source2 = "source install/setup.bash"
            cmd = "ros2 run mob_rob_loca client 'a' 'b'"
            full_command = f"bash -c '{source} && {source2} && {cmd}'"
            result = subprocess.run(full_command, shell=True)

            # result = subprocess.run(['ros2'], check=True)#, 'run', 'mob_rob_loca', 'client', 'a', 'b'], check=True)
            return result.returncode
        except subprocess.CalledProcessError as e:
            self.logger.error(f"Navigation failed: {e}")
            return e.returncode
    
