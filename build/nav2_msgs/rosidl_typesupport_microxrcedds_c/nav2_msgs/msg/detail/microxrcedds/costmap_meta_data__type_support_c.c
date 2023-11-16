// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:msg/CostmapMetaData.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/costmap_meta_data__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/msg/detail/costmap_meta_data__struct.h"
#include "nav2_msgs/msg/detail/costmap_meta_data__functions.h"

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

#include "builtin_interfaces/msg/detail/time__functions.h"  // map_load_time, update_time
#include "geometry_msgs/msg/detail/pose__functions.h"  // origin
#include "rosidl_runtime_c/string.h"  // layer
#include "rosidl_runtime_c/string_functions.h"  // layer

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time)();
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


typedef nav2_msgs__msg__CostmapMetaData _CostmapMetaData__ros_msg_type;

static bool _CostmapMetaData__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _CostmapMetaData__ros_msg_type * ros_message = (_CostmapMetaData__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: map_load_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->map_load_time, cdr);
  // Member: update_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->update_time, cdr);
  // Member: layer
 {
    uint32_t string_len = (ros_message->layer.data == NULL) ? 0 : (uint32_t)strlen(ros_message->layer.data) + 1;
    ros_message->layer.size = (ros_message->layer.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->layer.data, string_len);
  }
  // Member: resolution
  rv = ucdr_serialize_float(cdr, ros_message->resolution);
  // Member: size_x
  rv = ucdr_serialize_uint32_t(cdr, ros_message->size_x);
  // Member: size_y
  rv = ucdr_serialize_uint32_t(cdr, ros_message->size_y);
  // Member: origin
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose
      )()->data))->cdr_serialize(&ros_message->origin, cdr);

  return rv;
}

static bool _CostmapMetaData__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _CostmapMetaData__ros_msg_type * ros_message = (_CostmapMetaData__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: map_load_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->map_load_time);
  // Field name: update_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->update_time);
  // Field name: layer
  {
    size_t capacity = ros_message->layer.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->layer.data, capacity, &string_size);
    if (rv) {
      ros_message->layer.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->layer.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: resolution
  rv = ucdr_deserialize_float(cdr, &ros_message->resolution);
  // Field name: size_x
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->size_x);
  // Field name: size_y
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->size_y);
  // Field name: origin
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Pose
      )()->data))->cdr_deserialize(cdr, &ros_message->origin);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__CostmapMetaData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _CostmapMetaData__ros_msg_type * ros_message = (const _CostmapMetaData__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map_load_time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->map_load_time, current_alignment);
  // Member: update_time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->update_time, current_alignment);
  // Member: layer
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->layer.size + 1;
  // Member: resolution
  {
    const size_t item_size = sizeof(ros_message->resolution);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
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
  // Member: origin
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Pose(&ros_message->origin, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _CostmapMetaData__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__msg__CostmapMetaData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__CostmapMetaData(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map_load_time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: update_time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: layer
  *full_bounded = false;
  // Member: resolution
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: size_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: size_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: origin
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Pose(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _CostmapMetaData__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__msg__CostmapMetaData(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_CostmapMetaData = {
  "nav2_msgs::msg",
  "CostmapMetaData",
  _CostmapMetaData__cdr_serialize,
  _CostmapMetaData__cdr_deserialize,
  _CostmapMetaData__get_serialized_size,
  get_serialized_size_nav2_msgs__msg__CostmapMetaData,
  _CostmapMetaData__max_serialized_size
};

static rosidl_message_type_support_t _CostmapMetaData__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_CostmapMetaData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, CostmapMetaData)() {
  return &_CostmapMetaData__type_support;
}

#if defined(__cplusplus)
}
#endif
