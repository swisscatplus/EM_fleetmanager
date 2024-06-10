from nodes.CustomNode import CustomNode

import time

class GetAvailable(CustomNode):
    """
    This class is a node that represents the action of getting an available EM.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)
        self.robot_id = None

    def _execute(self, src: CustomNode, dst: CustomNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        payload = {"station": None}
        self.logger.debug("Station received")
        self.logger.debug(args) #args["station1"], args["station2"] to access
        self.logger.info("Looking for available EM")
        return 0, None, None
    
class GetAtStation(CustomNode):
    """
    This class is a node that represents the action of getting an EM located at a specific station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)

    def _execute(self, src: CustomNode, dst: CustomNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        # payload = {"station": args["station_start"]}
        self.logger.info("Looking for EM at station")
        robot_id = self.get_id_at(station=args["station_start"])
        # payload = {"robot_id": robot_id, statioargs["station_start"]}
        # self.logger.info(args["station_start"])
        self.logger.debug(dst.id)
        return 0, None, None
    
    def get_id_at(self, station: str) -> str:
        """
        This method returns the id of the EM at the station.
        """
        time.sleep(2)
        return "robot_1"
    
