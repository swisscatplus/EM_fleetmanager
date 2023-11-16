// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeQuality.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__functions.h"

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


typedef marvelmind_ros2_msgs__msg__HedgeQuality _HedgeQuality__ros_msg_type;

static bool _HedgeQuality__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _HedgeQuality__ros_msg_type * ros_message = (_HedgeQuality__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: address
  rv = ucdr_serialize_uint8_t(cdr, ros_message->address);
  // Member: quality_percents
  rv = ucdr_serialize_uint8_t(cdr, ros_message->quality_percents);

  return rv;
}

static bool _HedgeQuality__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _HedgeQuality__ros_msg_type * ros_message = (_HedgeQuality__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: address
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->address);
  // Field name: quality_percents
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->quality_percents);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _HedgeQuality__ros_msg_type * ros_message = (const _HedgeQuality__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: address
  {
    const size_t item_size = sizeof(ros_message->address);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: quality_percents
  {
    const size_t item_size = sizeof(ros_message->quality_percents);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgeQuality__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: address
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: quality_percents
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static size_t _HedgeQuality__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_HedgeQuality = {
  "marvelmind_ros2_msgs::msg",
  "HedgeQuality",
  _HedgeQuality__cdr_serialize,
  _HedgeQuality__cdr_deserialize,
  _HedgeQuality__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality,
  _HedgeQuality__max_serialized_size
};

static rosidl_message_type_support_t _HedgeQuality__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_HedgeQuality,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, msg, HedgeQuality)() {
  return &_HedgeQuality__type_support;
}

#if defined(__cplusplus)
}
#endif
