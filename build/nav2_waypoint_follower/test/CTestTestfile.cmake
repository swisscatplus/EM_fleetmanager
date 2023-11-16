# CMake generated Testfile for 
# Source directory: /home/coderey/ros2_ws/src/navigation2/nav2_waypoint_follower/test
# Build directory: /home/coderey/ros2_ws/build/nav2_waypoint_follower/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_task_executors "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/coderey/ros2_ws/build/nav2_waypoint_follower/test_results/nav2_waypoint_follower/test_task_executors.gtest.xml" "--package-name" "nav2_waypoint_follower" "--output-file" "/home/coderey/ros2_ws/build/nav2_waypoint_follower/ament_cmake_gtest/test_task_executors.txt" "--command" "/home/coderey/ros2_ws/build/nav2_waypoint_follower/test/test_task_executors" "--gtest_output=xml:/home/coderey/ros2_ws/build/nav2_waypoint_follower/test_results/nav2_waypoint_follower/test_task_executors.gtest.xml")
set_tests_properties(test_task_executors PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/coderey/ros2_ws/build/nav2_waypoint_follower/test/test_task_executors" TIMEOUT "60" WORKING_DIRECTORY "/home/coderey/ros2_ws/build/nav2_waypoint_follower/test" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/opt/ros/galactic/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/galactic/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/coderey/ros2_ws/src/navigation2/nav2_waypoint_follower/test/CMakeLists.txt;2;ament_add_gtest;/home/coderey/ros2_ws/src/navigation2/nav2_waypoint_follower/test/CMakeLists.txt;0;")
subdirs("../gtest")
