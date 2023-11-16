// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
// generated code does not contain a copyright notice

#ifndef MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_IMU_RAW__TRAITS_HPP_
#define MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_IMU_RAW__TRAITS_HPP_

#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const marvelmind_ros2_msgs::msg::HedgeImuRaw & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp_ms: ";
    value_to_yaml(msg.timestamp_ms, out);
    out << "\n";
  }

  // member: acc_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_x: ";
    value_to_yaml(msg.acc_x, out);
    out << "\n";
  }

  // member: acc_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_y: ";
    value_to_yaml(msg.acc_y, out);
    out << "\n";
  }

  // member: acc_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_z: ";
    value_to_yaml(msg.acc_z, out);
    out << "\n";
  }

  // member: gyro_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_x: ";
    value_to_yaml(msg.gyro_x, out);
    out << "\n";
  }

  // member: gyro_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_y: ";
    value_to_yaml(msg.gyro_y, out);
    out << "\n";
  }

  // member: gyro_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_z: ";
    value_to_yaml(msg.gyro_z, out);
    out << "\n";
  }

  // member: compass_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "compass_x: ";
    value_to_yaml(msg.compass_x, out);
    out << "\n";
  }

  // member: compass_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "compass_y: ";
    value_to_yaml(msg.compass_y, out);
    out << "\n";
  }

  // member: compass_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "compass_z: ";
    value_to_yaml(msg.compass_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const marvelmind_ros2_msgs::msg::HedgeImuRaw & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<marvelmind_ros2_msgs::msg::HedgeImuRaw>()
{
  return "marvelmind_ros2_msgs::msg::HedgeImuRaw";
}

template<>
inline const char * name<marvelmind_ros2_msgs::msg::HedgeImuRaw>()
{
  return "marvelmind_ros2_msgs/msg/HedgeImuRaw";
}

template<>
struct has_fixed_size<marvelmind_ros2_msgs::msg::HedgeImuRaw>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<marvelmind_ros2_msgs::msg::HedgeImuRaw>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<marvelmind_ros2_msgs::msg::HedgeImuRaw>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_IMU_RAW__TRAITS_HPP_
