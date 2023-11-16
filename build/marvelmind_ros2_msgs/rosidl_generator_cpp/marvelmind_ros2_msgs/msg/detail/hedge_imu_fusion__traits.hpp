// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuFusion.idl
// generated code does not contain a copyright notice

#ifndef MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_IMU_FUSION__TRAITS_HPP_
#define MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_IMU_FUSION__TRAITS_HPP_

#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const marvelmind_ros2_msgs::msg::HedgeImuFusion & msg,
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

  // member: x_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_m: ";
    value_to_yaml(msg.x_m, out);
    out << "\n";
  }

  // member: y_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_m: ";
    value_to_yaml(msg.y_m, out);
    out << "\n";
  }

  // member: z_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_m: ";
    value_to_yaml(msg.z_m, out);
    out << "\n";
  }

  // member: qw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "qw: ";
    value_to_yaml(msg.qw, out);
    out << "\n";
  }

  // member: qx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "qx: ";
    value_to_yaml(msg.qx, out);
    out << "\n";
  }

  // member: qy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "qy: ";
    value_to_yaml(msg.qy, out);
    out << "\n";
  }

  // member: qz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "qz: ";
    value_to_yaml(msg.qz, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    value_to_yaml(msg.vz, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    value_to_yaml(msg.az, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const marvelmind_ros2_msgs::msg::HedgeImuFusion & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<marvelmind_ros2_msgs::msg::HedgeImuFusion>()
{
  return "marvelmind_ros2_msgs::msg::HedgeImuFusion";
}

template<>
inline const char * name<marvelmind_ros2_msgs::msg::HedgeImuFusion>()
{
  return "marvelmind_ros2_msgs/msg/HedgeImuFusion";
}

template<>
struct has_fixed_size<marvelmind_ros2_msgs::msg::HedgeImuFusion>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<marvelmind_ros2_msgs::msg::HedgeImuFusion>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<marvelmind_ros2_msgs::msg::HedgeImuFusion>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_IMU_FUSION__TRAITS_HPP_
