// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:msg/Particle.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/particle__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/msg/detail/particle__struct.h"
#include "nav2_msgs/msg/detail/particle__functions.h"

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

#include "geometry_msgs/msg/detail/pose__functions.h"  // pose

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose)();


typedef nav2_msgs__msg__Particle _Particle__ros_msg_type;

static bool _Particle__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Particle__ros_msg_type * ros_message = (_Particle__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose
      )()->data))->cdr_serialize(&ros_message->pose, cdr);
  // Member: weight
  rv = ucdr_serialize_double(cdr, ros_message->weight);

  return rv;
}

static bool _Particle__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Particle__ros_msg_type * ros_message = (_Particle__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose
      )()->data))->cdr_deserialize(cdr, &ros_message->pose);
  // Field name: weight
  rv = ucdr_deserialize_double(cdr, &ros_message->weight);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__Particle(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Particle__ros_msg_type * ros_message = (const _Particle__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Pose(&ros_message->pose, current_alignment);
  // Member: weight
  {
    const size_t item_size = sizeof(ros_message->weight);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Particle__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__msg__Particle(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__Particle(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: pose
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Pose(full_bounded, current_alignment);
  // Member: weight
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);

  return current_alignment - initial_alignment;
}

static size_t _Particle__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__msg__Particle(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Particle = {
  "nav2_msgs::msg",
  "Particle",
  _Particle__cdr_serialize,
  _Particle__cdr_deserialize,
  _Particle__get_serialized_size,
  get_serialized_size_nav2_msgs__msg__Particle,
  _Particle__max_serialized_size
};

static rosidl_message_type_support_t _Particle__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Particle,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, Particle)() {
  return &_Particle__type_support;
}

#if defined(__cplusplus)
}
#endif
