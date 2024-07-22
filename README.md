<br />
<div align="center">
  <a href="https://github.com/swisscatplus/task-scheduler">
    <img src="https://images.squarespace-cdn.com/content/v1/6012a0a1f4c67c587a8eff67/d7731755-2fa3-4548-bf1e-5a25182d67ae/Combined+Logo+CAT-ETH-EPFL+%282%29.png?format=1500w" alt="Logo" height="80">
  </a>

  <h1 align="center"> EM_fleetmanager - Autonomous navigation and control of a mobile robot using Nav2 and GLAS architecture </h1>

</div>

This repository provides the code to fuse sensors using an Extended Kalman filter and uses the outputted position to control a mobile robot using [Nav2](https://github.com/ros-navigation/navigation2). The latter is responsible for transporting chemical vials between stations inside the laboratory. Moreover, the project fits into the framework of the schedulers from the SwissCat+ laboratory as it uses the [GLAS](https://github.com/swisscatplus/glas) scheduler to communicate with the higher-level scheduler: the Robot Scheduler. It is designed to work jointly with a mobile robot having [this code](https://github.com/swisscatplus/EM_onrobot) embedded and running.

## Requirements
  - Ubuntu 22.04
  - ROS2 Humble
  
## Table of Contents
1. [Description](#description)<br>
2. [How to build](#how-to-build)<br>
3. [How to use](#how-to-use)<br>
4. [ROS2 interfaces](#ros2-interfaces)<br>
5. [To improve](#to-improve)

## Description
When running the main launch file, the program will subscribe to the four output topics of the mobile robot, described [here](https://github.com/swisscatplus/EM_onrobot), convert the left and right ticks into an odometry topic, wheel/odom. The IMU, odometry and camera position data will then be fused inside an EKF filter, using the [robot_localization package](https://index.ros.org/p/robot_localization/). This results in outputting the topic odometry/global, a much more reliable and stable position, which will then be used for the navigation tasks. At the moment, these are performed using [Nav2](https://github.com/ros-navigation/navigation2), but the goal is to detach from this package to have more control over the algorithms, as Nav2 provides little adaptability and its behaviour is sometimes unpredictable. In the framework of the SwissCat+ laboratory, navigation is needed to move the robot around stations where it'd be transporting chemical vials. The implemented GLAS architecture links this structure to the Robot Scheduler and provides workflows which can be called and executed autonomously. The task requests can be sent from Postman, an API platform, to mimic the Robot Scheduler behaviour.

<details>
<summary> Show detailed description</summary>

### Sensor fusion
To achieve sensor fusion, the topics must have compatible types and a configuration file has to be properly set, which includes defining the covariance matrices. The configuration file implemented is [here](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/config/ekf_em.yaml), and all the information about its configuration is described in the comments of the former [file](https://github.com/cra-ros-pkg/robot_localization/blob/ros2/params/ekf.yaml). In our case, we apply the EKF filter twice, once for the relative localisation data and once for the absolute one. This also allows us to have the transforms automatically defined  as the `publish_tf` boolean is enabled. The relative pose includes the IMU and the odometry data, which are thus fused into the `odometry/filtered` topic, and then fused again with the camera position data as part of the absolute data pose. 

### Navigation 2
Similar to the Kalman module, a [configuration file](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/params/nav_params.yaml) defines the navigation tools employed: the main components on which a focus will be made are the planner, controller as well as costmap filter. The structure of Nav2 can be observed in the following figure.

<p align="center">
  <img width="493" alt="nav2_global" src="https://github.com/swisscatplus/EM_fleetmanager/assets/102654647/04572848-4494-440f-b763-253a09dfc50f">
</p>

For the planner, an A* is used as no specific planner is needed to plan the path for one robot. It will need to be changed in the future to account for the other mobile robots and avoid them. As the robot can rotate on itself, the primary controller employed, named rotary shim controller, privileges this behaviour. If the angle to the path is lower than a certain tolerance, the control to follow the path then switches to the default Nav2 controller, which is a [Dynamic-Window Approach controller](https://github.com/ros-navigation/navigation2/blob/main/nav2_dwb_controller/README.md). To include the static obstacles, meaning the walls of the track, a costmap filter was defined. It's simply a PNG map with black pixels where the walls are. This was the only option to provide the obstacle positions, as the robot lacks embedded sensors to detect near obstacles, such as a lidar. The map was then inflated to account for the robot radius with a safety margin. To make it work with the other maps, a [configuration file](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/params/keepout_params.yaml) also had to be implemented with the basic information required for the image. One of the main challenges of this implementation was to match the required circuit resolution, as the stations need to be met within a precise tolerance (<2cm, <15°) to be in the camera range so that the robotic arm can grab the samples. The resolution of every feature had then to be reduced as much as possible to meet this criterion while avoiding unwanted navigation behaviour. Indeed, if the goal tolerance is too low, the robot may take too long to match it and some recovery patterns inherent to Nav2 may be activated. 

To make the robot move, a service which uses the nav2 API was created, from bt_navigator, and moves the robot to a destination. Its definition is located [here](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca_msgs/srv/GoToStation.srv), inside the other package dedicated to messages and service types. It receives a station ID and a robot ID, moves the specific robot to the station and returns a result ID, 0 being a success. At the moment, the robot ID is hard defined, for the station, its position inside the circuit is retrieved from a [configuration file](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/config/stations.yaml). 

### GLAS architecture
To join this project to the whole laboratory structure, we're using [GLAS](https://github.com/swisscatplus/glas), which is a task scheduler enabling a reliable connection with the upper-level schedulers. We will detail the choices made for the workflows and nodes, for more information their [README](https://github.com/swisscatplus/glas) is well explained.
The workflows and nodes needed for our application are located in [this folder](https://github.com/swisscatplus/EM_fleetmanager/tree/main/config). A workflow defines a series of nodes, a node being a basic unitary action the Fleet Manager would need to perform. We defined two workflows, one for filling a station and another for going from one station to another, as they correspond to slightly different procedures. The first workflow needs any available robot which satisfies an objective function (yet to be implemented, its parameters would be battery percentage, distance to the required station, ...) whereas the second workflow needs the robot ID at the station. As for the nodes, they are where the ROS2 communication occurs. They obtain arguments from the upper post request and may launch ROS2 services or get topic information, according to their needs. If we take the example of the [MoveToStation Node](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/nodes/MoveToStation.py), it retrieves the ["station_end"] argument from the post request to move the robot accordingly, using a `subprocess.run` command. The resulting message obtained is then parsed to retrieve its ID, which is then returned to the Robot Scheduler. 

Upon defining a new workflow or node, one first has to define it inside the [config folder](https://github.com/swisscatplus/EM_fleetmanager/tree/main/config), then code the main body inside the `_execute` function, located inside the [nodes folder](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/nodes). Finally, to initialise it correctly, we also need to specify to the orchestrator that we created a new node, this is done by modifying [this code snippet](https://github.com/swisscatplus/EM_fleetmanager/blob/5451efa8952160f8aaa0cf5e752be1f0849c2e18/src/orchestrator/core.py#L77C13-L86C1).

A [scheduler](https://github.com/swisscatplus/EM_fleetmanager/blob/5451efa8952160f8aaa0cf5e752be1f0849c2e18/src/scheduler/core.py) is also available in case there is a need to implement a new API route inherent to the Fleet Manager.

</details>

## How to build

### Install project and dependencies
Git clone this project into your working space, use the recurse flag or add the GLAS submodule afterwards, --depth 1 specifies that we don't want to load all the commits history (there are TOO MANY)
```
git clone --recurse-submodules --depth 1 <git-url> 
```
Then go to the main directory and run the following line to install the dependencies.
```
# install dependencies
rosdep install --from-paths src -y --ignore-src

# pip related requirements:
pip install -r requirements.txt
# build project
colcon build # don't try the symlink build, ament_cmake is smh not complying
```

### Set-up workspace
As for any ROS2 project, don't forget to source it. 
```
nano ~/.bashrc #(or zshrc, depending on your set-up)

#write the following lines to source this project
source /opt/ros/humble/setup.bash
source ~/EM_fleetmanager/install/setup.bash

# some exports are also needed:
export PYTHONPATH=/opt/ros/humble/lib/python3/dist-packages
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp # needed for rpi and nav2 communication, for which fastdds doesnt work
export ROS_DOMAIN_ID=10  # same than the one on the mobile robot
```

## How to use
### Run from the terminal
To run the main launch file:
```
ros2 launch mob_rob_loca localization.launch.py

# it basically launches in series several other launch files
# ekf.launch.py, which creates the subscription to the mobile robot and outputs a filtered odometry
# rviz.launch.py, which sets the visualisation tools
# maps.launch.py, which creates the circuit and costmap layers needed for the navigation
# it then launches nav2 with a configuration file set up in params/
# fleet.launch.py, which creates the server responsible for moving the robot, this part should further be implemented to act as a Fleet Manager
```
For the fleet.launch.py, an example on how one could implement the future Fleet Manager node, which would supervise the whole operation, can be found [here](https://github.com/swisscatplus/EM_fleetmanager/blob/5451efa8952160f8aaa0cf5e752be1f0849c2e18/src/mob_rob_loca/mob_rob_loca/FleetManager.py) (it wasn't tested, rather is just an implementation idea that one could use as a skeleton).

This file gives information on how to install and use the package. Some examples are also given to illustrate the package in action.

### Create requests using Postman API
Using Postman, we can mimic a request from the Robot Scheduler to test if the implementation with the whole laboratory works. To achieve this we're using Postman, which can be downloaded [here](https://www.postman.com/downloads/). To make it work, we first need to have 0) our database built & running and a virtual environment, then 1) our scheduler running locally and 2) a Postman post request.

0) To create the database, we're using docker. Go to the main folder and build it:
    ```
    cd ~/EM_fleetmanager
    docker compose up -d # runs the containers in the background
    ```
    Then we have to create the virtual environment and install its dependencies:
    ```
    python3 -m venv .venv
    # source environment
    source ~/EM_fleetmanager/.venv/bin/activate
    # install dependencies if not done previously
    pip install -r requirements.txt
    # enable exec of shell script
    chmod u+x exec.sh
    ```
    You will also have to set the configuration for the two `.env` located respectively at [src/glas](https://github.com/swisscatplus/glas/blob/ccc1a3a07851eb8bf134fc779a95af1a39eb54c3/.env.example) and [src/glas/database/setup](https://github.com/swisscatplus/glas/blob/ccc1a3a07851eb8bf134fc779a95af1a39eb54c3/database/setup/.env.example). Rename the file without the `.example` and fill the variables according to your organisation.

   On Postman, you need to import the collection: select the import button, and choose this [json file](https://github.com/swisscatplus/glas/blob/ccc1a3a07851eb8bf134fc779a95af1a39eb54c3/GLAS.postman_collection.json). A collection named SwissCat+ should appear. You'll be using the "add task" tab to run tasks.

2) Once the environment is created and the docker containers running, this is what should be executed to launch our scheduler:
    ```
    cd ~/EM_fleetmanager
    # if the environment is not yet sourced
    source ~/EM_fleetmanager/.venv/bin/activate
    # run run.py with the port 3000
    ./exec.sh 3000
    # your scheduler should have initialised the nodes and be running
    ```

- If you encounter this error:

  ![image](https://github.com/swisscatplus/EM_fleetmanager/assets/102654647/8e561043-b9d6-4eae-8f77-ce3ed2136e69)

  It means the docker database isn't running, start the containers and try again.

2) Go on Postman, SwissCat+/Tasks/Add and fill the json body. Depending on the workflow you want to run, its arguments may vary. At this moment, here are the two json bodies which work with the scheduler:
    ```
    {
      "workflow_name": "Station-To-Station",
      "args": {"station_start": "ur5-sfc", "station_end": "ur5-omni"}
    }
    
    {
      "workflow_name": "Fill-Station",
      "args": {"station_end": "NMR"}
    }
    ```
    The workflow name has to match the one inside the config folder, and the stations also have to match the names defined in the stations.yalm. Here's a screenshot of what it should look like on Postman:
    
    ![image](https://github.com/swisscatplus/EM_fleetmanager/assets/102654647/b869450d-161e-4eed-a602-3a0a7ce11877)
  
  When running the code, your screen should typically look like this:
  
  ![image](https://github.com/swisscatplus/EM_fleetmanager/assets/102654647/1b0966ab-e9d6-42b5-bb35-e65af5f60d80)

## ROS2 interfaces

<div align="center">

| Topic                | Type                                    | Description                                                      |
|----------------------|-----------------------------------------|------------------------------------------------------------------|
| `odometry_filt`      | nav_msgs/msg/Odometry                  | EKF output of fused relative sensors                             |
| `odometry_global`    | nav_msgs/msg/Odometry                  | EKF output of fused relative and absolute sensors, final one     |
| `markers`            | visualization_msgs/msg/MarkerArray     | Visualisation of ArUco code on the circuit for debugging purposes|
| `keepout_filter_mask`| nav_msgs/msg/OccupancyGrid             | Occupancy grid representing the static obstacles, hence the circuit walls, used by Nav2|
</div>

Many services are present in the project due to using large packages like Nav2 or robot_localization, therefore only newly implemented services and other useful ones are described here.

<div align="center">
  
| Services implemented   | Input Args            | Output    | Description                                                                         |
|------------------------|-----------------------|-----------|-------------------------------------------------------------------------------------|
| `/go_to_station`        |  station_id, robot_id | result_id | Moves selected robot to desired station, returns 0 if success. otherwise returns the error ID |

| Other services         | Package |  Input Args            | Output    | Description                                                                         |
|------------------------|---------|------------------------|-----------|-------------------------------------------------------------------------------------|
| `/set_pose` | robot_localization |geometry_msgs/PoseWithCovarianceStamped pose|  -  |Sets the robot to a defined pose|
</div>

Some service examples are shown in the [mob_rob_loca_msgs/srv](https://github.com/swisscatplus/EM_fleetmanager/tree/main/src/mob_rob_loca_msgs/srv) folder to represent what would need to be further implemented, such as a service to get an available robot ID.

### Dependencies
The package dependencies are seen in the [package.xml](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/package.xml). The main ones are shown inside the following bracket.

<details open>
  <summary><strong>Show dependencies</strong></summary>
    - tf2_ros <br>
    - robot_localization <br>
    - navigation2 <br>
    - robot_localization <br>
    - nav2_map_server <br>
    - robot_state_publisher <br>
    - joint_state_publisher <br>
</details>

## To improve
- Regarding the localisation, only one portion of the circuit is equipped with ArUco codes which impacts the navigation, as the only part which can be reliably used for chemical transports is NMR <-> OMNI. The arrival of Dynamixel motors, with their embedded ROS2 driver, will improve the odometry's reliability, hopefully allowing for setting fewer ArUco codes on the circuit. A better calibration of the 
