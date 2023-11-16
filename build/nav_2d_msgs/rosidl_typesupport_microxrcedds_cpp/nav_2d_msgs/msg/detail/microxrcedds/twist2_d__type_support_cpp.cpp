// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from nav_2d_msgs:msg/Twist2D.idl
// generated code does not contain a copyright notice
#include "nav_2d_msgs/msg/detail/twist2_d__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "nav_2d_msgs/msg/detail/twist2_d__struct.hpp"

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

namespace nav_2d_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav_2d_msgs
cdr_serialize(
  const nav_2d_msgs::msg::Twist2D & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: x
  rv = ucdr_serialize_double(cdr, ros_message.x);
  // Member: y
  rv = ucdr_serialize_double(cdr, ros_message.y);
  // Member: theta
  rv = ucdr_serialize_double(cdr, ros_message.theta);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav_2d_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav_2d_msgs::msg::Twist2D & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: x
  rv = ucdr_deserialize_double(cdr, &ros_message.x);
  // Member: y
  rv = ucdr_deserialize_double(cdr, &ros_message.y);
  // Member: theta
  rv = ucdr_deserialize_double(cdr, &ros_message.theta);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav_2d_msgs
get_serialized_size(
  const nav_2d_msgs::msg::Twist2D & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: x
  {
    const size_t item_size = sizeof(ros_message.x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: y
  {
    const size_t item_size = sizeof(ros_message.y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: theta
  {
    const size_t item_size = sizeof(ros_message.theta);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav_2d_msgs
max_serialized_size_Twist2D(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: x
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: y
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: theta
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);

  return current_alignment - initial_alignment;
}

static bool _Twist2D__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav_2d_msgs::msg::Twist2D *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Twist2D__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav_2d_msgs::msg::Twist2D *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Twist2D__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav_2d_msgs::msg::Twist2D *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Twist2D__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav_2d_msgs::msg::Twist2D *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _Twist2D__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_Twist2D(&full_bounded, 0);
}

static message_type_support_callbacks_t _Twist2D__callbacks = {
  "nav_2d_msgs::msg",
  "Twist2D",
  _Twist2D__cdr_serialize,
  _Twist2D__cdr_deserialize,
  _Twist2D__get_serialized_size,
  _Twist2D__get_serialized_size_with_initial_alignment,
  _Twist2D__max_serialized_size
};

static rosidl_message_type_support_t _Twist2D__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_Twist2D__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace nav_2d_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav_2d_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_2d_msgs::msg::Twist2D>()
{
  return &nav_2d_msgs::msg::typesupport_microxrcedds_cpp::_Twist2D__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav_2d_msgs, msg, Twist2D)() {
  return &nav_2d_msgs::msg::typesupport_microxrcedds_cpp::_Twist2D__handle;
}

#ifdef __cplusplus
}
#endif
