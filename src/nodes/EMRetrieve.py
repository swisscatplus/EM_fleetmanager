from task_scheduler.nodes.base import BaseNode


class GetAvailableEM(BaseNode):
    """
    This class is a node that represents the action of getting an available EM.
    """
    def __init__(self, _id: str, name: str, ip: str, execution_args: list[dict]) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.info("Looking for available EM")
        return 0, None, None
    
class GetStationEM(BaseNode):
    """
    This class is a node that represents the action of getting an EM located at a station.
    """
    def __init__(self, _id: str, name: str, ip: str, execution_args: list[dict]) -> None:
        super().__init__(_id, name)

    def _execute(self, src: BaseNode, dst: BaseNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.info("Looking for Station EM")
        return 0, None, None
    
