FROM ros:jazzy-ros-base-noble
SHELL ["/bin/bash", "-c"]
ENV ROS_DISTRO=jazzy

# Install system dependencies
RUN apt-get update && apt-get install -y \
    python3 python3-pip python3-colcon-common-extensions \
    ros-${ROS_DISTRO}-example-interfaces ros-${ROS_DISTRO}-rclpy \
    python3-yaml python3-ply ros-${ROS_DISTRO}-nav2-map-server \
    ros-${ROS_DISTRO}-tf-transformations libgl1 \
 && rm -rf /var/lib/apt/lists/*

# Install necessary Python packages via pip
# Pin numpy to <2.0 to avoid transforms3d / tf_transformations crash
RUN pip3 install --no-cache-dir --break-system-packages \
    opencv-python "numpy<2.0" pygame

# === ADD FASTDDS CONFIG FILE ===
RUN mkdir -p /root/.ros
COPY fastdds.xml /root/.ros/fastdds.xml
ENV FASTRTPS_DEFAULT_PROFILES_FILE=/root/.ros/fastdds.xml

# Build your ROS application
WORKDIR /ros2_ws
COPY src/mob_rob_loca src/mob_rob_loca
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && colcon build --packages-select mob_rob_loca

# Copy the entrypoint script
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Set the entrypoint and default command
ENTRYPOINT ["/entrypoint.sh"]

# Example launch (both maps + markers)
CMD ["/bin/bash", "-c", "ros2 launch mob_rob_loca maps.launch.py & ros2 launch mob_rob_loca markers.launch.py"]
