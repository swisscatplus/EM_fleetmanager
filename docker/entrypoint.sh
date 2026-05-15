#!/bin/bash
set -e

export RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_fastrtps_cpp}"
export FASTRTPS_DEFAULT_PROFILES_FILE="${FASTRTPS_DEFAULT_PROFILES_FILE:-/root/.ros/fastdds.xml}"
export ROS_DOMAIN_ID="${ROS_DOMAIN_ID:-10}"

source /etc/profile.d/fleet_stack_ros.sh

exec "$@"
