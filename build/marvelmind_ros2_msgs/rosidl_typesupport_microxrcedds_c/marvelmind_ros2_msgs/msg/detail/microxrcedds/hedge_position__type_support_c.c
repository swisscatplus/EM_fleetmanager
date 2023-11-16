// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:msg/HedgePosition.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__functions.h"

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


typedef marvelmind_ros2_msgs__msg__HedgePosition _HedgePosition__ros_msg_type;

static bool _HedgePosition__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _HedgePosition__ros_msg_type * ros_message = (_HedgePosition__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: timestamp_ms
  rv = ucdr_serialize_int64_t(cdr, ros_message->timestamp_ms);
  // Member: x_m
  rv = ucdr_serialize_double(cdr, ros_message->x_m);
  // Member: y_m
  rv = ucdr_serialize_double(cdr, ros_message->y_m);
  // Member: z_m
  rv = ucdr_serialize_double(cdr, ros_message->z_m);
  // Member: flags
  rv = ucdr_serialize_uint8_t(cdr, ros_message->flags);

  return rv;
}

static bool _HedgePosition__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _HedgePosition__ros_msg_type * ros_message = (_HedgePosition__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: timestamp_ms
  rv = ucdr_deserialize_int64_t(cdr, &ros_message->timestamp_ms);
  // Field name: x_m
  rv = ucdr_deserialize_double(cdr, &ros_message->x_m);
  // Field name: y_m
  rv = ucdr_deserialize_double(cdr, &ros_message->y_m);
  // Field name: z_m
  rv = ucdr_deserialize_double(cdr, &ros_message->z_m);
  // Field name: flags
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->flags);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _HedgePosition__ros_msg_type * ros_message = (const _HedgePosition__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  {
    const size_t item_size = sizeof(ros_message->timestamp_ms);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: x_m
  {
    const size_t item_size = sizeof(ros_message->x_m);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: y_m
  {
    const size_t item_size = sizeof(ros_message->y_m);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: z_m
  {
    const size_t item_size = sizeof(ros_message->z_m);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: flags
  {
    const size_t item_size = sizeof(ros_message->flags);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgePosition__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: x_m
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: y_m
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: z_m
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: flags
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static size_t _HedgePosition__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_HedgePosition = {
  "marvelmind_ros2_msgs::msg",
  "HedgePosition",
  _HedgePosition__cdr_serialize,
  _HedgePosition__cdr_deserialize,
  _HedgePosition__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition,
  _HedgePosition__max_serialized_size
};

static rosidl_message_type_support_t _HedgePosition__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_HedgePosition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, msg, HedgePosition)() {
  return &_HedgePosition__type_support;
}

#if defined(__cplusplus)
}
#endif
