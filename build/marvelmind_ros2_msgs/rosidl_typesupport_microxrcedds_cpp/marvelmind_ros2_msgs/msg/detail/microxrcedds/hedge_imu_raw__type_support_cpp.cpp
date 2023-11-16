// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__struct.hpp"

#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstring>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
#include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions

namespace marvelmind_ros2_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_serialize(
  const marvelmind_ros2_msgs::msg::HedgeImuRaw & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: timestamp_ms
  rv = ucdr_serialize_int64_t(cdr, ros_message.timestamp_ms);
  // Member: acc_x
  rv = ucdr_serialize_int16_t(cdr, ros_message.acc_x);
  // Member: acc_y
  rv = ucdr_serialize_int16_t(cdr, ros_message.acc_y);
  // Member: acc_z
  rv = ucdr_serialize_int16_t(cdr, ros_message.acc_z);
  // Member: gyro_x
  rv = ucdr_serialize_int16_t(cdr, ros_message.gyro_x);
  // Member: gyro_y
  rv = ucdr_serialize_int16_t(cdr, ros_message.gyro_y);
  // Member: gyro_z
  rv = ucdr_serialize_int16_t(cdr, ros_message.gyro_z);
  // Member: compass_x
  rv = ucdr_serialize_int16_t(cdr, ros_message.compass_x);
  // Member: compass_y
  rv = ucdr_serialize_int16_t(cdr, ros_message.compass_y);
  // Member: compass_z
  rv = ucdr_serialize_int16_t(cdr, ros_message.compass_z);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  marvelmind_ros2_msgs::msg::HedgeImuRaw & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: timestamp_ms
  rv = ucdr_deserialize_int64_t(cdr, &ros_message.timestamp_ms);
  // Member: acc_x
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.acc_x);
  // Member: acc_y
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.acc_y);
  // Member: acc_z
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.acc_z);
  // Member: gyro_x
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.gyro_x);
  // Member: gyro_y
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.gyro_y);
  // Member: gyro_z
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.gyro_z);
  // Member: compass_x
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.compass_x);
  // Member: compass_y
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.compass_y);
  // Member: compass_z
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.compass_z);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::msg::HedgeImuRaw & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp_ms
  {
    const size_t item_size = sizeof(ros_message.timestamp_ms);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: acc_x
  {
    const size_t item_size = sizeof(ros_message.acc_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: acc_y
  {
    const size_t item_size = sizeof(ros_message.acc_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: acc_z
  {
    const size_t item_size = sizeof(ros_message.acc_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: gyro_x
  {
    const size_t item_size = sizeof(ros_message.gyro_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: gyro_y
  {
    const size_t item_size = sizeof(ros_message.gyro_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: gyro_z
  {
    const size_t item_size = sizeof(ros_message.gyro_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compass_x
  {
    const size_t item_size = sizeof(ros_message.compass_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compass_y
  {
    const size_t item_size = sizeof(ros_message.compass_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compass_z
  {
    const size_t item_size = sizeof(ros_message.compass_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_HedgeImuRaw(
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

static bool _HedgeImuRaw__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HedgeImuRaw__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HedgeImuRaw__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HedgeImuRaw__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _HedgeImuRaw__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_HedgeImuRaw(&full_bounded, 0);
}

static message_type_support_callbacks_t _HedgeImuRaw__callbacks = {
  "marvelmind_ros2_msgs::msg",
  "HedgeImuRaw",
  _HedgeImuRaw__cdr_serialize,
  _HedgeImuRaw__cdr_deserialize,
  _HedgeImuRaw__get_serialized_size,
  _HedgeImuRaw__get_serialized_size_with_initial_alignment,
  _HedgeImuRaw__max_serialized_size
};

static rosidl_message_type_support_t _HedgeImuRaw__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_HedgeImuRaw__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace marvelmind_ros2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_marvelmind_ros2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<marvelmind_ros2_msgs::msg::HedgeImuRaw>()
{
  return &marvelmind_ros2_msgs::msg::typesupport_microxrcedds_cpp::_HedgeImuRaw__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, msg, HedgeImuRaw)() {
  return &marvelmind_ros2_msgs::msg::typesupport_microxrcedds_cpp::_HedgeImuRaw__handle;
}

#ifdef __cplusplus
}
#endif
