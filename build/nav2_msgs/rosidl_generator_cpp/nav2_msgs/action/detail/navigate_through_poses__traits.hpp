// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav2_msgs:action/NavigateThroughPoses.idl
// generated code does not contain a copyright notice

#ifndef NAV2_MSGS__ACTION__DETAIL__NAVIGATE_THROUGH_POSES__TRAITS_HPP_
#define NAV2_MSGS__ACTION__DETAIL__NAVIGATE_THROUGH_POSES__TRAITS_HPP_

#include "nav2_msgs/action/detail/navigate_through_poses__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: poses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses.size() == 0) {
      out << "poses: []\n";
    } else {
      out << "poses:\n";
      for (auto item : msg.poses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: behavior_tree
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_tree: ";
    value_to_yaml(msg.behavior_tree, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_Goal & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_Goal>()
{
  return "nav2_msgs::action::NavigateThroughPoses_Goal";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_Goal>()
{
  return "nav2_msgs/action/NavigateThroughPoses_Goal";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "std_msgs/msg/detail/empty__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_Result & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_Result>()
{
  return "nav2_msgs::action::NavigateThroughPoses_Result";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_Result>()
{
  return "nav2_msgs/action/NavigateThroughPoses_Result";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_Result>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Empty>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_Result>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Empty>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"
// Member 'navigation_time'
// Member 'estimated_time_remaining'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_yaml(msg.current_pose, out, indentation + 2);
  }

  // member: navigation_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "navigation_time:\n";
    to_yaml(msg.navigation_time, out, indentation + 2);
  }

  // member: estimated_time_remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estimated_time_remaining:\n";
    to_yaml(msg.estimated_time_remaining, out, indentation + 2);
  }

  // member: number_of_recoveries
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "number_of_recoveries: ";
    value_to_yaml(msg.number_of_recoveries, out);
    out << "\n";
  }

  // member: distance_remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_remaining: ";
    value_to_yaml(msg.distance_remaining, out);
    out << "\n";
  }

  // member: number_of_poses_remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "number_of_poses_remaining: ";
    value_to_yaml(msg.number_of_poses_remaining, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_Feedback & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_Feedback>()
{
  return "nav2_msgs::action::NavigateThroughPoses_Feedback";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_Feedback>()
{
  return "nav2_msgs/action/NavigateThroughPoses_Feedback";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_Feedback>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value && has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_Feedback>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value && has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "nav2_msgs/action/detail/navigate_through_poses__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_SendGoal_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>()
{
  return "nav2_msgs::action::NavigateThroughPoses_SendGoal_Request";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>()
{
  return "nav2_msgs/action/NavigateThroughPoses_SendGoal_Request";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<nav2_msgs::action::NavigateThroughPoses_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<nav2_msgs::action::NavigateThroughPoses_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_SendGoal_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>()
{
  return "nav2_msgs::action::NavigateThroughPoses_SendGoal_Response";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>()
{
  return "nav2_msgs/action/NavigateThroughPoses_SendGoal_Response";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_SendGoal>()
{
  return "nav2_msgs::action::NavigateThroughPoses_SendGoal";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_SendGoal>()
{
  return "nav2_msgs/action/NavigateThroughPoses_SendGoal";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>::value &&
    has_fixed_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>::value &&
    has_bounded_size<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<nav2_msgs::action::NavigateThroughPoses_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<nav2_msgs::action::NavigateThroughPoses_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nav2_msgs::action::NavigateThroughPoses_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_GetResult_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>()
{
  return "nav2_msgs::action::NavigateThroughPoses_GetResult_Request";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>()
{
  return "nav2_msgs/action/NavigateThroughPoses_GetResult_Request";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_GetResult_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>()
{
  return "nav2_msgs::action::NavigateThroughPoses_GetResult_Response";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>()
{
  return "nav2_msgs/action/NavigateThroughPoses_GetResult_Response";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<nav2_msgs::action::NavigateThroughPoses_Result>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<nav2_msgs::action::NavigateThroughPoses_Result>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_GetResult>()
{
  return "nav2_msgs::action::NavigateThroughPoses_GetResult";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_GetResult>()
{
  return "nav2_msgs/action/NavigateThroughPoses_GetResult";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>::value &&
    has_fixed_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>::value &&
    has_bounded_size<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>::value
  >
{
};

template<>
struct is_service<nav2_msgs::action::NavigateThroughPoses_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<nav2_msgs::action::NavigateThroughPoses_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nav2_msgs::action::NavigateThroughPoses_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nav2_msgs::action::NavigateThroughPoses_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nav2_msgs::action::NavigateThroughPoses_FeedbackMessage & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nav2_msgs::action::NavigateThroughPoses_FeedbackMessage>()
{
  return "nav2_msgs::action::NavigateThroughPoses_FeedbackMessage";
}

template<>
inline const char * name<nav2_msgs::action::NavigateThroughPoses_FeedbackMessage>()
{
  return "nav2_msgs/action/NavigateThroughPoses_FeedbackMessage";
}

template<>
struct has_fixed_size<nav2_msgs::action::NavigateThroughPoses_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<nav2_msgs::action::NavigateThroughPoses_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<nav2_msgs::action::NavigateThroughPoses_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<nav2_msgs::action::NavigateThroughPoses_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<nav2_msgs::action::NavigateThroughPoses_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<nav2_msgs::action::NavigateThroughPoses>
  : std::true_type
{
};

template<>
struct is_action_goal<nav2_msgs::action::NavigateThroughPoses_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<nav2_msgs::action::NavigateThroughPoses_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<nav2_msgs::action::NavigateThroughPoses_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // NAV2_MSGS__ACTION__DETAIL__NAVIGATE_THROUGH_POSES__TRAITS_HPP_
