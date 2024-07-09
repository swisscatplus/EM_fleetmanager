<br />
<div align="center">
  <a href="https://github.com/swisscatplus/task-scheduler">
    <img src="https://images.squarespace-cdn.com/content/v1/6012a0a1f4c67c587a8eff67/d7731755-2fa3-4548-bf1e-5a25182d67ae/Combined+Logo+CAT-ETH-EPFL+%282%29.png?format=1500w" alt="Logo" height="80">
  </a>

  <h1 align="center"> EM_fleetmanager - Autonomous navigation and control of a mobile robot using Nav2 and GLAS architecture </h1>

</div>

This repository provides the code to fuse sensors using an Extended Kalman filter and uses the outputted position to control a mobile robot using [Nav2](https://github.com/ros-navigation/navigation2). The latter is responsible for transporting chemical vials between stations inside the laboratory. Moreover, the project fits into the framework of the schedulers from the SwissCat+ laboratory as it uses the [GLAS](https://github.com/swisscatplus/glas) scheduler to communicate with the higher-level scheduler: the Robot Scheduler. It is designed to work jointly with a mobile robot having [this code](https://github.com/swisscatplus/EM_onrobot) embedded and running.

## Versions and software used
  - Ubuntu 22.04
  - ROS2 Humble
  
## Table of Contents
1. [Description](#description)<br>
2. [How to build](#how-to-build)<br>
3. [How to use](#how-to-use)<br>
4. [ROS2 Interfaces](#ros2-interfaces)<br>

## Description
When running the main launch file, the program will subscribe to the four output topics of the mobile robot, described [here](https://github.com/swisscatplus/EM_onrobot), convert the left and right ticks into an odometry topic, wheel/odom. The IMU, odometry and camera position data will then be fused inside an EKF filter, using the [robot_localization package](https://index.ros.org/p/robot_localization/). This results in outputting the topic odometry/global, a much more reliable and stable position, which will then be used for the navigation tasks. At the moment, these are performed using [Nav2](https://github.com/ros-navigation/navigation2), but the goal is to detach from this package to have more control over the algorithms, as Nav2 provides little adaptability and its behaviour is sometimes unpredictable. In the framework of the SwissCat+ laboratory, navigation is needed to move the robot around stations where it'd be transporting chemical vials. The implemented GLAS architecture links this structure to the Robot Scheduler and provides workflows which can be called and executed autonomously. The task requests can be sent from Postman, an API platform, to mimic the Robot Scheduler behaviour.

### Sensor fusion
To achieve sensor fusion, the topics must have compatible types and a configuration file has to be properly set, which includes defining the covariance matrices. The configuration file implemented is [here](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/config/ekf_em.yaml), and all the information about its configuration is described in the comments of the former [file](https://github.com/cra-ros-pkg/robot_localization/blob/ros2/params/ekf.yaml). In our case, we apply the EKF filter twice, once for the relative localisation data and once for the absolute one. This also allows us to have the transforms automatically defined  as the `publish_tf` boolean is enabled. The relative pose includes the IMU and the odometry data, which are thus fused into the `odometry/filtered` topic, and then fused again with the camera position data as part of the absolute data pose. 

### Navigation 2
Similar to the Kalman module, a [configuration file](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/params/nav_params.yaml) defines the navigation tools employed: the main components on which a focus will be made are the planner, controller as well as costmap filter. The structure of Nav2 can be observed in the following figure.

<center>
  <img width="493" alt="nav2_global" src="https://github.com/swisscatplus/EM_fleetmanager/assets/102654647/04572848-4494-440f-b763-253a09dfc50f">
</center>

For the planner, an A* is used as no specific planner is needed to plan the path for one robot. It will need to be changed in the future to account for the other mobile robots and avoid them. As the robot can rotate on itself, the primary controller employed, named rotary shim controller, privileges this behaviour. If the angle to the path is lower than a certain tolerance, the control to follow the path then switches to the default Nav2 controller, which is a [Dynamic-Window Approach controller](https://github.com/ros-navigation/navigation2/blob/main/nav2_dwb_controller/README.md). To include the static obstacles, meaning the walls of the track, a costmap filter was defined. It's simply a PNG map with black pixels where the walls are. This was the only option to provide the obstacle positions, as the robot lacks embedded sensors to detect near obstacles, such as a lidar. The map was then inflated to account for the robot radius with a safety margin. To make it work with the other maps, a configuration file](https://github.com/swisscatplus/EM_fleetmanager/blob/main/src/mob_rob_loca/params/keepout_params.yaml) also had to be implemented with the basic information required for the image. One of the main challenges of this implementation was to match the required circuit resolution, as the stations need to be met within a precise tolerance (<2cm, <15°) to be in the camera range so that the robotic arm can grab the samples. The resolution of every feature had then to be reduced as much as possible to meet this criterion while avoiding unwanted navigation behaviour. Indeed, if the goal tolerance is too low, the robot may take too long to match it and some recovery patterns inherent to Nav2 may be activated. 

### GLAS architecture

### Visualisation

## How to build

### Install ROS2

### Install project and dependencies

### Set-up workspace



This file gives information on how to install and use the package. Some examples are also given to illustrate the package in action.

## Installation
In the terminal, write the following commands:
```
mkdir ~/edi_ws/src && cd ~/edi_ws/src
git clone git@github.com:Yanniscod/SwissCat_ROS2.git
rosdep install --from-paths src -y --ignore-src
cd ~/edi_ws
colcon build --symlink-install
```

As written, the package uses the full repository of [Nav2 repository](https://github.com/ros-planning/navigation2/tree/galactic) to navigate, but also the [robot_localization](https://github.com/automaticaddison/robot_localization) to compute the localization using the EKF. The first was fully cloned into the folder, as problems were experienced when trying to run the code using the operating system’s package manager, as suggested in the [Nav2 tutorial](https://navigation.ros.org/getting_started/index.html). Therefore, if you experience similar problems, please copy-paste the following commands in your terminal:
```
cd ~/edi_ws/src
git clone https://github.com/ros-planning/navigation2.git --branch galactic
cd ~/edi_ws
rosdep install -y -r -q --from-paths src --ignore-src --rosdistro galactic
colcon build --symlink-install
```

## Localization
The localization of the Edison robot is determined by fusing three sets of data: the ultrasonic GPS provided by [Marvelmind](https://marvelmind.com/product/starter-set-super-mp-3d/), the [bno055 IMU from Bosch](https://www.bosch-sensortec.com/products/smart-sensor-systems/bno055/) and the odometry of the wheels. One could have only used the GPS information to have the position of the robot, however when testing inside the laboratory, a large variance was observed as the signal was jumping back and forth. The following picture illustrates the trajectory seen by the raw GPS sensor, the odometry of the wheels and the odometry fused. 

INCLUDE GRAPH 

## On-robot communication
The Edison robot is composed of an arduino UNO controlling the DC motors. The latter is serial linked to a Raspberry 3B+, powering the IMU and GPS devices and communicating with the ROS2 server by subscribing to the velocity topic, /cmd_vel, and publishing the ticks of the motors, as well as IMU data. The GPS device has its own ROS2 node. 
The code uploaded on the Raspberry was put inside the /src and /launch folders of the mob_rob_loca package, and is recognised by starting with rpi_. The installation of the RPI will be documented in another README.
