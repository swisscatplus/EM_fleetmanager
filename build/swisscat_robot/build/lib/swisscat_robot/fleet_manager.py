#!/usr/bin/env python3

import time
import os
import numpy as np
import configparser
from pathlib import Path
from munkres import Munkres
# Ros Libraries
import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory
# Submodules from package
from .submodules.single_agent_planner import compute_heuristics, a_star
from .submodules.cbs import CBSSolver
from .submodules.robot import Robot
from .submodules.point import Point
from .submodules.station import Station

package_share_directory = get_package_share_directory('swisscat_robot')
ini_file_path = os.path.join(package_share_directory, 'config', '../config/configrobots.ini')
circuit_file_path = os.path.join(package_share_directory, 'config', '../config/circuit_MAPF.txt')

VERBOSE = False
DIST_THRESH = 0.3
LOOP_FREQUENCY = 10  # Hz
LOOP_INTERVAL = 1.0 / LOOP_FREQUENCY


class FleetManager(Node):
    def __init__(self):
        super().__init__('fleet_manager')
        self.goals = []
        self.starts = []

        self.robots, self.stations = self.create_all_from_ini_file(ini_file_path)

        # init map
        self.my_map = self.import_mapf_instance(circuit_file_path)

        # generate the tasks
        tasks_to_do, next_tasks_to_do = self.task_generator(self.stations)

        # task allocation
        self.goals = self.task_allocation(self.stations, tasks_to_do, next_tasks_to_do, self.my_map)
        if VERBOSE:
            self.get_logger().info(str(self.goals))

        # Find paths
        self.starts = [robot.posGrid.get_coordinates() for robot in self.robots]
        cbs = CBSSolver(self.my_map, self.starts, self.goals)
        paths = cbs.find_solution('--disjoint')

        # Update paths
        for robot in self.robots:
            robot.path = paths[self.robots.index(robot)]

        # Filter the checkpoints to only keep changes in direction, initial and final positions in path
        all_change_dir = []
        all_change_dir.append(0)
        self.find_change_dir_idx()
        for robot in self.robots:
            all_change_dir.extend(robot.change_dir_idx)
            all_change_dir.append(len(robot.path) - 1)
        all_change_dir = np.unique(all_change_dir)
        for robot in self.robots:
            robot.path = [robot.path[i] for i in list(filter(lambda item: item < len(robot.path), all_change_dir))]
        self.get_logger().info(f"path {self.robots[0].path}")
        # Change frame MAPF 2 Gazebo (for path)
        for robot in self.robots:
            self.robots[self.robots.index(robot)].base_MAPF2Gazebo()

        self.get_logger().info(f"gazebo path {self.robots[0].path_gazebo}")

        # Get position (Gazebo frame)
        # qos_profile = QoSProfile(depth=10)
        # for i in range(5):
        # self.create_subscription(Odometry, f'/Robot{i + 1}/odom', self.robots[i].Position, qos_profile)

        # a checker
        #for robot in self.robots:
            #self.robots[self.robots.index(robot)].goalTemp = self.robots[self.robots.index(robot)].posMap

    def create_robots_from_ini_file(self, config):
        '''
        Load robot configuration parameters from ini file
        '''
        global_section = config['Global']
        number_robot = int(global_section['number_robot'])
        robots = []
        for i in range(1, number_robot + 1):
            robot_config = config['Robots'][f'robot{i}']
            x, y, station_id = map(int, robot_config.split(','))
            robot = Robot("Robot" + str(i), x, y, station_id)
            robots.append(robot)
        return robots

    def create_stations_from_ini_file(self, config):
        """
        Loads station configuration parameters from ini file
        """
        stations_list = []
        stations_config = config['Stations']['stations']
        station_configs = stations_config.split(';')
        for station_config in station_configs:
            name, x, y = station_config.split(',')
            station = Station(name.strip(), int(x), int(y))
            stations_list.append(station)
        return stations_list

    def create_all_from_ini_file(self, file_path):
        """
        Initializes robots and stations
        """
        config = configparser.ConfigParser()
        config.read(file_path)
        robots = self.create_robots_from_ini_file(config)
        stations = self.create_stations_from_ini_file(config)
        return robots, stations

    def main_loop(self):
        while rclpy.ok():
            start_time = time.time()
            try:
                self.get_logger().info("----------------------------------- Looping -----------------------------------")
                if self.is_system_ready():
                    self.get_logger().info("----------------------------------- Update system state-----------------------------------")
                    self.update_system_state()

                if self.is_mission_complete():
                    self.get_logger().info("----------------------------------- Mission complete -----------------------------------")
                    break

                self.check_checkpoint()
                self.send_checkpoint()
                self.spin_robots()

                self.control_loop_frequency(start_time)

            except Exception as e:
                self.get_logger().error(f"Error in main_loop: {str(e)}")

    def is_system_ready(self):
        """
        Checks if all robots are finished with their current task.
        """
        return self.all_robot_has_state('state_current_task', 0)

    def is_mission_complete(self):
        return self.all_robot_has_state('state_mission', 1)

    def any_robot_has_state(self, attribute, value):
        """
        Check if any robot has the given value for the specified attribute.
        """
        return any(getattr(robot, attribute) == value for robot in self.robots)

    def all_robot_has_state(self, attribute, value):
        """
        Check if all robot has the given value for the specified attribute.
        """
        return all(getattr(robot, attribute) == value for robot in self.robots)

    def update_system_state(self):
        """
        Updates the system's state which includes updating goals,
        converting robot coordinates, getting new start positions
        and computing paths for robots.
        """
        self.update_goal()

        # Convert robot positions from the Gazebo frame to the MAPF frame
        for robot in self.robots:
            robot.base_Gazebo2MAPF()

        # Update the start positions of robots
        self.starts = [robot.posGrid.get_coordinates() for robot in self.robots]

        # Compute and assign paths to robots
        self.compute_and_assign_paths_for_robots()

    def update_goal(self):
        """
        Updates goals for each robot. If a robot reaches its goal,
        it removes the goal from its list and sets a new goal.
        """
        for robot in self.robots:
            self.get_logger().debug(f'{robot.name} reached its goal')

            # If there are multiple goals left for the robot
            if len(robot.goal) > 1:
                robot.goal.pop(-1)  # Remove the last goal
                robot.state_current_task = 1
            else:
                # If only one goal is left, mission is considered complete
                robot.state_mission = 0

            # Update the goal list for the robot
            self.goals[robot.id] = robot.goal[-1].get_coordinates()
            self.get_logger().debug(f'New goal for {robot.name} is {robot.goal[-1].get_coordinates()}')

    def compute_and_assign_paths_for_robots(self):
        cbs = CBSSolver(self.my_map, self.starts, self.goals)
        paths = cbs.find_solution('--disjoint')

        all_change_dir = [0]
        self.find_change_dir_idx()
        for robot, path in zip(self.robots, paths):
            robot.path = path
            all_change_dir.extend(robot.change_dir_idx)
            all_change_dir.append(len(path) - 1)

        unique_change_dir = np.unique(all_change_dir)
        for robot in self.robots:
            robot.path = [robot.path[i] for i in
                          filter(lambda item: item < len(robot.path), unique_change_dir)]

        # Convert paths back to Gazebo frame for all robots
        for robot in self.robots:
            robot.base_MAPF2Gazebo()

    def check_checkpoint(self):
        """
        Check if each robot has reached its checkpoint.
        """
        for robot in self.robots:
            if robot.state_mission == 1:
                self.get_logger().info("CHECK_CHECKPOINT")
                # Check if the robot is ready to receive a new goal
                if robot.state_current_task == 1:
                    self.get_logger().info("SEND_GOAL")
                    robot.send_goal()

                # Calculate the distance to the goal
                distance_to_goal_x = abs(robot.posMap.x - robot.goalTemp.x)
                distance_to_goal_y = abs(robot.posMap.y - robot.goalTemp.y)

                # Log the distance if verbose mode is on
                #if VERBOSE:
                self.get_logger().debug(f"{robot.name} distance to goal X: {distance_to_goal_x}")
                self.get_logger().debug(f"{robot.name} distance to goal Y: {distance_to_goal_y}")

                # Check if the robot is within the checkpoint threshold
                if self.is_within_threshold(distance_to_goal_x, distance_to_goal_y):
                    #if VERBOSE:
                    self.get_logger().info(f"{robot.name} has reached the checkpoint and is moving to the next one.")

                    robot.state_checkpoint = 0

                    # Update task state if the robot has completed its path
                    if len(robot.path_gazebo) <= 1:
                        robot.state_current_task = 0

    def is_within_threshold(self, x_distance, y_distance):
        """
        Determine if the robot is within the checkpoint threshold.
        """
        return (x_distance < DIST_THRESH) and (y_distance < DIST_THRESH) and (min(x_distance, y_distance) < 0.3)

    def send_checkpoint(self):
        """
        Send the next checkpoint to each robot if all robots have reached their previous checkpoint.
        """

        if self.any_robot_has_state('state_checkpoint', 1):
            return

        # Update the path for each robot
        for robot in self.robots:
            if len(robot.path_gazebo) > 1:
                robot.path_gazebo.pop(0)

    def spin_robots(self):
        for robot in self.robots:
            rclpy.spin_once(robot)

    def control_loop_frequency(self, start_time):
        elapsed_time = time.time() - start_time
        sleep_duration = LOOP_INTERVAL - elapsed_time
        if sleep_duration > 0:
            time.sleep(sleep_duration)

    def import_mapf_instance(self, filename):
        '''
        MAP GENERATION (FOR A*)
        - input : text file representing the map
        - output: table containing free and occupied cells, respectively True and False
        '''
        f = open(filename, 'r')
        # first line: #rows #columns
        line = f.readline()
        rows, columns = [int(x) for x in line.split(' ')]
        rows = int(rows)
        columns = int(columns)
        # rows lines with the map
        my_map = []
        for r in range(rows):
            line = f.readline()
            my_map.append([])
            for cell in line:
                if cell == '@':
                    my_map[-1].append(True)
                elif cell == '.':
                    my_map[-1].append(False)
        if VERBOSE:
            self.get_logger().info('Map Generated')
        return my_map

    def task_generator(self, stations):
        '''
        TASK GENERATION: generate random tasks for the robots

        - input:  stations: 0: discovery (5,2) ; 1: omni (5,10) ; 2: synt (9,10) ; 3: sfc (0,10)
        - output: tasks_to_do is a list containing: [[Collection station(s)][Delivery station(s)]]

        example: [[0,3],[1,2]] consists in sending one robot to collect samples in station 0 and deliver them to station 1
        and another robot to collect samples in station 3 and deliver them to station 2
        '''
        # TODO: get tasks from a task generation manager at higher level

        # possible tasks:
        # tasks = [[[0,3],[1,2]], [[1,2],[0,3]], [[1,0],[3,2]], [[0,3, 1],[1,2, 0]], [[3, 1,2],[1, 0,3]], [[2, 1,0],[0,3,2]], [[3, 2, 1,0],[1,0,3,2]]]
        # tasks_to_do = random.choice(tasks) # select a random set of tasks

        tasks_to_do = [[2], [1]]  # [[0],[3]] #[[2],[1]]#[[2,0],[1, 3]] # values for testing

        return tasks_to_do[0], tasks_to_do[1]

    def task_allocation(self, stations, tasks_to_do, next_tasks_to_do, my_map):
        '''
        Allocate the tasks to the robots by minimizing the total distance travelled by the robots
        - input : list of station, list of tasks: collecting stations in task_to_do, delivery station in next_tasks_to_do
        - output: list of goals allocated to each robot, updates state_goal and state_mission if robots were assigned tasks
        '''

        starts_robots = [robot.posGrid.get_coordinates() for robot in self.robots]
        goals_allocation = []
        cost_matrix = np.zeros((len(tasks_to_do), len(self.robots)))

        # 1. OPTIMIZATION - Hungarian algorithm

        # update goals_allocation with the collection stations to reach
        for i in range(0, len(tasks_to_do)):
            goals_allocation.append(stations[tasks_to_do[i]].posGrid)

        heuristics = []
        for goal in goals_allocation:
            heuristics.append(compute_heuristics(my_map, goal.get_coordinates()))

        # compute the cost matrix
        for i in range(0, len(tasks_to_do)):
            for j in range(0, len(self.robots)):
                path = a_star(my_map, starts_robots[j], goals_allocation[i].get_coordinates(), heuristics[i], 0, [])
                cost_matrix[i][j] = len(path)

        # Hungarian algorithm
        m = Munkres()
        indexes = m.compute(cost_matrix)  # it outputs a list of assignments (task, robot)

        if VERBOSE:
            self.get_logger().info(str(indexes))

        # 2. Update goals for the robots performing a task
        for j in range(0, len(indexes)):
            robot_index = indexes[j][1]
            self.robots[robot_index].goal.append(stations[next_tasks_to_do[indexes[j][0]]].posGrid)
            self.robots[robot_index].goal.append(stations[tasks_to_do[indexes[j][0]]].posGrid)
            self.robots[robot_index].state_current_task = 1
            self.robots[robot_index].state_mission = 1  # update the mission state
            if VERBOSE:
                self.get_logger().info(self.robots[robot_index].name + ' is taking the task ' + str(j))

        # 3. Update goals_allocation list containing the goals for each robot
        goals_allocation = [robot.goal[-1].get_coordinates() for robot in self.robots]
        return goals_allocation

    def find_change_dir_idx(self):
        '''
        Will store the first and last nodes in paths as well as all nodes at which there is a change in orientation
        The goal of this function is to avoid having to send all nodes to the robot
        - input: path in MAPF frame
        '''
        for robot in self.robots:
            for i in range(len(robot.path) - 2):
                # if two consecutive segments are perpendicular or if the robot has to move back
                if np.dot(np.array([robot.path[i + 1][0] - robot.path[i][0], robot.path[i + 1][1] - robot.path[i][1]]),
                          np.array([robot.path[i + 2][0] - robot.path[i + 1][0],
                                    robot.path[i + 2][1] - robot.path[i + 1][1]])) <= 0:
                    # Store the indices of the changes of direction along the path
                    robot.change_dir_idx.append(i + 1)

    def check_boundaries(self, X, Y, my_map):
        '''
        Check if a point is inside  the map
        '''
        if X < len(my_map) and Y < len(my_map)[0] and X > 0 and Y > 0:
            return True
        else:
            return False


def main(args=None):
    rclpy.init(args=args)
    fleet_manager_node = FleetManager()
    fleet_manager_node.main_loop()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
