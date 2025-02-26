FROM ros:humble-ros-base-jammy
SHELL ["/bin/bash", "-c"]
ENV ROS_DISTRO=humble

RUN apt-get update && apt-get install -y \
    python3 python3-pip python3-colcon-common-extensions \
    ros-${ROS_DISTRO}-example-interfaces ros-${ROS_DISTRO}-rclpy \
    python3-yaml python3-ply ros-${ROS_DISTRO}-nav2-map-server \
    libgl1-mesa-glx

# Install necessary Python packages via pip
RUN pip3 install opencv-python numpy

# Build your ROS application
WORKDIR /ros2_ws
COPY src/mob_rob_loca src/mob_rob_loca
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && colcon build --packages-select mob_rob_loca

# Copy the entrypoint script
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Set the entrypoint and default command
ENTRYPOINT ["/entrypoint.sh"]
CMD ["ros2", "launch", "mob_rob_loca", "maps.launch.py"]
