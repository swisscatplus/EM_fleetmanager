// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:msg/BehaviorTreeStatusChange.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/behavior_tree_status_change__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/msg/detail/behavior_tree_status_change__struct.h"
#include "nav2_msgs/msg/detail/behavior_tree_status_change__functions.h"

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

#include "builtin_interfaces/msg/detail/time__functions.h"  // timestamp
#include "rosidl_runtime_c/string.h"  // current_status, node_name, previous_status
#include "rosidl_runtime_c/string_functions.h"  // current_status, node_name, previous_status

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


typedef nav2_msgs__msg__BehaviorTreeStatusChange _BehaviorTreeStatusChange__ros_msg_type;

static bool _BehaviorTreeStatusChange__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _BehaviorTreeStatusChange__ros_msg_type * ros_message = (_BehaviorTreeStatusChange__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: timestamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->timestamp, cdr);
  // Member: node_name
 {
    uint32_t string_len = (ros_message->node_name.data == NULL) ? 0 : (uint32_t)strlen(ros_message->node_name.data) + 1;
    ros_message->node_name.size = (ros_message->node_name.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->node_name.data, string_len);
  }
  // Member: previous_status
 {
    uint32_t string_len = (ros_message->previous_status.data == NULL) ? 0 : (uint32_t)strlen(ros_message->previous_status.data) + 1;
    ros_message->previous_status.size = (ros_message->previous_status.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->previous_status.data, string_len);
  }
  // Member: current_status
 {
    uint32_t string_len = (ros_message->current_status.data == NULL) ? 0 : (uint32_t)strlen(ros_message->current_status.data) + 1;
    ros_message->current_status.size = (ros_message->current_status.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->current_status.data, string_len);
  }

  return rv;
}

static bool _BehaviorTreeStatusChange__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _BehaviorTreeStatusChange__ros_msg_type * ros_message = (_BehaviorTreeStatusChange__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: timestamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->timestamp);
  // Field name: node_name
  {
    size_t capacity = ros_message->node_name.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->node_name.data, capacity, &string_size);
    if (rv) {
      ros_message->node_name.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->node_name.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: previous_status
  {
    size_t capacity = ros_message->previous_status.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->previous_status.data, capacity, &string_size);
    if (rv) {
      ros_message->previous_status.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->previous_status.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: current_status
  {
    size_t capacity = ros_message->current_status.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->current_status.data, capacity, &string_size);
    if (rv) {
      ros_message->current_status.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->current_status.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__BehaviorTreeStatusChange(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _BehaviorTreeStatusChange__ros_msg_type * ros_message = (const _BehaviorTreeStatusChange__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->timestamp, current_alignment);
  // Member: node_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->node_name.size + 1;
  // Member: previous_status
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->previous_status.size + 1;
  // Member: current_status
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->current_status.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _BehaviorTreeStatusChange__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__msg__BehaviorTreeStatusChange(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__BehaviorTreeStatusChange(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: timestamp
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: node_name
  *full_bounded = false;
  // Member: previous_status
  *full_bounded = false;
  // Member: current_status
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _BehaviorTreeStatusChange__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__msg__BehaviorTreeStatusChange(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_BehaviorTreeStatusChange = {
  "nav2_msgs::msg",
  "BehaviorTreeStatusChange",
  _BehaviorTreeStatusChange__cdr_serialize,
  _BehaviorTreeStatusChange__cdr_deserialize,
  _BehaviorTreeStatusChange__get_serialized_size,
  get_serialized_size_nav2_msgs__msg__BehaviorTreeStatusChange,
  _BehaviorTreeStatusChange__max_serialized_size
};

static rosidl_message_type_support_t _BehaviorTreeStatusChange__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_BehaviorTreeStatusChange,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, BehaviorTreeStatusChange)() {
  return &_BehaviorTreeStatusChange__type_support;
}

#if defined(__cplusplus)
}
#endif
