// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:action/NavigateThroughPoses.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/action/detail/navigate_through_poses__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
#include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

#include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // poses
#include "rosidl_runtime_c/string.h"  // behavior_tree
#include "rosidl_runtime_c/string_functions.h"  // behavior_tree

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped)();


typedef nav2_msgs__action__NavigateThroughPoses_Goal _NavigateThroughPoses_Goal__ros_msg_type;

static bool _NavigateThroughPoses_Goal__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_Goal__ros_msg_type * ros_message = (_NavigateThroughPoses_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: poses
  {
    const size_t size = ros_message->poses.size;
    rv = ucdr_serialize_uint32_t(cdr, size);

    if(rv == true){
      for(size_t i = 0; i < size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped
          )()->data))->cdr_serialize(&ros_message->poses.data[i], cdr);
        if(rv == false){
          break;
        }
      }
    }
  }
  // Member: behavior_tree
 {
    uint32_t string_len = (ros_message->behavior_tree.data == NULL) ? 0 : (uint32_t)strlen(ros_message->behavior_tree.data) + 1;
    ros_message->behavior_tree.size = (ros_message->behavior_tree.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->behavior_tree.data, string_len);
  }

  return rv;
}

static bool _NavigateThroughPoses_Goal__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_Goal__ros_msg_type * ros_message = (_NavigateThroughPoses_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: poses
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->poses.capacity){
      return 0;
    }

    ros_message->poses.size = size;
    for(size_t i = 0; i < size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped
        )()->data))->cdr_deserialize(cdr, &ros_message->poses.data[i]);
      if(rv == false){
        break;
      }
    }
  }
  // Field name: behavior_tree
  {
    size_t capacity = ros_message->behavior_tree.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->behavior_tree.data, capacity, &string_size);
    if (rv) {
      ros_message->behavior_tree.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->behavior_tree.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_Goal__ros_msg_type * ros_message = (const _NavigateThroughPoses_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: poses
  {
    const size_t sequence_size = ros_message->poses.size;

    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->poses.data[i], current_alignment);
      uint8_t alignment_size = (element_size < MICROXRCEDDS_PADDING) ? element_size : MICROXRCEDDS_PADDING;
      current_alignment += ucdr_alignment(current_alignment, alignment_size) + element_size;
    }
  }
  // Member: behavior_tree
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->behavior_tree.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: poses
  {
    *full_bounded = false;
  }
  // Member: behavior_tree
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_Goal__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_Goal = {
  "nav2_msgs::action",
  "NavigateThroughPoses_Goal",
  _NavigateThroughPoses_Goal__cdr_serialize,
  _NavigateThroughPoses_Goal__cdr_deserialize,
  _NavigateThroughPoses_Goal__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal,
  _NavigateThroughPoses_Goal__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_Goal__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_Goal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Goal)() {
  return &_NavigateThroughPoses_Goal__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

#include "std_msgs/msg/detail/empty__functions.h"  // result

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_std_msgs__msg__Empty(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_std_msgs__msg__Empty(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty)();


typedef nav2_msgs__action__NavigateThroughPoses_Result _NavigateThroughPoses_Result__ros_msg_type;

static bool _NavigateThroughPoses_Result__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_Result__ros_msg_type * ros_message = (_NavigateThroughPoses_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_serialize(&ros_message->result, cdr);

  return rv;
}

static bool _NavigateThroughPoses_Result__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_Result__ros_msg_type * ros_message = (_NavigateThroughPoses_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_deserialize(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_Result__ros_msg_type * ros_message = (const _NavigateThroughPoses_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: result
  current_alignment +=
    get_serialized_size_std_msgs__msg__Empty(&ros_message->result, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_Result__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: result
  current_alignment +=
    max_serialized_size_std_msgs__msg__Empty(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_Result__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_Result = {
  "nav2_msgs::action",
  "NavigateThroughPoses_Result",
  _NavigateThroughPoses_Result__cdr_serialize,
  _NavigateThroughPoses_Result__cdr_deserialize,
  _NavigateThroughPoses_Result__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result,
  _NavigateThroughPoses_Result__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_Result__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_Result,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Result)() {
  return &_NavigateThroughPoses_Result__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

#include "builtin_interfaces/msg/detail/duration__functions.h"  // estimated_time_remaining, navigation_time
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // current_pose

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_builtin_interfaces__msg__Duration(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_builtin_interfaces__msg__Duration(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped)();


typedef nav2_msgs__action__NavigateThroughPoses_Feedback _NavigateThroughPoses_Feedback__ros_msg_type;

static bool _NavigateThroughPoses_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_Feedback__ros_msg_type * ros_message = (_NavigateThroughPoses_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: current_pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped
      )()->data))->cdr_serialize(&ros_message->current_pose, cdr);
  // Member: navigation_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_serialize(&ros_message->navigation_time, cdr);
  // Member: estimated_time_remaining
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_serialize(&ros_message->estimated_time_remaining, cdr);
  // Member: number_of_recoveries
  rv = ucdr_serialize_int16_t(cdr, ros_message->number_of_recoveries);
  // Member: distance_remaining
  rv = ucdr_serialize_float(cdr, ros_message->distance_remaining);
  // Member: number_of_poses_remaining
  rv = ucdr_serialize_int16_t(cdr, ros_message->number_of_poses_remaining);

  return rv;
}

static bool _NavigateThroughPoses_Feedback__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_Feedback__ros_msg_type * ros_message = (_NavigateThroughPoses_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: current_pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, PoseStamped
      )()->data))->cdr_deserialize(cdr, &ros_message->current_pose);
  // Field name: navigation_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_deserialize(cdr, &ros_message->navigation_time);
  // Field name: estimated_time_remaining
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_deserialize(cdr, &ros_message->estimated_time_remaining);
  // Field name: number_of_recoveries
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->number_of_recoveries);
  // Field name: distance_remaining
  rv = ucdr_deserialize_float(cdr, &ros_message->distance_remaining);
  // Field name: number_of_poses_remaining
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->number_of_poses_remaining);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_Feedback__ros_msg_type * ros_message = (const _NavigateThroughPoses_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: current_pose
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__PoseStamped(&ros_message->current_pose, current_alignment);
  // Member: navigation_time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Duration(&ros_message->navigation_time, current_alignment);
  // Member: estimated_time_remaining
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Duration(&ros_message->estimated_time_remaining, current_alignment);
  // Member: number_of_recoveries
  {
    const size_t item_size = sizeof(ros_message->number_of_recoveries);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: distance_remaining
  {
    const size_t item_size = sizeof(ros_message->distance_remaining);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: number_of_poses_remaining
  {
    const size_t item_size = sizeof(ros_message->number_of_poses_remaining);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: current_pose
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__PoseStamped(full_bounded, current_alignment);
  // Member: navigation_time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Duration(full_bounded, current_alignment);
  // Member: estimated_time_remaining
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Duration(full_bounded, current_alignment);
  // Member: number_of_recoveries
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: distance_remaining
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: number_of_poses_remaining
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_Feedback__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_Feedback = {
  "nav2_msgs::action",
  "NavigateThroughPoses_Feedback",
  _NavigateThroughPoses_Feedback__cdr_serialize,
  _NavigateThroughPoses_Feedback__cdr_deserialize,
  _NavigateThroughPoses_Feedback__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback,
  _NavigateThroughPoses_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_Feedback__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_Feedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Feedback)() {
  return &_NavigateThroughPoses_Feedback__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"  // goal
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Goal)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID)();


typedef nav2_msgs__action__NavigateThroughPoses_SendGoal_Request _NavigateThroughPoses_SendGoal_Request__ros_msg_type;

static bool _NavigateThroughPoses_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_SendGoal_Request__ros_msg_type * ros_message = (_NavigateThroughPoses_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Goal
      )()->data))->cdr_serialize(&ros_message->goal, cdr);

  return rv;
}

static bool _NavigateThroughPoses_SendGoal_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_SendGoal_Request__ros_msg_type * ros_message = (_NavigateThroughPoses_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Goal
      )()->data))->cdr_deserialize(cdr, &ros_message->goal);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_SendGoal_Request__ros_msg_type * ros_message = (const _NavigateThroughPoses_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: goal
  current_alignment +=
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(&ros_message->goal, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    max_serialized_size_unique_identifier_msgs__msg__UUID(full_bounded, current_alignment);
  // Member: goal
  current_alignment +=
    max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Goal(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_SendGoal_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_SendGoal_Request = {
  "nav2_msgs::action",
  "NavigateThroughPoses_SendGoal_Request",
  _NavigateThroughPoses_SendGoal_Request__cdr_serialize,
  _NavigateThroughPoses_SendGoal_Request__cdr_deserialize,
  _NavigateThroughPoses_SendGoal_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Request,
  _NavigateThroughPoses_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_SendGoal_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_SendGoal_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_SendGoal_Request)() {
  return &_NavigateThroughPoses_SendGoal_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp

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


typedef nav2_msgs__action__NavigateThroughPoses_SendGoal_Response _NavigateThroughPoses_SendGoal_Response__ros_msg_type;

static bool _NavigateThroughPoses_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_SendGoal_Response__ros_msg_type * ros_message = (_NavigateThroughPoses_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: accepted
  rv = ucdr_serialize_bool(cdr, (ros_message->accepted) ? 0x01 : 0x00);
  // Member: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->stamp, cdr);

  return rv;
}

static bool _NavigateThroughPoses_SendGoal_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_SendGoal_Response__ros_msg_type * ros_message = (_NavigateThroughPoses_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: accepted
  rv = ucdr_deserialize_bool(cdr, &ros_message->accepted);
  // Field name: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->stamp);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_SendGoal_Response__ros_msg_type * ros_message = (const _NavigateThroughPoses_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: accepted
  {
    const size_t item_size = sizeof(ros_message->accepted);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: stamp
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->stamp, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: accepted
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: stamp
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_SendGoal_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_SendGoal_Response = {
  "nav2_msgs::action",
  "NavigateThroughPoses_SendGoal_Response",
  _NavigateThroughPoses_SendGoal_Response__cdr_serialize,
  _NavigateThroughPoses_SendGoal_Response__cdr_deserialize,
  _NavigateThroughPoses_SendGoal_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_SendGoal_Response,
  _NavigateThroughPoses_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_SendGoal_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_SendGoal_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_SendGoal_Response)() {
  return &_NavigateThroughPoses_SendGoal_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/action/navigate_through_poses.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t NavigateThroughPoses_SendGoal__callbacks = {
  "nav2_msgs::action",
  "NavigateThroughPoses_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_SendGoal_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_SendGoal_Response),
};

static rosidl_service_type_support_t NavigateThroughPoses_SendGoal__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &NavigateThroughPoses_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_SendGoal)() {
  return &NavigateThroughPoses_SendGoal__handle;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID)();


typedef nav2_msgs__action__NavigateThroughPoses_GetResult_Request _NavigateThroughPoses_GetResult_Request__ros_msg_type;

static bool _NavigateThroughPoses_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_GetResult_Request__ros_msg_type * ros_message = (_NavigateThroughPoses_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);

  return rv;
}

static bool _NavigateThroughPoses_GetResult_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_GetResult_Request__ros_msg_type * ros_message = (_NavigateThroughPoses_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_GetResult_Request__ros_msg_type * ros_message = (const _NavigateThroughPoses_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    max_serialized_size_unique_identifier_msgs__msg__UUID(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_GetResult_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_GetResult_Request = {
  "nav2_msgs::action",
  "NavigateThroughPoses_GetResult_Request",
  _NavigateThroughPoses_GetResult_Request__cdr_serialize,
  _NavigateThroughPoses_GetResult_Request__cdr_deserialize,
  _NavigateThroughPoses_GetResult_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Request,
  _NavigateThroughPoses_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_GetResult_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_GetResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_GetResult_Request)() {
  return &_NavigateThroughPoses_GetResult_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Result)();


typedef nav2_msgs__action__NavigateThroughPoses_GetResult_Response _NavigateThroughPoses_GetResult_Response__ros_msg_type;

static bool _NavigateThroughPoses_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_GetResult_Response__ros_msg_type * ros_message = (_NavigateThroughPoses_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: status
  rv = ucdr_serialize_int8_t(cdr, ros_message->status);
  // Member: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Result
      )()->data))->cdr_serialize(&ros_message->result, cdr);

  return rv;
}

static bool _NavigateThroughPoses_GetResult_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_GetResult_Response__ros_msg_type * ros_message = (_NavigateThroughPoses_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: status
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->status);
  // Field name: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Result
      )()->data))->cdr_deserialize(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_GetResult_Response__ros_msg_type * ros_message = (const _NavigateThroughPoses_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: status
  {
    const size_t item_size = sizeof(ros_message->status);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: result
  current_alignment +=
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(&ros_message->result, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: status
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);
  // Member: result
  current_alignment +=
    max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Result(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_GetResult_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_GetResult_Response = {
  "nav2_msgs::action",
  "NavigateThroughPoses_GetResult_Response",
  _NavigateThroughPoses_GetResult_Response__cdr_serialize,
  _NavigateThroughPoses_GetResult_Response__cdr_deserialize,
  _NavigateThroughPoses_GetResult_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_GetResult_Response,
  _NavigateThroughPoses_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_GetResult_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_GetResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_GetResult_Response)() {
  return &_NavigateThroughPoses_GetResult_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/navigate_through_poses.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t NavigateThroughPoses_GetResult__callbacks = {
  "nav2_msgs::action",
  "NavigateThroughPoses_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_GetResult_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_GetResult_Response),
};

static rosidl_service_type_support_t NavigateThroughPoses_GetResult__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &NavigateThroughPoses_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_GetResult)() {
  return &NavigateThroughPoses_GetResult__handle;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__struct.h"
// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"

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

// already included above
// #include "nav2_msgs/action/detail/navigate_through_poses__functions.h"  // feedback
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Feedback)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID)();


typedef nav2_msgs__action__NavigateThroughPoses_FeedbackMessage _NavigateThroughPoses_FeedbackMessage__ros_msg_type;

static bool _NavigateThroughPoses_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _NavigateThroughPoses_FeedbackMessage__ros_msg_type * ros_message = (_NavigateThroughPoses_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Feedback
      )()->data))->cdr_serialize(&ros_message->feedback, cdr);

  return rv;
}

static bool _NavigateThroughPoses_FeedbackMessage__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _NavigateThroughPoses_FeedbackMessage__ros_msg_type * ros_message = (_NavigateThroughPoses_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_Feedback
      )()->data))->cdr_deserialize(cdr, &ros_message->feedback);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__NavigateThroughPoses_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _NavigateThroughPoses_FeedbackMessage__ros_msg_type * ros_message = (const _NavigateThroughPoses_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: feedback
  current_alignment +=
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(&ros_message->feedback, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateThroughPoses_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__NavigateThroughPoses_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__NavigateThroughPoses_FeedbackMessage(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    max_serialized_size_unique_identifier_msgs__msg__UUID(full_bounded, current_alignment);
  // Member: feedback
  current_alignment +=
    max_serialized_size_nav2_msgs__action__NavigateThroughPoses_Feedback(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _NavigateThroughPoses_FeedbackMessage__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__NavigateThroughPoses_FeedbackMessage(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_NavigateThroughPoses_FeedbackMessage = {
  "nav2_msgs::action",
  "NavigateThroughPoses_FeedbackMessage",
  _NavigateThroughPoses_FeedbackMessage__cdr_serialize,
  _NavigateThroughPoses_FeedbackMessage__cdr_deserialize,
  _NavigateThroughPoses_FeedbackMessage__get_serialized_size,
  get_serialized_size_nav2_msgs__action__NavigateThroughPoses_FeedbackMessage,
  _NavigateThroughPoses_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _NavigateThroughPoses_FeedbackMessage__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_NavigateThroughPoses_FeedbackMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, NavigateThroughPoses_FeedbackMessage)() {
  return &_NavigateThroughPoses_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
