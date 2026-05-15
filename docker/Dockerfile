FROM ros:humble-ros-base-jammy
SHELL ["/bin/bash", "-c"]
ENV DEBIAN_FRONTEND=noninteractive
ENV ROS_DISTRO=humble

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    curl \
    git \
    gnupg \
    libgl1 \
    lsb-release \
    python3 \
    python3-colcon-common-extensions \
    python3-pip \
    python3-rosdep \
    python3-yaml \
    ros-${ROS_DISTRO}-ament-index-python \
    ros-${ROS_DISTRO}-geometry-msgs \
    ros-${ROS_DISTRO}-launch-ros \
    ros-${ROS_DISTRO}-nav-msgs \
    ros-${ROS_DISTRO}-nav2-lifecycle-manager \
    ros-${ROS_DISTRO}-nav2-map-server \
    ros-${ROS_DISTRO}-rclpy \
    ros-${ROS_DISTRO}-rosidl-default-generators \
    ros-${ROS_DISTRO}-rosidl-default-runtime \
    ros-${ROS_DISTRO}-rviz2 \
    ros-${ROS_DISTRO}-std-msgs \
    ros-${ROS_DISTRO}-tf-transformations \
    ros-${ROS_DISTRO}-tf2-ros \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --no-cache-dir \
    cvxpy \
    matplotlib \
    networkx \
    "numpy<2.0" \
    opencv-python \
    py_trees \
    Rtree \
    scipy \
    shapely \
    transitions

RUN mkdir -p /root/.ros
COPY config/fastdds.xml /root/.ros/fastdds.xml
ENV FASTRTPS_DEFAULT_PROFILES_FILE=/root/.ros/fastdds.xml

WORKDIR /ros2_ws
COPY src src
RUN rosdep update && \
    rosdep install --from-paths src --ignore-src -r -y && \
    . /opt/ros/${ROS_DISTRO}/setup.sh && \
    colcon build --symlink-install --packages-select fleet_interfaces fleet_manager tracker

COPY docker/entrypoint.sh /entrypoint.sh
COPY docker/ros_bashrc.sh /etc/profile.d/fleet_stack_ros.sh
RUN sed -i 's/\r$//' /entrypoint.sh /etc/profile.d/fleet_stack_ros.sh && \
    chmod +x /entrypoint.sh && \
    cat /etc/profile.d/fleet_stack_ros.sh >> /root/.bashrc

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]
