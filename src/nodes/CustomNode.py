from glas.nodes.base import BaseNode
import subprocess

class CustomNode(BaseNode):
    """
    This class is a node that represents the action of moving the robot to a station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)
        self.process = subprocess.Popen(['bash'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        #source ros2 installation
        self.write_cmd('source /opt/ros/humble/setup.bash')
        self.write_cmd('source install/setup.bash')

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.debug('Arguments:')
        self.logger.debug(task_id)
        self.logger.info("Moving available EM to station")
        robot_id = src.get_id_at('station')
        result = self.move_to(robot_id) #self.move_to(args)
        self.logger.info(f"Robot moved to station with result {result}")
        return 0, None, None
    
    def write_cmd(self, cmd):
        self.process.stdin.write(f"{cmd}\n")
        self.process.stdin.flush()
    
    def shutdown(self):
        self.process.terminate()

