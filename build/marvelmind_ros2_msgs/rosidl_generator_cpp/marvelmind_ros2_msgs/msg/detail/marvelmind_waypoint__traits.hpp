// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindWaypoint.idl
// generated code does not contain a copyright notice

#ifndef MARVELMIND_ROS2_MSGS__MSG__DETAIL__MARVELMIND_WAYPOINT__TRAITS_HPP_
#define MARVELMIND_ROS2_MSGS__MSG__DETAIL__MARVELMIND_WAYPOINT__TRAITS_HPP_

#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const marvelmind_ros2_msgs::msg::MarvelmindWaypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: total_items
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_items: ";
    value_to_yaml(msg.total_items, out);
    out << "\n";
  }

  // member: item_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "item_index: ";
    value_to_yaml(msg.item_index, out);
    out << "\n";
  }

  // member: movement_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "movement_type: ";
    value_to_yaml(msg.movement_type, out);
    out << "\n";
  }

  // member: param1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param1: ";
    value_to_yaml(msg.param1, out);
    out << "\n";
  }

  // member: param2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param2: ";
    value_to_yaml(msg.param2, out);
    out << "\n";
  }

  // member: param3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param3: ";
    value_to_yaml(msg.param3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const marvelmind_ros2_msgs::msg::MarvelmindWaypoint & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>()
{
  return "marvelmind_ros2_msgs::msg::MarvelmindWaypoint";
}

template<>
inline const char * name<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>()
{
  return "marvelmind_ros2_msgs/msg/MarvelmindWaypoint";
}

template<>
struct has_fixed_size<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MARVELMIND_ROS2_MSGS__MSG__DETAIL__MARVELMIND_WAYPOINT__TRAITS_HPP_
