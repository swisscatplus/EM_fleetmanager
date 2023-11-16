// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from dwb_msgs:msg/TrajectoryScore.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/msg/detail/trajectory_score__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "dwb_msgs/msg/detail/trajectory_score__struct.h"
#include "dwb_msgs/msg/detail/trajectory_score__functions.h"

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

#include "dwb_msgs/msg/detail/critic_score__functions.h"  // scores
#include "dwb_msgs/msg/detail/trajectory2_d__functions.h"  // traj

// forward declare type support functions
size_t get_serialized_size_dwb_msgs__msg__CriticScore(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__CriticScore(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore)();
size_t get_serialized_size_dwb_msgs__msg__Trajectory2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__Trajectory2D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D)();


typedef dwb_msgs__msg__TrajectoryScore _TrajectoryScore__ros_msg_type;

static bool _TrajectoryScore__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _TrajectoryScore__ros_msg_type * ros_message = (_TrajectoryScore__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: traj
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D
      )()->data))->cdr_serialize(&ros_message->traj, cdr);
  // Member: scores
  {
    const size_t size = ros_message->scores.size;
    rv = ucdr_serialize_uint32_t(cdr, size);

    if(rv == true){
      for(size_t i = 0; i < size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore
          )()->data))->cdr_serialize(&ros_message->scores.data[i], cdr);
        if(rv == false){
          break;
        }
      }
    }
  }
  // Member: total
  rv = ucdr_serialize_float(cdr, ros_message->total);

  return rv;
}

static bool _TrajectoryScore__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _TrajectoryScore__ros_msg_type * ros_message = (_TrajectoryScore__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: traj
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, Trajectory2D
      )()->data))->cdr_deserialize(cdr, &ros_message->traj);
  // Field name: scores
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->scores.capacity){
      return 0;
    }

    ros_message->scores.size = size;
    for(size_t i = 0; i < size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore
        )()->data))->cdr_deserialize(cdr, &ros_message->scores.data[i]);
      if(rv == false){
        break;
      }
    }
  }
  // Field name: total
  rv = ucdr_deserialize_float(cdr, &ros_message->total);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__msg__TrajectoryScore(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _TrajectoryScore__ros_msg_type * ros_message = (const _TrajectoryScore__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment +=
    get_serialized_size_dwb_msgs__msg__Trajectory2D(&ros_message->traj, current_alignment);
  // Member: scores
  {
    const size_t sequence_size = ros_message->scores.size;

    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, CriticScore
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->scores.data[i], current_alignment);
      uint8_t alignment_size = (element_size < MICROXRCEDDS_PADDING) ? element_size : MICROXRCEDDS_PADDING;
      current_alignment += ucdr_alignment(current_alignment, alignment_size) + element_size;
    }
  }
  // Member: total
  {
    const size_t item_size = sizeof(ros_message->total);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TrajectoryScore__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_dwb_msgs__msg__TrajectoryScore(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__msg__TrajectoryScore(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment +=
    max_serialized_size_dwb_msgs__msg__Trajectory2D(full_bounded, current_alignment);
  // Member: scores
  {
    *full_bounded = false;
  }
  // Member: total
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static size_t _TrajectoryScore__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_dwb_msgs__msg__TrajectoryScore(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_TrajectoryScore = {
  "dwb_msgs::msg",
  "TrajectoryScore",
  _TrajectoryScore__cdr_serialize,
  _TrajectoryScore__cdr_deserialize,
  _TrajectoryScore__get_serialized_size,
  get_serialized_size_dwb_msgs__msg__TrajectoryScore,
  _TrajectoryScore__max_serialized_size
};

static rosidl_message_type_support_t _TrajectoryScore__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_TrajectoryScore,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, dwb_msgs, msg, TrajectoryScore)() {
  return &_TrajectoryScore__type_support;
}

#if defined(__cplusplus)
}
#endif
