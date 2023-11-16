// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:msg/SpeedLimit.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/speed_limit__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/msg/detail/speed_limit__struct.h"
#include "nav2_msgs/msg/detail/speed_limit__functions.h"

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

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef nav2_msgs__msg__SpeedLimit _SpeedLimit__ros_msg_type;

static bool _SpeedLimit__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _SpeedLimit__ros_msg_type * ros_message = (_SpeedLimit__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: percentage
  rv = ucdr_serialize_bool(cdr, (ros_message->percentage) ? 0x01 : 0x00);
  // Member: speed_limit
  rv = ucdr_serialize_double(cdr, ros_message->speed_limit);

  return rv;
}

static bool _SpeedLimit__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _SpeedLimit__ros_msg_type * ros_message = (_SpeedLimit__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: percentage
  rv = ucdr_deserialize_bool(cdr, &ros_message->percentage);
  // Field name: speed_limit
  rv = ucdr_deserialize_double(cdr, &ros_message->speed_limit);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__SpeedLimit(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _SpeedLimit__ros_msg_type * ros_message = (const _SpeedLimit__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: percentage
  {
    const size_t item_size = sizeof(ros_message->percentage);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: speed_limit
  {
    const size_t item_size = sizeof(ros_message->speed_limit);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SpeedLimit__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__msg__SpeedLimit(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__SpeedLimit(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: percentage
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: speed_limit
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);

  return current_alignment - initial_alignment;
}

static size_t _SpeedLimit__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__msg__SpeedLimit(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_SpeedLimit = {
  "nav2_msgs::msg",
  "SpeedLimit",
  _SpeedLimit__cdr_serialize,
  _SpeedLimit__cdr_deserialize,
  _SpeedLimit__get_serialized_size,
  get_serialized_size_nav2_msgs__msg__SpeedLimit,
  _SpeedLimit__max_serialized_size
};

static rosidl_message_type_support_t _SpeedLimit__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_SpeedLimit,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, SpeedLimit)() {
  return &_SpeedLimit__type_support;
}

#if defined(__cplusplus)
}
#endif
