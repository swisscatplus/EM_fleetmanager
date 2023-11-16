// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from dwb_msgs:srv/GetCriticScore.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/get_critic_score__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/detail/get_critic_score__struct.h"
#include "dwb_msgs/srv/detail/get_critic_score__functions.h"

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
#include "rosidl_runtime_c/string.h"  // critic_name
#include "rosidl_runtime_c/string_functions.h"  // critic_name

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


typedef dwb_msgs__srv__GetCriticScore_Request _GetCriticScore_Request__ros_msg_type;

static bool _GetCriticScore_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetCriticScore_Request__ros_msg_type * ros_message = (_GetCriticScore_Request__ros_msg_type *)(untyped_ros_message);
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
  // Member: critic_name
 {
    uint32_t string_len = (ros_message->critic_name.data == NULL) ? 0 : (uint32_t)strlen(ros_message->critic_name.data) + 1;
    ros_message->critic_name.size = (ros_message->critic_name.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->critic_name.data, string_len);
  }

  return rv;
}

static bool _GetCriticScore_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetCriticScore_Request__ros_msg_type * ros_message = (_GetCriticScore_Request__ros_msg_type *)(untyped_ros_message);
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
  // Field name: critic_name
  {
    size_t capacity = ros_message->critic_name.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->critic_name.data, capacity, &string_size);
    if (rv) {
      ros_message->critic_name.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->critic_name.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetCriticScore_Request__ros_msg_type * ros_message = (const _GetCriticScore_Request__ros_msg_type *)(untyped_ros_message);
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
  // Member: critic_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->critic_name.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _GetCriticScore_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
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
  // Member: critic_name
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _GetCriticScore_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__GetCriticScore_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetCriticScore_Request = {
  "dwb_msgs::srv",
  "GetCriticScore_Request",
  _GetCriticScore_Request__cdr_serialize,
  _GetCriticScore_Request__cdr_deserialize,
  _GetCriticScore_Request__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__GetCriticScore_Request,
  _GetCriticScore_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetCriticScore_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetCriticScore_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GetCriticScore_Request)() {
  return &_GetCriticScore_Request__type_support;
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
// #include "dwb_msgs/srv/detail/get_critic_score__struct.h"
// already included above
// #include "dwb_msgs/srv/detail/get_critic_score__functions.h"

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

#include "dwb_msgs/msg/detail/critic_score__functions.h"  // score

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__CriticScore(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__CriticScore(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore)();


typedef dwb_msgs__srv__GetCriticScore_Response _GetCriticScore_Response__ros_msg_type;

static bool _GetCriticScore_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetCriticScore_Response__ros_msg_type * ros_message = (_GetCriticScore_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: score
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore
      )()->data))->cdr_serialize(&ros_message->score, cdr);

  return rv;
}

static bool _GetCriticScore_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetCriticScore_Response__ros_msg_type * ros_message = (_GetCriticScore_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: score
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore
      )()->data))->cdr_deserialize(cdr, &ros_message->score);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetCriticScore_Response__ros_msg_type * ros_message = (const _GetCriticScore_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: score
  current_alignment +=
    get_serialized_size_dwb_msgs__msg__CriticScore(&ros_message->score, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GetCriticScore_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: score
  current_alignment +=
    max_serialized_size_dwb_msgs__msg__CriticScore(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GetCriticScore_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__GetCriticScore_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetCriticScore_Response = {
  "dwb_msgs::srv",
  "GetCriticScore_Response",
  _GetCriticScore_Response__cdr_serialize,
  _GetCriticScore_Response__cdr_deserialize,
  _GetCriticScore_Response__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__GetCriticScore_Response,
  _GetCriticScore_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetCriticScore_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetCriticScore_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GetCriticScore_Response)() {
  return &_GetCriticScore_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/get_critic_score.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetCriticScore__callbacks = {
  "dwb_msgs::srv",
  "GetCriticScore",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GetCriticScore_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GetCriticScore_Response),
};

static rosidl_service_type_support_t GetCriticScore__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &GetCriticScore__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, GetCriticScore)() {
  return &GetCriticScore__handle;
}

#if defined(__cplusplus)
}
#endif
