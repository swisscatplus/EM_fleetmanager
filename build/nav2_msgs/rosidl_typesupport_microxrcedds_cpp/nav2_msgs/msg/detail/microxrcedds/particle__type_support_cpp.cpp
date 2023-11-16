// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:msg/Particle.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/particle__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "nav2_msgs/msg/detail/particle__struct.hpp"

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
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Pose &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Pose &);

size_t get_serialized_size(
  const geometry_msgs::msg::Pose &,
  size_t current_alignment);

size_t
max_serialized_size_Pose(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace nav2_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::msg::Particle & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: pose
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.pose,
    cdr);
  // Member: weight
  rv = ucdr_serialize_double(cdr, ros_message.weight);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::msg::Particle & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: pose
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.pose);
  // Member: weight
  rv = ucdr_deserialize_double(cdr, &ros_message.weight);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::msg::Particle & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.pose,
    current_alignment);
  // Member: weight
  {
    const size_t item_size = sizeof(ros_message.weight);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_Particle(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Pose(
    full_bounded,
    current_alignment);
  // Member: weight
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);

  return current_alignment - initial_alignment;
}

static bool _Particle__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::Particle *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Particle__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::msg::Particle *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Particle__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::Particle *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Particle__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::Particle *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _Particle__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_Particle(&full_bounded, 0);
}

static message_type_support_callbacks_t _Particle__callbacks = {
  "nav2_msgs::msg",
  "Particle",
  _Particle__cdr_serialize,
  _Particle__cdr_deserialize,
  _Particle__get_serialized_size,
  _Particle__get_serialized_size_with_initial_alignment,
  _Particle__max_serialized_size
};

static rosidl_message_type_support_t _Particle__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_Particle__callbacks,
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
get_message_type_support_handle<nav2_msgs::msg::Particle>()
{
  return &nav2_msgs::msg::typesupport_microxrcedds_cpp::_Particle__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, msg, Particle)() {
  return &nav2_msgs::msg::typesupport_microxrcedds_cpp::_Particle__handle;
}

#ifdef __cplusplus
}
#endif
