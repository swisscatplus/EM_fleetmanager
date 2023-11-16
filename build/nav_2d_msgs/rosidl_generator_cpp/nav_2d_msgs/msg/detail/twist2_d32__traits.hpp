// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_2d_msgs:msg/Twist2D32.idl
// generated code does not contain a copyright notice

#ifndef NAV_2D_MSGS__MSG__DETAIL__TWIST2_D32__TRAITS_HPP_
#define NAV_2D_MSGS__MSG__DETAIL__TWIST2_D32__TRAITS_HPP_

#include "nav_2d_msgs/msg/detail/twist2_d32__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav_2d_msgs::msg::Twist2D32 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav_2d_msgs::msg::Twist2D32 & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav_2d_msgs::msg::Twist2D32>()
{
  return "nav_2d_msgs::msg::Twist2D32";
}

template<>
inline const char * name<nav_2d_msgs::msg::Twist2D32>()
{
  return "nav_2d_msgs/msg/Twist2D32";
}

template<>
struct has_fixed_size<nav_2d_msgs::msg::Twist2D32>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nav_2d_msgs::msg::Twist2D32>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nav_2d_msgs::msg::Twist2D32>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_2D_MSGS__MSG__DETAIL__TWIST2_D32__TRAITS_HPP_
