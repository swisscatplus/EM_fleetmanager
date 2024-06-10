from nodes.CustomNode import CustomNode
import subprocess
import re
import ast

class MoveToStation(CustomNode):
    """
    This class is a node that represents the action of moving the robot to a station.
    """
    def __init__(self, _id: str, name: str) -> None:
        super().__init__(_id, name)
        self.process = subprocess.Popen(['bash'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        #source installation
        self.write_cmd('source /opt/ros/humble/setup.bash')
        self.write_cmd('source install/setup.bash')

        self.srv_received = False
        self.result_id = None
        self.cmpt = 0

    def _execute(self, src: CustomNode, dst: CustomNode, task_id: str, args: dict[str, any] = None) -> tuple[
        int, str | None, str | None]:
        self.logger.debug('Arguments:')
        self.logger.debug(args['station_end'])
        self.logger.info("Moving available EM to station")
        robot_id = src.get_id_at('station')
        station = args['station_end']
        result = self.move_to(robot_id, station) #self.move_to(args)
        self.logger.info(f"Robot moved to station with result {result}")
        return 0, None, None
    
    def write_cmd(self, cmd):
        self.process.stdin.write(f"{cmd}\n")
        self.process.stdin.flush()
    
    # def shutdown(self):
        # self.process.terminate()

    def get_value_from_response(self, response_string: str, target_key: str) -> int:
        """
        Extracts the value associated with the target_key from the response string of the target_srv.

        :param response_string: The response string containing the key-value pair.
        :param target_srv: The specific service response type to look for after 'srv.'.
        :param target_key: The key for which to extract the value.
        :return: The value associated with the target_key as an integer.
        """
        # Use regex to find the specific service response and extract the content inside the parenthesis
        target_srv = 'GoToStation_Response'
        pattern = rf'{re.escape(target_srv)}\((.*)\)'
        match = re.search(pattern, response_string)
        if not match:
            raise ValueError(f"{target_srv} not found in the response string")

        # Extract the content inside the parenthesis and parse it as a dictionary
        content = match.group(1).split('=')[1].strip() # works just bcs this service returns one argument
        self.logger.debug(f"Content: {content}")

        return int(content)
    
    def move_to(self, robot_id, station) -> int:
        """
        This method returns the error id of the service, 0 if success.
        """
        #calls client to move robot to station
        robot_id = "robot_id"
        source = "source /opt/ros/humble/setup.bash"
        source2 = "source install/setup.bash"
        cmd = f'ros2 service call /go_to_station mob_rob_loca_msgs/srv/GoToStation "{{station: {station}, {robot_id}: 2}}"'
        self.logger.debug(f"Command: {cmd}")
        full_command = f"bash -c '{source} && {source2} && {cmd}'"
        # self.process.stdin.write(f"{cmd}\n")
        # self.process.stdin.flush()
        result = subprocess.run(full_command, shell=True, capture_output=True, text=True)
        # while not self.srv_received:
            # output = self.process.stdout.readline().strip()
            # self.logger.debug(f"Received: {output}")
            # if output == 'response:': # formatted answer, the service reply is: response:\n mob_rob_loca_msgs...
                # response = self.process.stdout.readline().strip()#.strip('.')[2] # mob_rob_loca_msgs.srv.GoToStation_Response(result_id=0)
                # self.result_id = self.get_value_from_response(response, 'result_id')
                # self.logger.debug(f"Response: {self.result_id}")
                # self.srv_received = True
            # else:
                # self.cmpt += 1

            # if self.cmpt == 100:
                # self.logger.error("Service response not received")
                # break

        return result.returncode

