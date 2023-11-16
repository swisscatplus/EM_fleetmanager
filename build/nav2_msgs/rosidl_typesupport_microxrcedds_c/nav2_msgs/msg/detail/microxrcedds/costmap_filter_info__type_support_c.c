// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:msg/CostmapFilterInfo.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/costmap_filter_info__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/msg/detail/costmap_filter_info__struct.h"
#include "nav2_msgs/msg/detail/costmap_filter_info__functions.h"

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

#include "rosidl_runtime_c/string.h"  // filter_mask_topic
#include "rosidl_runtime_c/string_functions.h"  // filter_mask_topic
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
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


typedef nav2_msgs__msg__CostmapFilterInfo _CostmapFilterInfo__ros_msg_type;

static bool _CostmapFilterInfo__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _CostmapFilterInfo__ros_msg_type * ros_message = (_CostmapFilterInfo__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: type
  rv = ucdr_serialize_uint8_t(cdr, ros_message->type);
  // Member: filter_mask_topic
 {
    uint32_t string_len = (ros_message->filter_mask_topic.data == NULL) ? 0 : (uint32_t)strlen(ros_message->filter_mask_topic.data) + 1;
    ros_message->filter_mask_topic.size = (ros_message->filter_mask_topic.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->filter_mask_topic.data, string_len);
  }
  // Member: base
  rv = ucdr_serialize_float(cdr, ros_message->base);
  // Member: multiplier
  rv = ucdr_serialize_float(cdr, ros_message->multiplier);

  return rv;
}

static bool _CostmapFilterInfo__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _CostmapFilterInfo__ros_msg_type * ros_message = (_CostmapFilterInfo__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: type
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->type);
  // Field name: filter_mask_topic
  {
    size_t capacity = ros_message->filter_mask_topic.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->filter_mask_topic.data, capacity, &string_size);
    if (rv) {
      ros_message->filter_mask_topic.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->filter_mask_topic.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: base
  rv = ucdr_deserialize_float(cdr, &ros_message->base);
  // Field name: multiplier
  rv = ucdr_deserialize_float(cdr, &ros_message->multiplier);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__CostmapFilterInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _CostmapFilterInfo__ros_msg_type * ros_message = (const _CostmapFilterInfo__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: type
  {
    const size_t item_size = sizeof(ros_message->type);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: filter_mask_topic
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->filter_mask_topic.size + 1;
  // Member: base
  {
    const size_t item_size = sizeof(ros_message->base);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: multiplier
  {
    const size_t item_size = sizeof(ros_message->multiplier);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CostmapFilterInfo__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__msg__CostmapFilterInfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__CostmapFilterInfo(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: type
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: filter_mask_topic
  *full_bounded = false;
  // Member: base
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: multiplier
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static size_t _CostmapFilterInfo__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__msg__CostmapFilterInfo(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_CostmapFilterInfo = {
  "nav2_msgs::msg",
  "CostmapFilterInfo",
  _CostmapFilterInfo__cdr_serialize,
  _CostmapFilterInfo__cdr_deserialize,
  _CostmapFilterInfo__get_serialized_size,
  get_serialized_size_nav2_msgs__msg__CostmapFilterInfo,
  _CostmapFilterInfo__max_serialized_size
};

static rosidl_message_type_support_t _CostmapFilterInfo__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_CostmapFilterInfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, CostmapFilterInfo)() {
  return &_CostmapFilterInfo__type_support;
}

#if defined(__cplusplus)
}
#endif
