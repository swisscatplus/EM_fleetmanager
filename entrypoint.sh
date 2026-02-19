#!/bin/bash
set -e

export ROS_DOMAIN_ID=10

# Ensure Fast DDS profile path is active (optional but safe)
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
export FASTRTPS_DEFAULT_PROFILES_FILE=/root/.ros/fastdds.xml

# Source ROS 2
source /opt/ros/$ROS_DISTRO/setup.bash
# Source le workspace local
source /ros2_ws/install/setup.bash

# Exécuter la commande passée en arguments (CMD)
exec "$@"