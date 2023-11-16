// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuFusion.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__functions.h"

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


typedef marvelmind_ros2_msgs__msg__HedgeImuFusion _HedgeImuFusion__ros_msg_type;

static bool _HedgeImuFusion__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _HedgeImuFusion__ros_msg_type * ros_message = (_HedgeImuFusion__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: timestamp_ms
  rv = ucdr_serialize_int64_t(cdr, ros_message->timestamp_ms);
  // Member: x_m
  rv = ucdr_serialize_double(cdr, ros_message->x_m);
  // Member: y_m
  rv = ucdr_serialize_double(cdr, ros_message->y_m);
  // Member: z_m
  rv = ucdr_serialize_double(cdr, ros_message->z_m);
  // Member: qw
  rv = ucdr_serialize_double(cdr, ros_message->qw);
  // Member: qx
  rv = ucdr_serialize_double(cdr, ros_message->qx);
  // Member: qy
  rv = ucdr_serialize_double(cdr, ros_message->qy);
  // Member: qz
  rv = ucdr_serialize_double(cdr, ros_message->qz);
  // Member: vx
  rv = ucdr_serialize_double(cdr, ros_message->vx);
  // Member: vy
  rv = ucdr_serialize_double(cdr, ros_message->vy);
  // Member: vz
  rv = ucdr_serialize_double(cdr, ros_message->vz);
  // Member: ax
  rv = ucdr_serialize_double(cdr, ros_message->ax);
  // Member: ay
  rv = ucdr_serialize_double(cdr, ros_message->ay);
  // Member: az
  rv = ucdr_serialize_double(cdr, ros_message->az);

  return rv;
}

static bool _HedgeImuFusion__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _HedgeImuFusion__ros_msg_type * ros_message = (_HedgeImuFusion__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: timestamp_ms
  rv = ucdr_deserialize_int64_t(cdr, &ros_message->timestamp_ms);
  // Field name: x_m
  rv = ucdr_deserialize_double(cdr, &ros_message->x_m);
  // Field name: y_m
  rv = ucdr_deserialize_double(cdr, &ros_message->y_m);
  // Field name: z_m
  rv = ucdr_deserialize_double(cdr, &ros_message->z_m);
  // Field name: qw
  rv = ucdr_deserialize_double(cdr, &ros_message->qw);
  // Field name: qx
  rv = ucdr_deserialize_double(cdr, &ros_message->qx);
  // Field name: qy
  rv = ucdr_deserialize_double(cdr, &ros_message->qy);
  // Field name: qz
  rv = ucdr_deserialize_double(cdr, &ros_message->qz);
  // Field name: vx
  rv = ucdr_deserialize_double(cdr, &ros_message->vx);
  // Field name: vy
  rv = ucdr_deserialize_double(cdr, &ros_message->vy);
  // Field name: vz
  rv = ucdr_deserialize_double(cdr, &ros_message->vz);
  // Field name: ax
  rv = ucdr_deserialize_double(cdr, &ros_message->ax);
  // Field name: ay
  rv = ucdr_deserialize_double(cdr, &ros_message->ay);
  // Field name: az
  rv = ucdr_deserialize_double(cdr, &ros_message->az);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuFusion(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _HedgeImuFusion__ros_msg_type * ros_message = (const _HedgeImuFusion__ros_msg_type *)(untyped_ros_message);
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
  // Member: qw
  {
    const size_t item_size = sizeof(ros_message->qw);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: qx
  {
    const size_t item_size = sizeof(ros_message->qx);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: qy
  {
    const size_t item_size = sizeof(ros_message->qy);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: qz
  {
    const size_t item_size = sizeof(ros_message->qz);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: vx
  {
    const size_t item_size = sizeof(ros_message->vx);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: vy
  {
    const size_t item_size = sizeof(ros_message->vy);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: vz
  {
    const size_t item_size = sizeof(ros_message->vz);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: ax
  {
    const size_t item_size = sizeof(ros_message->ax);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: ay
  {
    const size_t item_size = sizeof(ros_message->ay);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: az
  {
    const size_t item_size = sizeof(ros_message->az);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgeImuFusion__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuFusion(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuFusion(
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
  // Member: qw
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: qx
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: qy
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: qz
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: vx
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: vy
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: vz
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: ax
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: ay
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: az
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);

  return current_alignment - initial_alignment;
}

static size_t _HedgeImuFusion__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuFusion(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_HedgeImuFusion = {
  "marvelmind_ros2_msgs::msg",
  "HedgeImuFusion",
  _HedgeImuFusion__cdr_serialize,
  _HedgeImuFusion__cdr_deserialize,
  _HedgeImuFusion__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__msg__HedgeImuFusion,
  _HedgeImuFusion__max_serialized_size
};

static rosidl_message_type_support_t _HedgeImuFusion__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_HedgeImuFusion,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, msg, HedgeImuFusion)() {
  return &_HedgeImuFusion__type_support;
}

#if defined(__cplusplus)
}
#endif
