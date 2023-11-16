// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeQuality.idl
// generated code does not contain a copyright notice

#ifndef MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_QUALITY__TRAITS_HPP_
#define MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_QUALITY__TRAITS_HPP_

#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const marvelmind_ros2_msgs::msg::HedgeQuality & msg,
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

  // member: quality_percents
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quality_percents: ";
    value_to_yaml(msg.quality_percents, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const marvelmind_ros2_msgs::msg::HedgeQuality & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<marvelmind_ros2_msgs::msg::HedgeQuality>()
{
  return "marvelmind_ros2_msgs::msg::HedgeQuality";
}

template<>
inline const char * name<marvelmind_ros2_msgs::msg::HedgeQuality>()
{
  return "marvelmind_ros2_msgs/msg/HedgeQuality";
}

template<>
struct has_fixed_size<marvelmind_ros2_msgs::msg::HedgeQuality>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<marvelmind_ros2_msgs::msg::HedgeQuality>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<marvelmind_ros2_msgs::msg::HedgeQuality>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_QUALITY__TRAITS_HPP_
