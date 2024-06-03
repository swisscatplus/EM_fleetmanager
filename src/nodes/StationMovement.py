from task_scheduler.nodes.base import BaseNode


class GoToStation(BaseNode):
    """
    This class is a node that represents the action of moving the robot to a station.
    """
    def __init__(self, _id: str, name: str, ip: str, execution_args: list[dict]) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.info("Moving Available EM to Desired Station")
        return 0, None, None
    
class StationToStation(BaseNode):
    """
    This class is a node that represents the action of moving the robot from a station to a station.
    """
    def __init__(self, _id: str, name: str, ip: str, execution_args: list[dict]) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.info("Moving EM at Station to Other Desired Station")
        return 0, None, None
    
