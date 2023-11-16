// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from dwb_msgs:srv/ScoreTrajectory.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/score_trajectory__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "dwb_msgs/srv/detail/score_trajectory__struct.hpp"

#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstring>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
#include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace nav_2d_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav_2d_msgs::msg::Pose2DStamped &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav_2d_msgs::msg::Pose2DStamped &);

size_t get_serialized_size(
  const nav_2d_msgs::msg::Pose2DStamped &,
  size_t current_alignment);

size_t
max_serialized_size_Pose2DStamped(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace nav_2d_msgs

namespace nav_2d_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav_2d_msgs::msg::Twist2D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav_2d_msgs::msg::Twist2D &);

size_t get_serialized_size(
  const nav_2d_msgs::msg::Twist2D &,
  size_t current_alignment);

size_t
max_serialized_size_Twist2D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace nav_2d_msgs

namespace nav_2d_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav_2d_msgs::msg::Path2D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav_2d_msgs::msg::Path2D &);

size_t get_serialized_size(
  const nav_2d_msgs::msg::Path2D &,
  size_t current_alignment);

size_t
max_serialized_size_Path2D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace nav_2d_msgs

namespace dwb_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const dwb_msgs::msg::Trajectory2D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  dwb_msgs::msg::Trajectory2D &);

size_t get_serialized_size(
  const dwb_msgs::msg::Trajectory2D &,
  size_t current_alignment);

size_t
max_serialized_size_Trajectory2D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace dwb_msgs


namespace dwb_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_serialize(
  const dwb_msgs::srv::ScoreTrajectory_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: pose
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.pose,
    cdr);
  // Member: velocity
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.velocity,
    cdr);
  // Member: global_plan
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.global_plan,
    cdr);
  // Member: traj
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.traj,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  dwb_msgs::srv::ScoreTrajectory_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: pose
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.pose);
  // Member: velocity
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.velocity);
  // Member: global_plan
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.global_plan);
  // Member: traj
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.traj);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
get_serialized_size(
  const dwb_msgs::srv::ScoreTrajectory_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.pose,
    current_alignment);
  // Member: velocity
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.velocity,
    current_alignment);
  // Member: global_plan
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.global_plan,
    current_alignment);
  // Member: traj
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.traj,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
max_serialized_size_ScoreTrajectory_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Pose2DStamped(
    full_bounded,
    current_alignment);
  // Member: velocity
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Twist2D(
    full_bounded,
    current_alignment);
  // Member: global_plan
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Path2D(
    full_bounded,
    current_alignment);
  // Member: traj
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Trajectory2D(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ScoreTrajectory_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::ScoreTrajectory_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ScoreTrajectory_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dwb_msgs::srv::ScoreTrajectory_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ScoreTrajectory_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::ScoreTrajectory_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ScoreTrajectory_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::ScoreTrajectory_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ScoreTrajectory_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ScoreTrajectory_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _ScoreTrajectory_Request__callbacks = {
  "dwb_msgs::srv",
  "ScoreTrajectory_Request",
  _ScoreTrajectory_Request__cdr_serialize,
  _ScoreTrajectory_Request__cdr_deserialize,
  _ScoreTrajectory_Request__get_serialized_size,
  _ScoreTrajectory_Request__get_serialized_size_with_initial_alignment,
  _ScoreTrajectory_Request__max_serialized_size
};

static rosidl_message_type_support_t _ScoreTrajectory_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ScoreTrajectory_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace dwb_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_dwb_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<dwb_msgs::srv::ScoreTrajectory_Request>()
{
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_ScoreTrajectory_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, ScoreTrajectory_Request)() {
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_ScoreTrajectory_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace dwb_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const dwb_msgs::msg::TrajectoryScore &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  dwb_msgs::msg::TrajectoryScore &);

size_t get_serialized_size(
  const dwb_msgs::msg::TrajectoryScore &,
  size_t current_alignment);

size_t
max_serialized_size_TrajectoryScore(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace dwb_msgs


namespace dwb_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_serialize(
  const dwb_msgs::srv::ScoreTrajectory_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: score
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.score,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  dwb_msgs::srv::ScoreTrajectory_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: score
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.score);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
get_serialized_size(
  const dwb_msgs::srv::ScoreTrajectory_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: score
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.score,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
max_serialized_size_ScoreTrajectory_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: score
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_TrajectoryScore(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ScoreTrajectory_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::ScoreTrajectory_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ScoreTrajectory_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dwb_msgs::srv::ScoreTrajectory_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ScoreTrajectory_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::ScoreTrajectory_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ScoreTrajectory_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::ScoreTrajectory_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ScoreTrajectory_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ScoreTrajectory_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _ScoreTrajectory_Response__callbacks = {
  "dwb_msgs::srv",
  "ScoreTrajectory_Response",
  _ScoreTrajectory_Response__cdr_serialize,
  _ScoreTrajectory_Response__cdr_deserialize,
  _ScoreTrajectory_Response__get_serialized_size,
  _ScoreTrajectory_Response__get_serialized_size_with_initial_alignment,
  _ScoreTrajectory_Response__max_serialized_size
};

static rosidl_message_type_support_t _ScoreTrajectory_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ScoreTrajectory_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace dwb_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_dwb_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<dwb_msgs::srv::ScoreTrajectory_Response>()
{
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_ScoreTrajectory_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, ScoreTrajectory_Response)() {
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_ScoreTrajectory_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace dwb_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _ScoreTrajectory__callbacks = {
  "dwb_msgs::srv",
  "ScoreTrajectory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, ScoreTrajectory_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, ScoreTrajectory_Response),
};

static rosidl_service_type_support_t _ScoreTrajectory__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ScoreTrajectory__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace dwb_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_dwb_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<dwb_msgs::srv::ScoreTrajectory>()
{
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_ScoreTrajectory__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, ScoreTrajectory)() {
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_ScoreTrajectory__handle;
}

#ifdef __cplusplus
}
#endif
