FROM ros:humble-ros-base-jammy
SHELL ["/bin/bash", "-c"]
ENV ROS_DISTRO=humble

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    python3 \
    python3-pip \
    python3-colcon-common-extensions \
    python3-yaml \
    python3-ply \
    python3-numpy \
    python3-opencv \
    git \
    libgl1 \
    ros-${ROS_DISTRO}-example-interfaces \
    ros-${ROS_DISTRO}-geometry-msgs \
    ros-${ROS_DISTRO}-joint-state-publisher \
    ros-${ROS_DISTRO}-nav2-bringup \
    ros-${ROS_DISTRO}-nav2-map-server \
    ros-${ROS_DISTRO}-navigation2 \
    ros-${ROS_DISTRO}-nav-msgs \
    ros-${ROS_DISTRO}-robot-localization \
    ros-${ROS_DISTRO}-robot-state-publisher \
    ros-${ROS_DISTRO}-rclpy \
    ros-${ROS_DISTRO}-rviz2 \
    ros-${ROS_DISTRO}-sensor-msgs \
    ros-${ROS_DISTRO}-std-msgs \
    ros-${ROS_DISTRO}-tf-transformations \
    ros-${ROS_DISTRO}-tf2-ros \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --no-cache-dir "numpy<2.0" opencv-python pygame

RUN mkdir -p /root/.ros
COPY config/fastdds.xml /root/.ros/fastdds.xml
ENV FASTRTPS_DEFAULT_PROFILES_FILE=/root/.ros/fastdds.xml

WORKDIR /ros2_ws
COPY src/mob_rob_loca src/mob_rob_loca
COPY src/mob_rob_loca_msgs src/mob_rob_loca_msgs
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && \
    colcon build --packages-select mob_rob_loca_msgs mob_rob_loca

COPY docker/entrypoint.sh /entrypoint.sh
RUN sed -i 's/\r$//' /entrypoint.sh && chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash", "-lc", "ros2 launch mob_rob_loca maps.launch.py & ros2 launch mob_rob_loca markers.launch.py"]
