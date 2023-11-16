// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeTelemetry.idl
// generated code does not contain a copyright notice

#ifndef MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_TELEMETRY__TRAITS_HPP_
#define MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_TELEMETRY__TRAITS_HPP_

#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const marvelmind_ros2_msgs::msg::HedgeTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: rssi_dbm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rssi_dbm: ";
    value_to_yaml(msg.rssi_dbm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const marvelmind_ros2_msgs::msg::HedgeTelemetry & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<marvelmind_ros2_msgs::msg::HedgeTelemetry>()
{
  return "marvelmind_ros2_msgs::msg::HedgeTelemetry";
}

template<>
inline const char * name<marvelmind_ros2_msgs::msg::HedgeTelemetry>()
{
  return "marvelmind_ros2_msgs/msg/HedgeTelemetry";
}

template<>
struct has_fixed_size<marvelmind_ros2_msgs::msg::HedgeTelemetry>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<marvelmind_ros2_msgs::msg::HedgeTelemetry>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<marvelmind_ros2_msgs::msg::HedgeTelemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MARVELMIND_ROS2_MSGS__MSG__DETAIL__HEDGE_TELEMETRY__TRAITS_HPP_
