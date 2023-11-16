// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeTelemetry.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__functions.h"

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


typedef marvelmind_ros2_msgs__msg__HedgeTelemetry _HedgeTelemetry__ros_msg_type;

static bool _HedgeTelemetry__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _HedgeTelemetry__ros_msg_type * ros_message = (_HedgeTelemetry__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: battery_voltage
  rv = ucdr_serialize_double(cdr, ros_message->battery_voltage);
  // Member: rssi_dbm
  rv = ucdr_serialize_int8_t(cdr, ros_message->rssi_dbm);

  return rv;
}

static bool _HedgeTelemetry__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _HedgeTelemetry__ros_msg_type * ros_message = (_HedgeTelemetry__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: battery_voltage
  rv = ucdr_deserialize_double(cdr, &ros_message->battery_voltage);
  // Field name: rssi_dbm
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->rssi_dbm);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgeTelemetry(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _HedgeTelemetry__ros_msg_type * ros_message = (const _HedgeTelemetry__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: battery_voltage
  {
    const size_t item_size = sizeof(ros_message->battery_voltage);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: rssi_dbm
  {
    const size_t item_size = sizeof(ros_message->rssi_dbm);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgeTelemetry__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgeTelemetry(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgeTelemetry(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: battery_voltage
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: rssi_dbm
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);

  return current_alignment - initial_alignment;
}

static size_t _HedgeTelemetry__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgeTelemetry(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_HedgeTelemetry = {
  "marvelmind_ros2_msgs::msg",
  "HedgeTelemetry",
  _HedgeTelemetry__cdr_serialize,
  _HedgeTelemetry__cdr_deserialize,
  _HedgeTelemetry__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__msg__HedgeTelemetry,
  _HedgeTelemetry__max_serialized_size
};

static rosidl_message_type_support_t _HedgeTelemetry__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_HedgeTelemetry,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, msg, HedgeTelemetry)() {
  return &_HedgeTelemetry__type_support;
}

#if defined(__cplusplus)
}
#endif
