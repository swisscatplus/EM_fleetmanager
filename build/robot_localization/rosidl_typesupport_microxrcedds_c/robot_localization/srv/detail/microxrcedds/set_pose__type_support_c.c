// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from robot_localization:srv/SetPose.idl
// generated code does not contain a copyright notice
#include "robot_localization/srv/detail/set_pose__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/detail/set_pose__struct.h"
#include "robot_localization/srv/detail/set_pose__functions.h"

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

#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__functions.h"  // pose

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t get_serialized_size_geometry_msgs__msg__PoseWithCovarianceStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t max_serialized_size_geometry_msgs__msg__PoseWithCovarianceStamped(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseWithCovarianceStamped)();


typedef robot_localization__srv__SetPose_Request _SetPose_Request__ros_msg_type;

static bool _SetPose_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _SetPose_Request__ros_msg_type * ros_message = (_SetPose_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseWithCovarianceStamped
      )()->data))->cdr_serialize(&ros_message->pose, cdr);

  return rv;
}

static bool _SetPose_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _SetPose_Request__ros_msg_type * ros_message = (_SetPose_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseWithCovarianceStamped
      )()->data))->cdr_deserialize(cdr, &ros_message->pose);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__SetPose_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _SetPose_Request__ros_msg_type * ros_message = (const _SetPose_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__PoseWithCovarianceStamped(&ros_message->pose, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _SetPose_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__SetPose_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__SetPose_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__PoseWithCovarianceStamped(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _SetPose_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__SetPose_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_SetPose_Request = {
  "robot_localization::srv",
  "SetPose_Request",
  _SetPose_Request__cdr_serialize,
  _SetPose_Request__cdr_deserialize,
  _SetPose_Request__get_serialized_size,
  get_serialized_size_robot_localization__srv__SetPose_Request,
  _SetPose_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetPose_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_SetPose_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, SetPose_Request)() {
  return &_SetPose_Request__type_support;
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
// #include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "robot_localization/srv/detail/set_pose__struct.h"
// already included above
// #include "robot_localization/srv/detail/set_pose__functions.h"

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


// forward declare type support functions


typedef robot_localization__srv__SetPose_Response _SetPose_Response__ros_msg_type;

static bool _SetPose_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _SetPose_Response__ros_msg_type * ros_message = (_SetPose_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_serialize_uint8_t(cdr, ros_message->structure_needs_at_least_one_member);

  return rv;
}

static bool _SetPose_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _SetPose_Response__ros_msg_type * ros_message = (_SetPose_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: structure_needs_at_least_one_member
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->structure_needs_at_least_one_member);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__SetPose_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _SetPose_Response__ros_msg_type * ros_message = (const _SetPose_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  {
    const size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SetPose_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__SetPose_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__SetPose_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static size_t _SetPose_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__SetPose_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_SetPose_Response = {
  "robot_localization::srv",
  "SetPose_Response",
  _SetPose_Response__cdr_serialize,
  _SetPose_Response__cdr_deserialize,
  _SetPose_Response__get_serialized_size,
  get_serialized_size_robot_localization__srv__SetPose_Response,
  _SetPose_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetPose_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_SetPose_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, SetPose_Response)() {
  return &_SetPose_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/set_pose.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SetPose__callbacks = {
  "robot_localization::srv",
  "SetPose",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, SetPose_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, SetPose_Response),
};

static rosidl_service_type_support_t SetPose__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &SetPose__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, SetPose)() {
  return &SetPose__handle;
}

#if defined(__cplusplus)
}
#endif
