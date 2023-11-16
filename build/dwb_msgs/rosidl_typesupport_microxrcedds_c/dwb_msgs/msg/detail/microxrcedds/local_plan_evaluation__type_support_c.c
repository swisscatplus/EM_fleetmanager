// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from dwb_msgs:msg/LocalPlanEvaluation.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/msg/detail/local_plan_evaluation__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/msg/detail/local_plan_evaluation__struct.h"
#include "dwb_msgs/msg/detail/local_plan_evaluation__functions.h"

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

#include "dwb_msgs/msg/detail/trajectory_score__functions.h"  // twists
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__TrajectoryScore(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__TrajectoryScore(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef dwb_msgs__msg__LocalPlanEvaluation _LocalPlanEvaluation__ros_msg_type;

static bool _LocalPlanEvaluation__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _LocalPlanEvaluation__ros_msg_type * ros_message = (_LocalPlanEvaluation__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: twists
  {
    const size_t size = ros_message->twists.size;
    rv = ucdr_serialize_uint32_t(cdr, size);

    if(rv == true){
      for(size_t i = 0; i < size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore
          )()->data))->cdr_serialize(&ros_message->twists.data[i], cdr);
        if(rv == false){
          break;
        }
      }
    }
  }
  // Member: best_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message->best_index);
  // Member: worst_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message->worst_index);

  return rv;
}

static bool _LocalPlanEvaluation__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _LocalPlanEvaluation__ros_msg_type * ros_message = (_LocalPlanEvaluation__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: twists
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->twists.capacity){
      return 0;
    }

    ros_message->twists.size = size;
    for(size_t i = 0; i < size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore
        )()->data))->cdr_deserialize(cdr, &ros_message->twists.data[i]);
      if(rv == false){
        break;
      }
    }
  }
  // Field name: best_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message->best_index);
  // Field name: worst_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message->worst_index);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _LocalPlanEvaluation__ros_msg_type * ros_message = (const _LocalPlanEvaluation__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: twists
  {
    const size_t sequence_size = ros_message->twists.size;

    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->twists.data[i], current_alignment);
      uint8_t alignment_size = (element_size < MICROXRCEDDS_PADDING) ? element_size : MICROXRCEDDS_PADDING;
      current_alignment += ucdr_alignment(current_alignment, alignment_size) + element_size;
    }
  }
  // Member: best_index
  {
    const size_t item_size = sizeof(ros_message->best_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: worst_index
  {
    const size_t item_size = sizeof(ros_message->worst_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LocalPlanEvaluation__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: twists
  {
    *full_bounded = false;
  }
  // Member: best_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);
  // Member: worst_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);

  return current_alignment - initial_alignment;
}

static size_t _LocalPlanEvaluation__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__msg__LocalPlanEvaluation(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LocalPlanEvaluation = {
  "dwb_msgs::msg",
  "LocalPlanEvaluation",
  _LocalPlanEvaluation__cdr_serialize,
  _LocalPlanEvaluation__cdr_deserialize,
  _LocalPlanEvaluation__get_serialized_size,
  get_serialized_size_dwb_msgs__msg__LocalPlanEvaluation,
  _LocalPlanEvaluation__max_serialized_size
};

static rosidl_message_type_support_t _LocalPlanEvaluation__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LocalPlanEvaluation,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, LocalPlanEvaluation)() {
  return &_LocalPlanEvaluation__type_support;
}

#if defined(__cplusplus)
}
#endif
