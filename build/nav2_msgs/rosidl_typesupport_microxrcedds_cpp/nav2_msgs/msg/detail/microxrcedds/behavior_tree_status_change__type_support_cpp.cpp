// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:msg/BehaviorTreeStatusChange.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/behavior_tree_status_change__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "nav2_msgs/msg/detail/behavior_tree_status_change__struct.hpp"

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
namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  builtin_interfaces::msg::Time &);

size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);

size_t
max_serialized_size_Time(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace nav2_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::msg::BehaviorTreeStatusChange & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: timestamp
  rv = builtin_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.timestamp,
    cdr);
  // Member: node_name
  rv = ucdr_serialize_string(cdr, ros_message.node_name.c_str());
  // Member: previous_status
  rv = ucdr_serialize_string(cdr, ros_message.previous_status.c_str());
  // Member: current_status
  rv = ucdr_serialize_string(cdr, ros_message.current_status.c_str());

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::msg::BehaviorTreeStatusChange & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: timestamp
  rv = builtin_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.timestamp);
  // Member: node_name
  ros_message.node_name.resize(ros_message.node_name.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.node_name[0], ros_message.node_name.capacity());
  if (rv) {
    ros_message.node_name.resize(std::strlen(&ros_message.node_name[0]));
  }
  // Member: previous_status
  ros_message.previous_status.resize(ros_message.previous_status.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.previous_status[0], ros_message.previous_status.capacity());
  if (rv) {
    ros_message.previous_status.resize(std::strlen(&ros_message.previous_status[0]));
  }
  // Member: current_status
  ros_message.current_status.resize(ros_message.current_status.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.current_status[0], ros_message.current_status.capacity());
  if (rv) {
    ros_message.current_status.resize(std::strlen(&ros_message.current_status[0]));
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::msg::BehaviorTreeStatusChange & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp
  current_alignment += builtin_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.timestamp,
    current_alignment);
  // Member: node_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.node_name.size() + 1;
  // Member: previous_status
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.previous_status.size() + 1;
  // Member: current_status
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.current_status.size() + 1;

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_BehaviorTreeStatusChange(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp
  current_alignment += builtin_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_Time(
    full_bounded,
    current_alignment);
  // Member: node_name
  *full_bounded = false;
  // Member: previous_status
  *full_bounded = false;
  // Member: current_status
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static bool _BehaviorTreeStatusChange__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::BehaviorTreeStatusChange *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BehaviorTreeStatusChange__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::msg::BehaviorTreeStatusChange *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BehaviorTreeStatusChange__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::BehaviorTreeStatusChange *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BehaviorTreeStatusChange__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::BehaviorTreeStatusChange *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _BehaviorTreeStatusChange__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_BehaviorTreeStatusChange(&full_bounded, 0);
}

static message_type_support_callbacks_t _BehaviorTreeStatusChange__callbacks = {
  "nav2_msgs::msg",
  "BehaviorTreeStatusChange",
  _BehaviorTreeStatusChange__cdr_serialize,
  _BehaviorTreeStatusChange__cdr_deserialize,
  _BehaviorTreeStatusChange__get_serialized_size,
  _BehaviorTreeStatusChange__get_serialized_size_with_initial_alignment,
  _BehaviorTreeStatusChange__max_serialized_size
};

static rosidl_message_type_support_t _BehaviorTreeStatusChange__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_BehaviorTreeStatusChange__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::msg::BehaviorTreeStatusChange>()
{
  return &nav2_msgs::msg::typesupport_microxrcedds_cpp::_BehaviorTreeStatusChange__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, msg, BehaviorTreeStatusChange)() {
  return &nav2_msgs::msg::typesupport_microxrcedds_cpp::_BehaviorTreeStatusChange__handle;
}

#ifdef __cplusplus
}
#endif
