// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from dwb_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/generate_trajectory__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/detail/generate_trajectory__struct.h"
#include "dwb_msgs/srv/detail/generate_trajectory__functions.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose2_d__functions.h"  // start_pose
#include "nav_2d_msgs/msg/detail/twist2_d__functions.h"  // cmd_vel, start_vel

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t get_serialized_size_geometry_msgs__msg__Pose2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t max_serialized_size_geometry_msgs__msg__Pose2D(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose2D)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t get_serialized_size_nav_2d_msgs__msg__Twist2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t max_serialized_size_nav_2d_msgs__msg__Twist2D(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D)();


typedef dwb_msgs__srv__GenerateTrajectory_Request _GenerateTrajectory_Request__ros_msg_type;

static bool _GenerateTrajectory_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GenerateTrajectory_Request__ros_msg_type * ros_message = (_GenerateTrajectory_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: start_pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose2D
      )()->data))->cdr_serialize(&ros_message->start_pose, cdr);
  // Member: start_vel
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D
      )()->data))->cdr_serialize(&ros_message->start_vel, cdr);
  // Member: cmd_vel
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D
      )()->data))->cdr_serialize(&ros_message->cmd_vel, cdr);

  return rv;
}

static bool _GenerateTrajectory_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GenerateTrajectory_Request__ros_msg_type * ros_message = (_GenerateTrajectory_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: start_pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose2D
      )()->data))->cdr_deserialize(cdr, &ros_message->start_pose);
  // Field name: start_vel
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D
      )()->data))->cdr_deserialize(cdr, &ros_message->start_vel);
  // Field name: cmd_vel
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D
      )()->data))->cdr_deserialize(cdr, &ros_message->cmd_vel);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GenerateTrajectory_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GenerateTrajectory_Request__ros_msg_type * ros_message = (const _GenerateTrajectory_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: start_pose
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Pose2D(&ros_message->start_pose, current_alignment);
  // Member: start_vel
  current_alignment +=
    get_serialized_size_nav_2d_msgs__msg__Twist2D(&ros_message->start_vel, current_alignment);
  // Member: cmd_vel
  current_alignment +=
    get_serialized_size_nav_2d_msgs__msg__Twist2D(&ros_message->cmd_vel, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GenerateTrajectory_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__GenerateTrajectory_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GenerateTrajectory_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: start_pose
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Pose2D(full_bounded, current_alignment);
  // Member: start_vel
  current_alignment +=
    max_serialized_size_nav_2d_msgs__msg__Twist2D(full_bounded, current_alignment);
  // Member: cmd_vel
  current_alignment +=
    max_serialized_size_nav_2d_msgs__msg__Twist2D(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GenerateTrajectory_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__GenerateTrajectory_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GenerateTrajectory_Request = {
  "dwb_msgs::srv",
  "GenerateTrajectory_Request",
  _GenerateTrajectory_Request__cdr_serialize,
  _GenerateTrajectory_Request__cdr_deserialize,
  _GenerateTrajectory_Request__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__GenerateTrajectory_Request,
  _GenerateTrajectory_Request__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GenerateTrajectory_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GenerateTrajectory_Request)() {
  return &_GenerateTrajectory_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "dwb_msgs/srv/detail/generate_trajectory__struct.h"
// already included above
// #include "dwb_msgs/srv/detail/generate_trajectory__functions.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "dwb_msgs/msg/detail/trajectory2_d__functions.h"  // traj

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__Trajectory2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__Trajectory2D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D)();


typedef dwb_msgs__srv__GenerateTrajectory_Response _GenerateTrajectory_Response__ros_msg_type;

static bool _GenerateTrajectory_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GenerateTrajectory_Response__ros_msg_type * ros_message = (_GenerateTrajectory_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: traj
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D
      )()->data))->cdr_serialize(&ros_message->traj, cdr);

  return rv;
}

static bool _GenerateTrajectory_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GenerateTrajectory_Response__ros_msg_type * ros_message = (_GenerateTrajectory_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: traj
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D
      )()->data))->cdr_deserialize(cdr, &ros_message->traj);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GenerateTrajectory_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GenerateTrajectory_Response__ros_msg_type * ros_message = (const _GenerateTrajectory_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment +=
    get_serialized_size_dwb_msgs__msg__Trajectory2D(&ros_message->traj, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GenerateTrajectory_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__GenerateTrajectory_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GenerateTrajectory_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment +=
    max_serialized_size_dwb_msgs__msg__Trajectory2D(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GenerateTrajectory_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__GenerateTrajectory_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GenerateTrajectory_Response = {
  "dwb_msgs::srv",
  "GenerateTrajectory_Response",
  _GenerateTrajectory_Response__cdr_serialize,
  _GenerateTrajectory_Response__cdr_deserialize,
  _GenerateTrajectory_Response__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__GenerateTrajectory_Response,
  _GenerateTrajectory_Response__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GenerateTrajectory_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GenerateTrajectory_Response)() {
  return &_GenerateTrajectory_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/generate_trajectory.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GenerateTrajectory__callbacks = {
  "dwb_msgs::srv",
  "GenerateTrajectory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GenerateTrajectory_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GenerateTrajectory_Response),
};

static rosidl_service_type_support_t GenerateTrajectory__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &GenerateTrajectory__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GenerateTrajectory)() {
  return &GenerateTrajectory__handle;
}

#if defined(__cplusplus)
}
#endif
