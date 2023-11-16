// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav2_msgs:srv/ClearCostmapAroundRobot.idl
// generated code does not contain a copyright notice

#ifndef NAV2_MSGS__SRV__DETAIL__CLEAR_COSTMAP_AROUND_ROBOT__TRAITS_HPP_
#define NAV2_MSGS__SRV__DETAIL__CLEAR_COSTMAP_AROUND_ROBOT__TRAITS_HPP_

#include "nav2_msgs/srv/detail/clear_costmap_around_robot__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::srv::ClearCostmapAroundRobot_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: reset_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reset_distance: ";
    value_to_yaml(msg.reset_distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::srv::ClearCostmapAroundRobot_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::srv::ClearCostmapAroundRobot_Request>()
{
  return "nav2_msgs::srv::ClearCostmapAroundRobot_Request";
}

template<>
inline const char * name<nav2_msgs::srv::ClearCostmapAroundRobot_Request>()
{
  return "nav2_msgs/srv/ClearCostmapAroundRobot_Request";
}

template<>
struct has_fixed_size<nav2_msgs::srv::ClearCostmapAroundRobot_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nav2_msgs::srv::ClearCostmapAroundRobot_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nav2_msgs::srv::ClearCostmapAroundRobot_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'response'
#include "std_msgs/msg/detail/empty__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::srv::ClearCostmapAroundRobot_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response:\n";
    to_yaml(msg.response, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::srv::ClearCostmapAroundRobot_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::srv::ClearCostmapAroundRobot_Response>()
{
  return "nav2_msgs::srv::ClearCostmapAroundRobot_Response";
}

template<>
inline const char * name<nav2_msgs::srv::ClearCostmapAroundRobot_Response>()
{
  return "nav2_msgs/srv/ClearCostmapAroundRobot_Response";
}

template<>
struct has_fixed_size<nav2_msgs::srv::ClearCostmapAroundRobot_Response>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Empty>::value> {};

template<>
struct has_bounded_size<nav2_msgs::srv::ClearCostmapAroundRobot_Response>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Empty>::value> {};

template<>
struct is_message<nav2_msgs::srv::ClearCostmapAroundRobot_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nav2_msgs::srv::ClearCostmapAroundRobot>()
{
  return "nav2_msgs::srv::ClearCostmapAroundRobot";
}

template<>
inline const char * name<nav2_msgs::srv::ClearCostmapAroundRobot>()
{
  return "nav2_msgs/srv/ClearCostmapAroundRobot";
}

template<>
struct has_fixed_size<nav2_msgs::srv::ClearCostmapAroundRobot>
  : std::integral_constant<
    bool,
    has_fixed_size<nav2_msgs::srv::ClearCostmapAroundRobot_Request>::value &&
    has_fixed_size<nav2_msgs::srv::ClearCostmapAroundRobot_Response>::value
  >
{
};

template<>
struct has_bounded_size<nav2_msgs::srv::ClearCostmapAroundRobot>
  : std::integral_constant<
    bool,
    has_bounded_size<nav2_msgs::srv::ClearCostmapAroundRobot_Request>::value &&
    has_bounded_size<nav2_msgs::srv::ClearCostmapAroundRobot_Response>::value
  >
{
};

template<>
struct is_service<nav2_msgs::srv::ClearCostmapAroundRobot>
  : std::true_type
{
};

template<>
struct is_service_request<nav2_msgs::srv::ClearCostmapAroundRobot_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nav2_msgs::srv::ClearCostmapAroundRobot_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAV2_MSGS__SRV__DETAIL__CLEAR_COSTMAP_AROUND_ROBOT__TRAITS_HPP_
