// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from dwb_msgs:srv/DebugLocalPlan.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/debug_local_plan__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/detail/debug_local_plan__struct.h"
#include "dwb_msgs/srv/detail/debug_local_plan__functions.h"

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

#include "nav_2d_msgs/msg/detail/path2_d__functions.h"  // global_plan
#include "nav_2d_msgs/msg/detail/pose2_d_stamped__functions.h"  // pose
#include "nav_2d_msgs/msg/detail/twist2_d__functions.h"  // velocity

// forward declare type support functions
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


typedef dwb_msgs__srv__DebugLocalPlan_Request _DebugLocalPlan_Request__ros_msg_type;

static bool _DebugLocalPlan_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _DebugLocalPlan_Request__ros_msg_type * ros_message = (_DebugLocalPlan_Request__ros_msg_type *)(untyped_ros_message);
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

  return rv;
}

static bool _DebugLocalPlan_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _DebugLocalPlan_Request__ros_msg_type * ros_message = (_DebugLocalPlan_Request__ros_msg_type *)(untyped_ros_message);
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
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__DebugLocalPlan_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _DebugLocalPlan_Request__ros_msg_type * ros_message = (const _DebugLocalPlan_Request__ros_msg_type *)(untyped_ros_message);
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

  return current_alignment - initial_alignment;
}

static uint32_t _DebugLocalPlan_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__DebugLocalPlan_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__DebugLocalPlan_Request(
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

  return current_alignment - initial_alignment;
}

static size_t _DebugLocalPlan_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__DebugLocalPlan_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_DebugLocalPlan_Request = {
  "dwb_msgs::srv",
  "DebugLocalPlan_Request",
  _DebugLocalPlan_Request__cdr_serialize,
  _DebugLocalPlan_Request__cdr_deserialize,
  _DebugLocalPlan_Request__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__DebugLocalPlan_Request,
  _DebugLocalPlan_Request__max_serialized_size
};

static rosidl_message_type_support_t _DebugLocalPlan_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_DebugLocalPlan_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, DebugLocalPlan_Request)() {
  return &_DebugLocalPlan_Request__type_support;
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
// #include "dwb_msgs/srv/detail/debug_local_plan__struct.h"
// already included above
// #include "dwb_msgs/srv/detail/debug_local_plan__functions.h"

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

#include "dwb_msgs/msg/detail/local_plan_evaluation__functions.h"  // results

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, LocalPlanEvaluation)();


typedef dwb_msgs__srv__DebugLocalPlan_Response _DebugLocalPlan_Response__ros_msg_type;

static bool _DebugLocalPlan_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _DebugLocalPlan_Response__ros_msg_type * ros_message = (_DebugLocalPlan_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: results
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, LocalPlanEvaluation
      )()->data))->cdr_serialize(&ros_message->results, cdr);

  return rv;
}

static bool _DebugLocalPlan_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _DebugLocalPlan_Response__ros_msg_type * ros_message = (_DebugLocalPlan_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: results
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, LocalPlanEvaluation
      )()->data))->cdr_deserialize(cdr, &ros_message->results);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__DebugLocalPlan_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _DebugLocalPlan_Response__ros_msg_type * ros_message = (const _DebugLocalPlan_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: results
  current_alignment +=
    get_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(&ros_message->results, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _DebugLocalPlan_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__srv__DebugLocalPlan_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__DebugLocalPlan_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: results
  current_alignment +=
    max_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _DebugLocalPlan_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__srv__DebugLocalPlan_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_DebugLocalPlan_Response = {
  "dwb_msgs::srv",
  "DebugLocalPlan_Response",
  _DebugLocalPlan_Response__cdr_serialize,
  _DebugLocalPlan_Response__cdr_deserialize,
  _DebugLocalPlan_Response__get_serialized_size,
  get_serialized_size_dwb_msgs__srv__DebugLocalPlan_Response,
  _DebugLocalPlan_Response__max_serialized_size
};

static rosidl_message_type_support_t _DebugLocalPlan_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_DebugLocalPlan_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, DebugLocalPlan_Response)() {
  return &_DebugLocalPlan_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/srv/debug_local_plan.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t DebugLocalPlan__callbacks = {
  "dwb_msgs::srv",
  "DebugLocalPlan",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, DebugLocalPlan_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, DebugLocalPlan_Response),
};

static rosidl_service_type_support_t DebugLocalPlan__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &DebugLocalPlan__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, srv, DebugLocalPlan)() {
  return &DebugLocalPlan__handle;
}

#if defined(__cplusplus)
}
#endif
