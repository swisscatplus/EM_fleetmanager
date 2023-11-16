// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav_2d_msgs:msg/Pose2DStamped.idl
// generated code does not contain a copyright notice
#include "nav_2d_msgs/msg/detail/pose2_d_stamped__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav_2d_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav_2d_msgs/msg/detail/pose2_d_stamped__struct.h"
#include "nav_2d_msgs/msg/detail/pose2_d_stamped__functions.h"

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

#include "geometry_msgs/msg/detail/pose2_d__functions.h"  // pose
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav_2d_msgs
size_t get_serialized_size_geometry_msgs__msg__Pose2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav_2d_msgs
size_t max_serialized_size_geometry_msgs__msg__Pose2D(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav_2d_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose2D)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav_2d_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav_2d_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav_2d_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef nav_2d_msgs__msg__Pose2DStamped _Pose2DStamped__ros_msg_type;

static bool _Pose2DStamped__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Pose2DStamped__ros_msg_type * ros_message = (_Pose2DStamped__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose2D
      )()->data))->cdr_serialize(&ros_message->pose, cdr);

  return rv;
}

static bool _Pose2DStamped__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Pose2DStamped__ros_msg_type * ros_message = (_Pose2DStamped__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose2D
      )()->data))->cdr_deserialize(cdr, &ros_message->pose);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav_2d_msgs
size_t get_serialized_size_nav_2d_msgs__msg__Pose2DStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Pose2DStamped__ros_msg_type * ros_message = (const _Pose2DStamped__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: pose
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Pose2D(&ros_message->pose, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Pose2DStamped__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav_2d_msgs__msg__Pose2DStamped(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav_2d_msgs
size_t max_serialized_size_nav_2d_msgs__msg__Pose2DStamped(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: pose
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Pose2D(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Pose2DStamped__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav_2d_msgs__msg__Pose2DStamped(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Pose2DStamped = {
  "nav_2d_msgs::msg",
  "Pose2DStamped",
  _Pose2DStamped__cdr_serialize,
  _Pose2DStamped__cdr_deserialize,
  _Pose2DStamped__get_serialized_size,
  get_serialized_size_nav_2d_msgs__msg__Pose2DStamped,
  _Pose2DStamped__max_serialized_size
};

static rosidl_message_type_support_t _Pose2DStamped__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Pose2DStamped,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_2d_msgs, msg, Pose2DStamped)() {
  return &_Pose2DStamped__type_support;
}

#if defined(__cplusplus)
}
#endif
