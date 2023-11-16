// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindWaypoint.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__struct.hpp"

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
  const marvelmind_ros2_msgs::msg::MarvelmindWaypoint & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: total_items
  rv = ucdr_serialize_uint8_t(cdr, ros_message.total_items);
  // Member: item_index
  rv = ucdr_serialize_uint8_t(cdr, ros_message.item_index);
  // Member: movement_type
  rv = ucdr_serialize_uint8_t(cdr, ros_message.movement_type);
  // Member: param1
  rv = ucdr_serialize_int16_t(cdr, ros_message.param1);
  // Member: param2
  rv = ucdr_serialize_int16_t(cdr, ros_message.param2);
  // Member: param3
  rv = ucdr_serialize_int16_t(cdr, ros_message.param3);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  marvelmind_ros2_msgs::msg::MarvelmindWaypoint & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: total_items
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message.total_items);
  // Member: item_index
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message.item_index);
  // Member: movement_type
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message.movement_type);
  // Member: param1
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.param1);
  // Member: param2
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.param2);
  // Member: param3
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.param3);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::msg::MarvelmindWaypoint & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: total_items
  {
    const size_t item_size = sizeof(ros_message.total_items);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: item_index
  {
    const size_t item_size = sizeof(ros_message.item_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: movement_type
  {
    const size_t item_size = sizeof(ros_message.movement_type);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: param1
  {
    const size_t item_size = sizeof(ros_message.param1);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: param2
  {
    const size_t item_size = sizeof(ros_message.param2);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: param3
  {
    const size_t item_size = sizeof(ros_message.param3);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_MarvelmindWaypoint(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: total_items
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: item_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: movement_type
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: param1
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: param2
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: param3
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);

  return current_alignment - initial_alignment;
}

static bool _MarvelmindWaypoint__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MarvelmindWaypoint__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MarvelmindWaypoint__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MarvelmindWaypoint__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _MarvelmindWaypoint__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_MarvelmindWaypoint(&full_bounded, 0);
}

static message_type_support_callbacks_t _MarvelmindWaypoint__callbacks = {
  "marvelmind_ros2_msgs::msg",
  "MarvelmindWaypoint",
  _MarvelmindWaypoint__cdr_serialize,
  _MarvelmindWaypoint__cdr_deserialize,
  _MarvelmindWaypoint__get_serialized_size,
  _MarvelmindWaypoint__get_serialized_size_with_initial_alignment,
  _MarvelmindWaypoint__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindWaypoint__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_MarvelmindWaypoint__callbacks,
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
get_message_type_support_handle<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>()
{
  return &marvelmind_ros2_msgs::msg::typesupport_microxrcedds_cpp::_MarvelmindWaypoint__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, msg, MarvelmindWaypoint)() {
  return &marvelmind_ros2_msgs::msg::typesupport_microxrcedds_cpp::_MarvelmindWaypoint__handle;
}

#ifdef __cplusplus
}
#endif
