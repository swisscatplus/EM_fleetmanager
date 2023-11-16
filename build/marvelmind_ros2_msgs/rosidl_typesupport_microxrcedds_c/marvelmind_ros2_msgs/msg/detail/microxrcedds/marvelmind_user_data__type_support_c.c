// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindUserData.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_user_data__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_user_data__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_user_data__functions.h"

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

#include "rosidl_runtime_c/primitives_sequence.h"  // data
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data

// forward declare type support functions


typedef marvelmind_ros2_msgs__msg__MarvelmindUserData _MarvelmindUserData__ros_msg_type;

static bool _MarvelmindUserData__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _MarvelmindUserData__ros_msg_type * ros_message = (_MarvelmindUserData__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: timestamp_ms
  rv = ucdr_serialize_int64_t(cdr, ros_message->timestamp_ms);
  // Member: data
  {
    const size_t size = ros_message->data.size;
    rv = ucdr_serialize_sequence_uint8_t(cdr, ros_message->data.data, size);
  }

  return rv;
}

static bool _MarvelmindUserData__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _MarvelmindUserData__ros_msg_type * ros_message = (_MarvelmindUserData__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: timestamp_ms
  rv = ucdr_deserialize_int64_t(cdr, &ros_message->timestamp_ms);
  // Field name: data
  {
    uint32_t size;
    const size_t capacity = ros_message->data.capacity;
    rv = ucdr_deserialize_sequence_uint8_t(cdr, ros_message->data.data, capacity, &size);
    if (rv) {
      ros_message->data.size = size;
    } else if(size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->data.size = 0;
      ucdr_align_to(cdr, sizeof(uint8_t));
      ucdr_advance_buffer(cdr, size * sizeof(uint8_t));
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindUserData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _MarvelmindUserData__ros_msg_type * ros_message = (const _MarvelmindUserData__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  {
    const size_t item_size = sizeof(ros_message->timestamp_ms);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: data
  {
    size_t sequence_size = ros_message->data.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    if (0 < sequence_size) {
      size_t item_size = sizeof(ros_message->data.data[0]);
      current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MarvelmindUserData__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindUserData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindUserData(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: data
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _MarvelmindUserData__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindUserData(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_MarvelmindUserData = {
  "marvelmind_ros2_msgs::msg",
  "MarvelmindUserData",
  _MarvelmindUserData__cdr_serialize,
  _MarvelmindUserData__cdr_deserialize,
  _MarvelmindUserData__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindUserData,
  _MarvelmindUserData__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindUserData__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_MarvelmindUserData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, msg, MarvelmindUserData)() {
  return &_MarvelmindUserData__type_support;
}

#if defined(__cplusplus)
}
#endif
