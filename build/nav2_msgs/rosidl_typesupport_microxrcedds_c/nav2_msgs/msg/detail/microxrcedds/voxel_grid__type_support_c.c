// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:msg/VoxelGrid.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/voxel_grid__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/msg/detail/voxel_grid__struct.h"
#include "nav2_msgs/msg/detail/voxel_grid__functions.h"

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

#include "geometry_msgs/msg/detail/point32__functions.h"  // origin
#include "geometry_msgs/msg/detail/vector3__functions.h"  // resolutions
#include "rosidl_runtime_c/primitives_sequence.h"  // data
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_geometry_msgs__msg__Point32(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_geometry_msgs__msg__Vector3(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_geometry_msgs__msg__Vector3(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Vector3)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef nav2_msgs__msg__VoxelGrid _VoxelGrid__ros_msg_type;

static bool _VoxelGrid__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _VoxelGrid__ros_msg_type * ros_message = (_VoxelGrid__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: data
  {
    const size_t size = ros_message->data.size;
    rv = ucdr_serialize_sequence_uint32_t(cdr, ros_message->data.data, size);
  }
  // Member: origin
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32
      )()->data))->cdr_serialize(&ros_message->origin, cdr);
  // Member: resolutions
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Vector3
      )()->data))->cdr_serialize(&ros_message->resolutions, cdr);
  // Member: size_x
  rv = ucdr_serialize_uint32_t(cdr, ros_message->size_x);
  // Member: size_y
  rv = ucdr_serialize_uint32_t(cdr, ros_message->size_y);
  // Member: size_z
  rv = ucdr_serialize_uint32_t(cdr, ros_message->size_z);

  return rv;
}

static bool _VoxelGrid__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _VoxelGrid__ros_msg_type * ros_message = (_VoxelGrid__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: data
  {
    uint32_t size;
    const size_t capacity = ros_message->data.capacity;
    rv = ucdr_deserialize_sequence_uint32_t(cdr, ros_message->data.data, capacity, &size);
    if (rv) {
      ros_message->data.size = size;
    } else if(size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->data.size = 0;
      ucdr_align_to(cdr, sizeof(uint32_t));
      ucdr_advance_buffer(cdr, size * sizeof(uint32_t));
    }
  }
  // Field name: origin
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32
      )()->data))->cdr_deserialize(cdr, &ros_message->origin);
  // Field name: resolutions
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Vector3
      )()->data))->cdr_deserialize(cdr, &ros_message->resolutions);
  // Field name: size_x
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->size_x);
  // Field name: size_y
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->size_y);
  // Field name: size_z
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->size_z);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__VoxelGrid(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _VoxelGrid__ros_msg_type * ros_message = (const _VoxelGrid__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: data
  {
    size_t sequence_size = ros_message->data.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    if (0 < sequence_size) {
      size_t item_size = sizeof(ros_message->data.data[0]);
      current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
    }
  }
  // Member: origin
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Point32(&ros_message->origin, current_alignment);
  // Member: resolutions
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Vector3(&ros_message->resolutions, current_alignment);
  // Member: size_x
  {
    const size_t item_size = sizeof(ros_message->size_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: size_y
  {
    const size_t item_size = sizeof(ros_message->size_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: size_z
  {
    const size_t item_size = sizeof(ros_message->size_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VoxelGrid__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__msg__VoxelGrid(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__VoxelGrid(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: data
  {
    *full_bounded = false;
  }
  // Member: origin
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Point32(full_bounded, current_alignment);
  // Member: resolutions
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Vector3(full_bounded, current_alignment);
  // Member: size_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: size_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: size_z
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);

  return current_alignment - initial_alignment;
}

static size_t _VoxelGrid__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__msg__VoxelGrid(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_VoxelGrid = {
  "nav2_msgs::msg",
  "VoxelGrid",
  _VoxelGrid__cdr_serialize,
  _VoxelGrid__cdr_deserialize,
  _VoxelGrid__get_serialized_size,
  get_serialized_size_nav2_msgs__msg__VoxelGrid,
  _VoxelGrid__max_serialized_size
};

static rosidl_message_type_support_t _VoxelGrid__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_VoxelGrid,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, VoxelGrid)() {
  return &_VoxelGrid__type_support;
}

#if defined(__cplusplus)
}
#endif
