// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from dwb_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/generate_trajectory__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "dwb_msgs/srv/detail/generate_trajectory__struct.hpp"

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
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Pose2D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Pose2D &);

size_t get_serialized_size(
  const geometry_msgs::msg::Pose2D &,
  size_t current_alignment);

size_t
max_serialized_size_Pose2D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs

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


namespace dwb_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_serialize(
  const dwb_msgs::srv::GenerateTrajectory_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: start_pose
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.start_pose,
    cdr);
  // Member: start_vel
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.start_vel,
    cdr);
  // Member: cmd_vel
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.cmd_vel,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  dwb_msgs::srv::GenerateTrajectory_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: start_pose
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.start_pose);
  // Member: start_vel
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.start_vel);
  // Member: cmd_vel
  rv = nav_2d_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.cmd_vel);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
get_serialized_size(
  const dwb_msgs::srv::GenerateTrajectory_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: start_pose
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.start_pose,
    current_alignment);
  // Member: start_vel
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.start_vel,
    current_alignment);
  // Member: cmd_vel
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.cmd_vel,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
max_serialized_size_GenerateTrajectory_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: start_pose
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Pose2D(
    full_bounded,
    current_alignment);
  // Member: start_vel
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Twist2D(
    full_bounded,
    current_alignment);
  // Member: cmd_vel
  current_alignment += nav_2d_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Twist2D(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _GenerateTrajectory_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GenerateTrajectory_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dwb_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GenerateTrajectory_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GenerateTrajectory_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GenerateTrajectory_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GenerateTrajectory_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _GenerateTrajectory_Request__callbacks = {
  "dwb_msgs::srv",
  "GenerateTrajectory_Request",
  _GenerateTrajectory_Request__cdr_serialize,
  _GenerateTrajectory_Request__cdr_deserialize,
  _GenerateTrajectory_Request__get_serialized_size,
  _GenerateTrajectory_Request__get_serialized_size_with_initial_alignment,
  _GenerateTrajectory_Request__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GenerateTrajectory_Request__callbacks,
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
get_message_type_support_handle<dwb_msgs::srv::GenerateTrajectory_Request>()
{
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_GenerateTrajectory_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, GenerateTrajectory_Request)() {
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_GenerateTrajectory_Request__handle;
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
  const dwb_msgs::srv::GenerateTrajectory_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

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
  dwb_msgs::srv::GenerateTrajectory_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: traj
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.traj);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
get_serialized_size(
  const dwb_msgs::srv::GenerateTrajectory_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.traj,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
max_serialized_size_GenerateTrajectory_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Trajectory2D(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _GenerateTrajectory_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GenerateTrajectory_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dwb_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GenerateTrajectory_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GenerateTrajectory_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const dwb_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GenerateTrajectory_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GenerateTrajectory_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _GenerateTrajectory_Response__callbacks = {
  "dwb_msgs::srv",
  "GenerateTrajectory_Response",
  _GenerateTrajectory_Response__cdr_serialize,
  _GenerateTrajectory_Response__cdr_deserialize,
  _GenerateTrajectory_Response__get_serialized_size,
  _GenerateTrajectory_Response__get_serialized_size_with_initial_alignment,
  _GenerateTrajectory_Response__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GenerateTrajectory_Response__callbacks,
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
get_message_type_support_handle<dwb_msgs::srv::GenerateTrajectory_Response>()
{
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_GenerateTrajectory_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, GenerateTrajectory_Response)() {
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_GenerateTrajectory_Response__handle;
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

static service_type_support_callbacks_t _GenerateTrajectory__callbacks = {
  "dwb_msgs::srv",
  "GenerateTrajectory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, GenerateTrajectory_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, GenerateTrajectory_Response),
};

static rosidl_service_type_support_t _GenerateTrajectory__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GenerateTrajectory__callbacks,
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
get_service_type_support_handle<dwb_msgs::srv::GenerateTrajectory>()
{
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_GenerateTrajectory__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, srv, GenerateTrajectory)() {
  return &dwb_msgs::srv::typesupport_microxrcedds_cpp::_GenerateTrajectory__handle;
}

#ifdef __cplusplus
}
#endif
