// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from dwb_msgs:srv/ScoreTrajectory.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/score_trajectory__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/detail/score_trajectory__struct.h"
#include "dwb_msgs/srv/detail/score_trajectory__functions.h"

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
#include "nav_2d_msgs/msg/detail/path2_d__functions.h"  // global_plan
#include "nav_2d_msgs/msg/detail/pose2_d_stamped__functions.h"  // pose
#include "nav_2d_msgs/msg/detail/twist2_d__functions.h"  // velocity

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__Trajectory2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__Trajectory2D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t get_serialized_size_nav_2d_msgs__msg__Path2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t max_serialized_size_nav_2d_msgs__msg__Path2D(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Path2D)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t get_serialized_size_nav_2d_msgs__msg__Pose2DStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t max_serialized_size_nav_2d_msgs__msg__Pose2DStamped(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Pose2DStamped)();
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


typedef dwb_msgs__srv__ScoreTrajectory_Request _ScoreTrajectory_Request__ros_msg_type;

static bool _ScoreTrajectory_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ScoreTrajectory_Request__ros_msg_type * ros_message = (_ScoreTrajectory_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Pose2DStamped
      )()->data))->cdr_serialize(&ros_message->pose, cdr);
  // Member: velocity
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D
      )()->data))->cdr_serialize(&ros_message->velocity, cdr);
  // Member: global_plan
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Path2D
      )()->data))->cdr_serialize(&ros_message->global_plan, cdr);
  // Member: traj
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D
      )()->data))->cdr_serialize(&ros_message->traj, cdr);

  return rv;
}

static bool _ScoreTrajectory_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ScoreTrajectory_Request__ros_msg_type * ros_message = (_ScoreTrajectory_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Pose2DStamped
      )()->data))->cdr_deserialize(cdr, &ros_message->pose);
  // Field name: velocity
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Twist2D
      )()->data))->cdr_deserialize(cdr, &ros_message->velocity);
  // Field name: global_plan
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Path2D
      )()->data))->cdr_deserialize(cdr, &ros_message->global_plan);
  // Field name: traj
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D
      )()->data))->cdr_deserialize(cdr, &ros_message->traj);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__ScoreTrajectory_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ScoreTrajectory_Request__ros_msg_type * ros_message = (const _ScoreTrajectory_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment +=
    get_serialized_size_nav_2d_msgs__msg__Pose2DStamped(&ros_message->pose, current_alignment);
  // Member: velocity
  current_alignment +=
    get_serialized_size_nav_2d_msgs__msg__Twist2D(&ros_message->velocity, current_alignment);
  // Member: global_plan
  current_alignment +=
    get_serialized_size_nav_2d_msgs__msg__Path2D(&ros_message->global_plan, current_alignment);
  // Member: traj
  current_alignment +=
    get_serialized_size_dwb_msgs__msg__Trajectory2D(&ros_message->traj, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ScoreTrajectory_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__ScoreTrajectory_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__ScoreTrajectory_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment +=
    max_serialized_size_nav_2d_msgs__msg__Pose2DStamped(full_bounded, current_alignment);
  // Member: velocity
  current_alignment +=
    max_serialized_size_nav_2d_msgs__msg__Twist2D(full_bounded, current_alignment);
  // Member: global_plan
  current_alignment +=
    max_serialized_size_nav_2d_msgs__msg__Path2D(full_bounded, current_alignment);
  // Member: traj
  current_alignment +=
    max_serialized_size_dwb_msgs__msg__Trajectory2D(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ScoreTrajectory_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__ScoreTrajectory_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ScoreTrajectory_Request = {
  "dwb_msgs::srv",
  "ScoreTrajectory_Request",
  _ScoreTrajectory_Request__cdr_serialize,
  _ScoreTrajectory_Request__cdr_deserialize,
  _ScoreTrajectory_Request__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__ScoreTrajectory_Request,
  _ScoreTrajectory_Request__max_serialized_size
};

static rosidl_message_type_support_t _ScoreTrajectory_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ScoreTrajectory_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, ScoreTrajectory_Request)() {
  return &_ScoreTrajectory_Request__type_support;
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
// #include "dwb_msgs/srv/detail/score_trajectory__struct.h"
// already included above
// #include "dwb_msgs/srv/detail/score_trajectory__functions.h"

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

#include "dwb_msgs/msg/detail/trajectory_score__functions.h"  // score

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__TrajectoryScore(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__TrajectoryScore(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore)();


typedef dwb_msgs__srv__ScoreTrajectory_Response _ScoreTrajectory_Response__ros_msg_type;

static bool _ScoreTrajectory_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ScoreTrajectory_Response__ros_msg_type * ros_message = (_ScoreTrajectory_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: score
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore
      )()->data))->cdr_serialize(&ros_message->score, cdr);

  return rv;
}

static bool _ScoreTrajectory_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ScoreTrajectory_Response__ros_msg_type * ros_message = (_ScoreTrajectory_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: score
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore
      )()->data))->cdr_deserialize(cdr, &ros_message->score);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__ScoreTrajectory_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ScoreTrajectory_Response__ros_msg_type * ros_message = (const _ScoreTrajectory_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: score
  current_alignment +=
    get_serialized_size_dwb_msgs__msg__TrajectoryScore(&ros_message->score, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ScoreTrajectory_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__ScoreTrajectory_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__ScoreTrajectory_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: score
  current_alignment +=
    max_serialized_size_dwb_msgs__msg__TrajectoryScore(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ScoreTrajectory_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__ScoreTrajectory_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ScoreTrajectory_Response = {
  "dwb_msgs::srv",
  "ScoreTrajectory_Response",
  _ScoreTrajectory_Response__cdr_serialize,
  _ScoreTrajectory_Response__cdr_deserialize,
  _ScoreTrajectory_Response__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__ScoreTrajectory_Response,
  _ScoreTrajectory_Response__max_serialized_size
};

static rosidl_message_type_support_t _ScoreTrajectory_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ScoreTrajectory_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, ScoreTrajectory_Response)() {
  return &_ScoreTrajectory_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/score_trajectory.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ScoreTrajectory__callbacks = {
  "dwb_msgs::srv",
  "ScoreTrajectory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, ScoreTrajectory_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, ScoreTrajectory_Response),
};

static rosidl_service_type_support_t ScoreTrajectory__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &ScoreTrajectory__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, ScoreTrajectory)() {
  return &ScoreTrajectory__handle;
}

#if defined(__cplusplus)
}
#endif
