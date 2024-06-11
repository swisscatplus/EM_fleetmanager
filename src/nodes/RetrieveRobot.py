from nodes.CustomNode import CustomNode

import time

class GetAvailable(CustomNode):
    """
    This class is a node that represents the action of getting an available EM.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: CustomNode, dst: CustomNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        
        args["robot_id"] = self.get_avail()
        self.logger.debug(f"Appending {args["robot_id"]}")
        return 0, None, None
    
    def get_avail(self) -> str:
        """
        This method returns the id of the EM at the station.
        """
        self.logger.info("Looking for available EM")
        time.sleep(2)
        return "robot_1"
    
class GetAtStation(CustomNode):
    """
    This class is a node that represents the action of getting an EM located at a specific station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: CustomNode, dst: CustomNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:

        self.logger.info("executing GetAtStation...")
        args["robot_id"] = self.get_id_at(station=args["station_start"])
        self.logger.debug(f"Appending {args["robot_id"]}")
        return 0, None, None
    
    def get_id_at(self, station: str) -> str:
        """
        This method returns the id of the EM at the station.
        """

        self.logger.info(f"Looking for EM at {station}")
        time.sleep(2)
        return "robot_1"
    
