// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:action/FollowPath.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/action/detail/follow_path__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/action/detail/follow_path__struct.h"
#include "nav2_msgs/action/detail/follow_path__functions.h"

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

#include "nav_msgs/msg/detail/path__functions.h"  // path
#include "rosidl_runtime_c/string.h"  // controller_id, goal_checker_id
#include "rosidl_runtime_c/string_functions.h"  // controller_id, goal_checker_id

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
size_t max_serialized_size_nav_msgs__msg__Path(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_msgs, msg, Path)();


typedef nav2_msgs__action__FollowPath_Goal _FollowPath_Goal__ros_msg_type;

static bool _FollowPath_Goal__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_Goal__ros_msg_type * ros_message = (_FollowPath_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: path
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_msgs, msg, Path
      )()->data))->cdr_serialize(&ros_message->path, cdr);
  // Member: controller_id
 {
    uint32_t string_len = (ros_message->controller_id.data == NULL) ? 0 : (uint32_t)strlen(ros_message->controller_id.data) + 1;
    ros_message->controller_id.size = (ros_message->controller_id.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->controller_id.data, string_len);
  }
  // Member: goal_checker_id
 {
    uint32_t string_len = (ros_message->goal_checker_id.data == NULL) ? 0 : (uint32_t)strlen(ros_message->goal_checker_id.data) + 1;
    ros_message->goal_checker_id.size = (ros_message->goal_checker_id.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->goal_checker_id.data, string_len);
  }

  return rv;
}

static bool _FollowPath_Goal__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_Goal__ros_msg_type * ros_message = (_FollowPath_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: path
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav_msgs, msg, Path
      )()->data))->cdr_deserialize(cdr, &ros_message->path);
  // Field name: controller_id
  {
    size_t capacity = ros_message->controller_id.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->controller_id.data, capacity, &string_size);
    if (rv) {
      ros_message->controller_id.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->controller_id.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: goal_checker_id
  {
    size_t capacity = ros_message->goal_checker_id.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->goal_checker_id.data, capacity, &string_size);
    if (rv) {
      ros_message->goal_checker_id.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->goal_checker_id.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_Goal__ros_msg_type * ros_message = (const _FollowPath_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: path
  current_alignment +=
    get_serialized_size_nav_msgs__msg__Path(&ros_message->path, current_alignment);
  // Member: controller_id
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->controller_id.size + 1;
  // Member: goal_checker_id
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->goal_checker_id.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_Goal(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: path
  current_alignment +=
    max_serialized_size_nav_msgs__msg__Path(full_bounded, current_alignment);
  // Member: controller_id
  *full_bounded = false;
  // Member: goal_checker_id
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _FollowPath_Goal__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_Goal(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_Goal = {
  "nav2_msgs::action",
  "FollowPath_Goal",
  _FollowPath_Goal__cdr_serialize,
  _FollowPath_Goal__cdr_deserialize,
  _FollowPath_Goal__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_Goal,
  _FollowPath_Goal__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_Goal__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_Goal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Goal)() {
  return &_FollowPath_Goal__type_support;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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


typedef nav2_msgs__action__FollowPath_Result _FollowPath_Result__ros_msg_type;

static bool _FollowPath_Result__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_Result__ros_msg_type * ros_message = (_FollowPath_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_serialize(&ros_message->result, cdr);

  return rv;
}

static bool _FollowPath_Result__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_Result__ros_msg_type * ros_message = (_FollowPath_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_deserialize(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_Result__ros_msg_type * ros_message = (const _FollowPath_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: result
  current_alignment +=
    get_serialized_size_std_msgs__msg__Empty(&ros_message->result, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_Result__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_Result(
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

static size_t _FollowPath_Result__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_Result(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_Result = {
  "nav2_msgs::action",
  "FollowPath_Result",
  _FollowPath_Result__cdr_serialize,
  _FollowPath_Result__cdr_deserialize,
  _FollowPath_Result__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_Result,
  _FollowPath_Result__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_Result__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_Result,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Result)() {
  return &_FollowPath_Result__type_support;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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


// forward declare type support functions


typedef nav2_msgs__action__FollowPath_Feedback _FollowPath_Feedback__ros_msg_type;

static bool _FollowPath_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_Feedback__ros_msg_type * ros_message = (_FollowPath_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: distance_to_goal
  rv = ucdr_serialize_float(cdr, ros_message->distance_to_goal);
  // Member: speed
  rv = ucdr_serialize_float(cdr, ros_message->speed);

  return rv;
}

static bool _FollowPath_Feedback__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_Feedback__ros_msg_type * ros_message = (_FollowPath_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: distance_to_goal
  rv = ucdr_deserialize_float(cdr, &ros_message->distance_to_goal);
  // Field name: speed
  rv = ucdr_deserialize_float(cdr, &ros_message->speed);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_Feedback__ros_msg_type * ros_message = (const _FollowPath_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: distance_to_goal
  {
    const size_t item_size = sizeof(ros_message->distance_to_goal);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: speed
  {
    const size_t item_size = sizeof(ros_message->speed);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_Feedback(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: distance_to_goal
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: speed
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static size_t _FollowPath_Feedback__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_Feedback(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_Feedback = {
  "nav2_msgs::action",
  "FollowPath_Feedback",
  _FollowPath_Feedback__cdr_serialize,
  _FollowPath_Feedback__cdr_deserialize,
  _FollowPath_Feedback__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_Feedback,
  _FollowPath_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_Feedback__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_Feedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Feedback)() {
  return &_FollowPath_Feedback__type_support;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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
// #include "nav2_msgs/action/detail/follow_path__functions.h"  // goal
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__FollowPath_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__FollowPath_Goal(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Goal)();
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


typedef nav2_msgs__action__FollowPath_SendGoal_Request _FollowPath_SendGoal_Request__ros_msg_type;

static bool _FollowPath_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_SendGoal_Request__ros_msg_type * ros_message = (_FollowPath_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Goal
      )()->data))->cdr_serialize(&ros_message->goal, cdr);

  return rv;
}

static bool _FollowPath_SendGoal_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_SendGoal_Request__ros_msg_type * ros_message = (_FollowPath_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Goal
      )()->data))->cdr_deserialize(cdr, &ros_message->goal);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_SendGoal_Request__ros_msg_type * ros_message = (const _FollowPath_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: goal
  current_alignment +=
    get_serialized_size_nav2_msgs__action__FollowPath_Goal(&ros_message->goal, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Request(
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
    max_serialized_size_nav2_msgs__action__FollowPath_Goal(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _FollowPath_SendGoal_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_SendGoal_Request = {
  "nav2_msgs::action",
  "FollowPath_SendGoal_Request",
  _FollowPath_SendGoal_Request__cdr_serialize,
  _FollowPath_SendGoal_Request__cdr_deserialize,
  _FollowPath_SendGoal_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Request,
  _FollowPath_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_SendGoal_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_SendGoal_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_SendGoal_Request)() {
  return &_FollowPath_SendGoal_Request__type_support;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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


typedef nav2_msgs__action__FollowPath_SendGoal_Response _FollowPath_SendGoal_Response__ros_msg_type;

static bool _FollowPath_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_SendGoal_Response__ros_msg_type * ros_message = (_FollowPath_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: accepted
  rv = ucdr_serialize_bool(cdr, (ros_message->accepted) ? 0x01 : 0x00);
  // Member: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->stamp, cdr);

  return rv;
}

static bool _FollowPath_SendGoal_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_SendGoal_Response__ros_msg_type * ros_message = (_FollowPath_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
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
size_t get_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_SendGoal_Response__ros_msg_type * ros_message = (const _FollowPath_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
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

static uint32_t _FollowPath_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Response(
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

static size_t _FollowPath_SendGoal_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_SendGoal_Response = {
  "nav2_msgs::action",
  "FollowPath_SendGoal_Response",
  _FollowPath_SendGoal_Response__cdr_serialize,
  _FollowPath_SendGoal_Response__cdr_deserialize,
  _FollowPath_SendGoal_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_SendGoal_Response,
  _FollowPath_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_SendGoal_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_SendGoal_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_SendGoal_Response)() {
  return &_FollowPath_SendGoal_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/action/follow_path.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t FollowPath_SendGoal__callbacks = {
  "nav2_msgs::action",
  "FollowPath_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_SendGoal_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_SendGoal_Response),
};

static rosidl_service_type_support_t FollowPath_SendGoal__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &FollowPath_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_SendGoal)() {
  return &FollowPath_SendGoal__handle;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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


typedef nav2_msgs__action__FollowPath_GetResult_Request _FollowPath_GetResult_Request__ros_msg_type;

static bool _FollowPath_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_GetResult_Request__ros_msg_type * ros_message = (_FollowPath_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);

  return rv;
}

static bool _FollowPath_GetResult_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_GetResult_Request__ros_msg_type * ros_message = (_FollowPath_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_GetResult_Request__ros_msg_type * ros_message = (const _FollowPath_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_GetResult_Request(
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

static size_t _FollowPath_GetResult_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_GetResult_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_GetResult_Request = {
  "nav2_msgs::action",
  "FollowPath_GetResult_Request",
  _FollowPath_GetResult_Request__cdr_serialize,
  _FollowPath_GetResult_Request__cdr_deserialize,
  _FollowPath_GetResult_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_GetResult_Request,
  _FollowPath_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_GetResult_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_GetResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_GetResult_Request)() {
  return &_FollowPath_GetResult_Request__type_support;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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
// #include "nav2_msgs/action/detail/follow_path__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__FollowPath_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__FollowPath_Result(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Result)();


typedef nav2_msgs__action__FollowPath_GetResult_Response _FollowPath_GetResult_Response__ros_msg_type;

static bool _FollowPath_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_GetResult_Response__ros_msg_type * ros_message = (_FollowPath_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: status
  rv = ucdr_serialize_int8_t(cdr, ros_message->status);
  // Member: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Result
      )()->data))->cdr_serialize(&ros_message->result, cdr);

  return rv;
}

static bool _FollowPath_GetResult_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_GetResult_Response__ros_msg_type * ros_message = (_FollowPath_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: status
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->status);
  // Field name: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Result
      )()->data))->cdr_deserialize(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_GetResult_Response__ros_msg_type * ros_message = (const _FollowPath_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: status
  {
    const size_t item_size = sizeof(ros_message->status);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: result
  current_alignment +=
    get_serialized_size_nav2_msgs__action__FollowPath_Result(&ros_message->result, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_GetResult_Response(
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
    max_serialized_size_nav2_msgs__action__FollowPath_Result(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _FollowPath_GetResult_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_GetResult_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_GetResult_Response = {
  "nav2_msgs::action",
  "FollowPath_GetResult_Response",
  _FollowPath_GetResult_Response__cdr_serialize,
  _FollowPath_GetResult_Response__cdr_deserialize,
  _FollowPath_GetResult_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_GetResult_Response,
  _FollowPath_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_GetResult_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_GetResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_GetResult_Response)() {
  return &_FollowPath_GetResult_Response__type_support;
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
// #include "nav2_msgs/action/follow_path.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t FollowPath_GetResult__callbacks = {
  "nav2_msgs::action",
  "FollowPath_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_GetResult_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_GetResult_Response),
};

static rosidl_service_type_support_t FollowPath_GetResult__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &FollowPath_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_GetResult)() {
  return &FollowPath_GetResult__handle;
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
// #include "nav2_msgs/action/detail/follow_path__struct.h"
// already included above
// #include "nav2_msgs/action/detail/follow_path__functions.h"

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
// #include "nav2_msgs/action/detail/follow_path__functions.h"  // feedback
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__FollowPath_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__FollowPath_Feedback(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Feedback)();
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


typedef nav2_msgs__action__FollowPath_FeedbackMessage _FollowPath_FeedbackMessage__ros_msg_type;

static bool _FollowPath_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _FollowPath_FeedbackMessage__ros_msg_type * ros_message = (_FollowPath_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Feedback
      )()->data))->cdr_serialize(&ros_message->feedback, cdr);

  return rv;
}

static bool _FollowPath_FeedbackMessage__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _FollowPath_FeedbackMessage__ros_msg_type * ros_message = (_FollowPath_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_Feedback
      )()->data))->cdr_deserialize(cdr, &ros_message->feedback);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__FollowPath_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _FollowPath_FeedbackMessage__ros_msg_type * ros_message = (const _FollowPath_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: feedback
  current_alignment +=
    get_serialized_size_nav2_msgs__action__FollowPath_Feedback(&ros_message->feedback, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FollowPath_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__FollowPath_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__FollowPath_FeedbackMessage(
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
    max_serialized_size_nav2_msgs__action__FollowPath_Feedback(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _FollowPath_FeedbackMessage__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__FollowPath_FeedbackMessage(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FollowPath_FeedbackMessage = {
  "nav2_msgs::action",
  "FollowPath_FeedbackMessage",
  _FollowPath_FeedbackMessage__cdr_serialize,
  _FollowPath_FeedbackMessage__cdr_deserialize,
  _FollowPath_FeedbackMessage__get_serialized_size,
  get_serialized_size_nav2_msgs__action__FollowPath_FeedbackMessage,
  _FollowPath_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _FollowPath_FeedbackMessage__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FollowPath_FeedbackMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, FollowPath_FeedbackMessage)() {
  return &_FollowPath_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
