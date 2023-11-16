// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_localization:srv/GetState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_LOCALIZATION__SRV__DETAIL__GET_STATE__TRAITS_HPP_
#define ROBOT_LOCALIZATION__SRV__DETAIL__GET_STATE__TRAITS_HPP_

#include "robot_localization/srv/detail/get_state__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'time_stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const robot_localization::srv::GetState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_stamp:\n";
    to_yaml(msg.time_stamp, out, indentation + 2);
  }

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    value_to_yaml(msg.frame_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const robot_localization::srv::GetState_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<robot_localization::srv::GetState_Request>()
{
  return "robot_localization::srv::GetState_Request";
}

template<>
inline const char * name<robot_localization::srv::GetState_Request>()
{
  return "robot_localization/srv/GetState_Request";
}

template<>
struct has_fixed_size<robot_localization::srv::GetState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_localization::srv::GetState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_localization::srv::GetState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const robot_localization::srv::GetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.state.size() == 0) {
      out << "state: []\n";
    } else {
      out << "state:\n";
      for (auto item : msg.state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.covariance.size() == 0) {
      out << "covariance: []\n";
    } else {
      out << "covariance:\n";
      for (auto item : msg.covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const robot_localization::srv::GetState_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<robot_localization::srv::GetState_Response>()
{
  return "robot_localization::srv::GetState_Response";
}

template<>
inline const char * name<robot_localization::srv::GetState_Response>()
{
  return "robot_localization/srv/GetState_Response";
}

template<>
struct has_fixed_size<robot_localization::srv::GetState_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_localization::srv::GetState_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_localization::srv::GetState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_localization::srv::GetState>()
{
  return "robot_localization::srv::GetState";
}

template<>
inline const char * name<robot_localization::srv::GetState>()
{
  return "robot_localization/srv/GetState";
}

template<>
struct has_fixed_size<robot_localization::srv::GetState>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_localization::srv::GetState_Request>::value &&
    has_fixed_size<robot_localization::srv::GetState_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_localization::srv::GetState>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_localization::srv::GetState_Request>::value &&
    has_bounded_size<robot_localization::srv::GetState_Response>::value
  >
{
};

template<>
struct is_service<robot_localization::srv::GetState>
  : std::true_type
{
};

template<>
struct is_service_request<robot_localization::srv::GetState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_localization::srv::GetState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_LOCALIZATION__SRV__DETAIL__GET_STATE__TRAITS_HPP_
