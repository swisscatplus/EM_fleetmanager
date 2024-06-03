from task_scheduler.nodes.base import BaseNode


class GoToStation(BaseNode):
    """
    This class is a node that represents the action of moving the robot to a station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        payload = {"source_station": src.id, "destination_station": None}
        self.logger.info("Moving available EM to station {dst.id}")
        return 0, None, None
    
class StationToStation(BaseNode):
    """
    This class is a node that represents the action of moving the robot from a station to a station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        payload = {"source_station": src.id, "destination_station": dst.id}
        self.logger.info("Moving EM from station {src.id} to station {dst.id}")
        return 0, None, None
    
