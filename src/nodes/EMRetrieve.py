from task_scheduler.nodes.base import BaseNode


class GetAvailableEM(BaseNode):
    """
    This class is a node that represents the action of getting an available EM.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        payload = {"desired_station": None}
        self.logger.info("Looking for available EM")
        return 0, None, None
    
class GetStationEM(BaseNode):
    """
    This class is a node that represents the action of getting an EM located at a specific station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        payload = {"desired_station": src.id}
        self.logger.info("Looking for EM at station {src.id}")
        return 0, None, None
    
