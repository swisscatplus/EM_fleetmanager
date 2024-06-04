from task_scheduler.nodes.base import BaseNode
import time

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
        self.move_to(args)
        # payload = {"robot_id": robot_id, "station": args["station_end"]}
        self.logger.info("Moving available EM to station")
        return 0, None, None
    
    def move_to(self, robot_id):
        """
        This method returns the error id of the service, 0 if success.
        """
        time.sleep(2)
        return 0
    
