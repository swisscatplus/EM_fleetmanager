# CMake generated Testfile for 
# Source directory: /home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test
# Build directory: /home/coderey/ros2_ws/build/nav2_lifecycle_manager/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_lifecycle "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/coderey/ros2_ws/build/nav2_lifecycle_manager/test_results/nav2_lifecycle_manager/test_lifecycle.xml" "--package-name" "nav2_lifecycle_manager" "--generate-result-on-success" "--env" "TEST_EXECUTABLE=/home/coderey/ros2_ws/build/nav2_lifecycle_manager/test/test_lifecycle_gtest" "--command" "/home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test/launch_lifecycle_test.py")
set_tests_properties(test_lifecycle PROPERTIES  TIMEOUT "20" WORKING_DIRECTORY "/home/coderey/ros2_ws/build/nav2_lifecycle_manager/test" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test/CMakeLists.txt;13;ament_add_test;/home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test/CMakeLists.txt;0;")
add_test(test_bond "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/coderey/ros2_ws/build/nav2_lifecycle_manager/test_results/nav2_lifecycle_manager/test_bond.xml" "--package-name" "nav2_lifecycle_manager" "--generate-result-on-success" "--env" "TEST_EXECUTABLE=/home/coderey/ros2_ws/build/nav2_lifecycle_manager/test/test_bond_gtest" "--command" "/home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test/launch_bond_test.py")
set_tests_properties(test_bond PROPERTIES  TIMEOUT "20" WORKING_DIRECTORY "/home/coderey/ros2_ws/build/nav2_lifecycle_manager/test" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test/CMakeLists.txt;34;ament_add_test;/home/coderey/ros2_ws/src/navigation2/nav2_lifecycle_manager/test/CMakeLists.txt;0;")
subdirs("../gtest")
