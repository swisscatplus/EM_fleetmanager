// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from marvelmind_ros2_msgs:msg/HedgePositionAddressed.idl
// generated code does not contain a copyright notice

#ifndef MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_POSITION_ADDRESSED__TRAITS_HPP_
#define MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_POSITION_ADDRESSED__TRAITS_HPP_

#include "marvelmind_ros2_msgs/msg/detail/hedge_position_addressed__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const marvelmind_ros2_msgs::msg::HedgePositionAddressed & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "address: ";
    value_to_yaml(msg.address, out);
    out << "\n";
  }

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

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    value_to_yaml(msg.flags, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const marvelmind_ros2_msgs::msg::HedgePositionAddressed & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<marvelmind_ros2_msgs::msg::HedgePositionAddressed>()
{
  return "marvelmind_ros2_msgs::msg::HedgePositionAddressed";
}

template<>
inline const char * name<marvelmind_ros2_msgs::msg::HedgePositionAddressed>()
{
  return "marvelmind_ros2_msgs/msg/HedgePositionAddressed";
}

template<>
struct has_fixed_size<marvelmind_ros2_msgs::msg::HedgePositionAddressed>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<marvelmind_ros2_msgs::msg::HedgePositionAddressed>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<marvelmind_ros2_msgs::msg::HedgePositionAddressed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_POSITION_ADDRESSED__TRAITS_HPP_
