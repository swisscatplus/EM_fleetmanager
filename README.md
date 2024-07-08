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

# Description
When running the main launch file, the program will subscribe to the four output topics of the mobile robot, described [here](https://github.com/swisscatplus/EM_onrobot), convert the left and right ticks into an odometry topic, wheel/odom. The IMU, odometry and camera position data will then be fused inside an EKF filter, using the [robot_localization package](https://index.ros.org/p/robot_localization/). This results in outputting the topic odometry/global, a much more reliable and stable position, which will then be used for the navigation tasks. At the moment, these are performed using [Nav2](https://github.com/ros-navigation/navigation2), but the goal is to detach from this package to have more control over the algorithms, as Nav2 provides little adaptability and its behaviour is sometimes unpredictable. In the framework of the SwissCat+ laboratory, navigation is needed to move the robot around stations where it'd be transporting chemical vials. The implemented GLAS architecture links this structure to the Robot Scheduler and provides workflows which can be called and executed in an autonomous manner. The task requests can be sent from Postman, an API platform, to mimic the Robot Scheduler behaviour.

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
