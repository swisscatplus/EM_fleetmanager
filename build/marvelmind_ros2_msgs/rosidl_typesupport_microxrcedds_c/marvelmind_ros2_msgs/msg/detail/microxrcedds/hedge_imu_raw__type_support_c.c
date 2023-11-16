// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__functions.h"

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


typedef marvelmind_ros2_msgs__msg__HedgeImuRaw _HedgeImuRaw__ros_msg_type;

static bool _HedgeImuRaw__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _HedgeImuRaw__ros_msg_type * ros_message = (_HedgeImuRaw__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: timestamp_ms
  rv = ucdr_serialize_int64_t(cdr, ros_message->timestamp_ms);
  // Member: acc_x
  rv = ucdr_serialize_int16_t(cdr, ros_message->acc_x);
  // Member: acc_y
  rv = ucdr_serialize_int16_t(cdr, ros_message->acc_y);
  // Member: acc_z
  rv = ucdr_serialize_int16_t(cdr, ros_message->acc_z);
  // Member: gyro_x
  rv = ucdr_serialize_int16_t(cdr, ros_message->gyro_x);
  // Member: gyro_y
  rv = ucdr_serialize_int16_t(cdr, ros_message->gyro_y);
  // Member: gyro_z
  rv = ucdr_serialize_int16_t(cdr, ros_message->gyro_z);
  // Member: compass_x
  rv = ucdr_serialize_int16_t(cdr, ros_message->compass_x);
  // Member: compass_y
  rv = ucdr_serialize_int16_t(cdr, ros_message->compass_y);
  // Member: compass_z
  rv = ucdr_serialize_int16_t(cdr, ros_message->compass_z);

  return rv;
}

static bool _HedgeImuRaw__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _HedgeImuRaw__ros_msg_type * ros_message = (_HedgeImuRaw__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: timestamp_ms
  rv = ucdr_deserialize_int64_t(cdr, &ros_message->timestamp_ms);
  // Field name: acc_x
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->acc_x);
  // Field name: acc_y
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->acc_y);
  // Field name: acc_z
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->acc_z);
  // Field name: gyro_x
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->gyro_x);
  // Field name: gyro_y
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->gyro_y);
  // Field name: gyro_z
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->gyro_z);
  // Field name: compass_x
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->compass_x);
  // Field name: compass_y
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->compass_y);
  // Field name: compass_z
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->compass_z);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuRaw(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _HedgeImuRaw__ros_msg_type * ros_message = (const _HedgeImuRaw__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  {
    const size_t item_size = sizeof(ros_message->timestamp_ms);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: acc_x
  {
    const size_t item_size = sizeof(ros_message->acc_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: acc_y
  {
    const size_t item_size = sizeof(ros_message->acc_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: acc_z
  {
    const size_t item_size = sizeof(ros_message->acc_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: gyro_x
  {
    const size_t item_size = sizeof(ros_message->gyro_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: gyro_y
  {
    const size_t item_size = sizeof(ros_message->gyro_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: gyro_z
  {
    const size_t item_size = sizeof(ros_message->gyro_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compass_x
  {
    const size_t item_size = sizeof(ros_message->compass_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compass_y
  {
    const size_t item_size = sizeof(ros_message->compass_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compass_z
  {
    const size_t item_size = sizeof(ros_message->compass_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgeImuRaw__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuRaw(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuRaw(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: acc_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: acc_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: acc_z
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: gyro_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: gyro_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: gyro_z
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: compass_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: compass_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: compass_z
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);

  return current_alignment - initial_alignment;
}

static size_t _HedgeImuRaw__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuRaw(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_HedgeImuRaw = {
  "marvelmind_ros2_msgs::msg",
  "HedgeImuRaw",
  _HedgeImuRaw__cdr_serialize,
  _HedgeImuRaw__cdr_deserialize,
  _HedgeImuRaw__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuRaw,
  _HedgeImuRaw__max_serialized_size
};

static rosidl_message_type_support_t _HedgeImuRaw__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_HedgeImuRaw,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, msg, HedgeImuRaw)() {
  return &_HedgeImuRaw__type_support;
}

#if defined(__cplusplus)
}
#endif
