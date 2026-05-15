# Fleet stack interactive shell setup.

export RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_fastrtps_cpp}"
export FASTRTPS_DEFAULT_PROFILES_FILE="${FASTRTPS_DEFAULT_PROFILES_FILE:-/root/.ros/fastdds.xml}"
export ROS_DOMAIN_ID="${ROS_DOMAIN_ID:-10}"

if [ -n "$ROS_DISTRO" ] && [ -f "/opt/ros/$ROS_DISTRO/setup.bash" ]; then
  source "/opt/ros/$ROS_DISTRO/setup.bash"
fi

if [ -f /ros2_ws/install/setup.bash ]; then
  source /ros2_ws/install/setup.bash
fi

cd /ros2_ws 2>/dev/null || true
