FROM ros:humble-ros-base-jammy
SHELL ["/bin/bash", "-c"]
ENV ROS_DISTRO=humble

RUN apt-get update && apt-get install -y --no-install-recommends \
    python3 \
    python3-colcon-common-extensions \
    python3-yaml \
    ros-${ROS_DISTRO}-ament-index-python \
    ros-${ROS_DISTRO}-geometry-msgs \
    ros-${ROS_DISTRO}-launch-ros \
    ros-${ROS_DISTRO}-nav2-lifecycle-manager \
    ros-${ROS_DISTRO}-nav2-map-server \
    ros-${ROS_DISTRO}-rclpy \
    ros-${ROS_DISTRO}-rviz2 \
    ros-${ROS_DISTRO}-tf-transformations \
    ros-${ROS_DISTRO}-tf2-ros \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /root/.ros
COPY config/fastdds.xml /root/.ros/fastdds.xml
ENV FASTRTPS_DEFAULT_PROFILES_FILE=/root/.ros/fastdds.xml

WORKDIR /ros2_ws
COPY src/fleet_manager src/fleet_manager
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && \
    colcon build --packages-select fleet_manager

COPY docker/entrypoint.sh /entrypoint.sh
RUN sed -i 's/\r$//' /entrypoint.sh && chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash", "-lc", "ros2 launch fleet_manager bringup.launch.py"]
