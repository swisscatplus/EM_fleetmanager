// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:action/Wait.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/action/detail/wait__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/action/detail/wait__struct.h"
#include "nav2_msgs/action/detail/wait__functions.h"

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

#include "builtin_interfaces/msg/detail/duration__functions.h"  // time

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


typedef nav2_msgs__action__Wait_Goal _Wait_Goal__ros_msg_type;

static bool _Wait_Goal__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_Goal__ros_msg_type * ros_message = (_Wait_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_serialize(&ros_message->time, cdr);

  return rv;
}

static bool _Wait_Goal__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_Goal__ros_msg_type * ros_message = (_Wait_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_deserialize(cdr, &ros_message->time);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_Goal__ros_msg_type * ros_message = (const _Wait_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Duration(&ros_message->time, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_Goal(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Duration(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Wait_Goal__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_Goal(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_Goal = {
  "nav2_msgs::action",
  "Wait_Goal",
  _Wait_Goal__cdr_serialize,
  _Wait_Goal__cdr_deserialize,
  _Wait_Goal__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_Goal,
  _Wait_Goal__max_serialized_size
};

static rosidl_message_type_support_t _Wait_Goal__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_Goal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Goal)() {
  return &_Wait_Goal__type_support;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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
// #include "builtin_interfaces/msg/detail/duration__functions.h"  // total_elapsed_time

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


typedef nav2_msgs__action__Wait_Result _Wait_Result__ros_msg_type;

static bool _Wait_Result__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_Result__ros_msg_type * ros_message = (_Wait_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: total_elapsed_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_serialize(&ros_message->total_elapsed_time, cdr);

  return rv;
}

static bool _Wait_Result__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_Result__ros_msg_type * ros_message = (_Wait_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: total_elapsed_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_deserialize(cdr, &ros_message->total_elapsed_time);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_Result__ros_msg_type * ros_message = (const _Wait_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: total_elapsed_time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Duration(&ros_message->total_elapsed_time, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_Result__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_Result(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: total_elapsed_time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Duration(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Wait_Result__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_Result(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_Result = {
  "nav2_msgs::action",
  "Wait_Result",
  _Wait_Result__cdr_serialize,
  _Wait_Result__cdr_deserialize,
  _Wait_Result__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_Result,
  _Wait_Result__max_serialized_size
};

static rosidl_message_type_support_t _Wait_Result__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_Result,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Result)() {
  return &_Wait_Result__type_support;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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
// #include "builtin_interfaces/msg/detail/duration__functions.h"  // time_left

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


typedef nav2_msgs__action__Wait_Feedback _Wait_Feedback__ros_msg_type;

static bool _Wait_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_Feedback__ros_msg_type * ros_message = (_Wait_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: time_left
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_serialize(&ros_message->time_left, cdr);

  return rv;
}

static bool _Wait_Feedback__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_Feedback__ros_msg_type * ros_message = (_Wait_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: time_left
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_deserialize(cdr, &ros_message->time_left);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_Feedback__ros_msg_type * ros_message = (const _Wait_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: time_left
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Duration(&ros_message->time_left, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_Feedback(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: time_left
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Duration(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Wait_Feedback__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_Feedback(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_Feedback = {
  "nav2_msgs::action",
  "Wait_Feedback",
  _Wait_Feedback__cdr_serialize,
  _Wait_Feedback__cdr_deserialize,
  _Wait_Feedback__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_Feedback,
  _Wait_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _Wait_Feedback__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_Feedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Feedback)() {
  return &_Wait_Feedback__type_support;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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
// #include "nav2_msgs/action/detail/wait__functions.h"  // goal
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__Wait_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__Wait_Goal(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Goal)();
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


typedef nav2_msgs__action__Wait_SendGoal_Request _Wait_SendGoal_Request__ros_msg_type;

static bool _Wait_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_SendGoal_Request__ros_msg_type * ros_message = (_Wait_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Goal
      )()->data))->cdr_serialize(&ros_message->goal, cdr);

  return rv;
}

static bool _Wait_SendGoal_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_SendGoal_Request__ros_msg_type * ros_message = (_Wait_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Goal
      )()->data))->cdr_deserialize(cdr, &ros_message->goal);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_SendGoal_Request__ros_msg_type * ros_message = (const _Wait_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: goal
  current_alignment +=
    get_serialized_size_nav2_msgs__action__Wait_Goal(&ros_message->goal, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_SendGoal_Request(
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
    max_serialized_size_nav2_msgs__action__Wait_Goal(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Wait_SendGoal_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_SendGoal_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_SendGoal_Request = {
  "nav2_msgs::action",
  "Wait_SendGoal_Request",
  _Wait_SendGoal_Request__cdr_serialize,
  _Wait_SendGoal_Request__cdr_deserialize,
  _Wait_SendGoal_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_SendGoal_Request,
  _Wait_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _Wait_SendGoal_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_SendGoal_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_SendGoal_Request)() {
  return &_Wait_SendGoal_Request__type_support;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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


typedef nav2_msgs__action__Wait_SendGoal_Response _Wait_SendGoal_Response__ros_msg_type;

static bool _Wait_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_SendGoal_Response__ros_msg_type * ros_message = (_Wait_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: accepted
  rv = ucdr_serialize_bool(cdr, (ros_message->accepted) ? 0x01 : 0x00);
  // Member: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->stamp, cdr);

  return rv;
}

static bool _Wait_SendGoal_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_SendGoal_Response__ros_msg_type * ros_message = (_Wait_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
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
size_t get_serialized_size_nav2_msgs__action__Wait_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_SendGoal_Response__ros_msg_type * ros_message = (const _Wait_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
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

static uint32_t _Wait_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_SendGoal_Response(
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

static size_t _Wait_SendGoal_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_SendGoal_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_SendGoal_Response = {
  "nav2_msgs::action",
  "Wait_SendGoal_Response",
  _Wait_SendGoal_Response__cdr_serialize,
  _Wait_SendGoal_Response__cdr_deserialize,
  _Wait_SendGoal_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_SendGoal_Response,
  _Wait_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _Wait_SendGoal_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_SendGoal_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_SendGoal_Response)() {
  return &_Wait_SendGoal_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/action/wait.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Wait_SendGoal__callbacks = {
  "nav2_msgs::action",
  "Wait_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_SendGoal_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_SendGoal_Response),
};

static rosidl_service_type_support_t Wait_SendGoal__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &Wait_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_SendGoal)() {
  return &Wait_SendGoal__handle;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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


typedef nav2_msgs__action__Wait_GetResult_Request _Wait_GetResult_Request__ros_msg_type;

static bool _Wait_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_GetResult_Request__ros_msg_type * ros_message = (_Wait_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);

  return rv;
}

static bool _Wait_GetResult_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_GetResult_Request__ros_msg_type * ros_message = (_Wait_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_GetResult_Request__ros_msg_type * ros_message = (const _Wait_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_GetResult_Request(
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

static size_t _Wait_GetResult_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_GetResult_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_GetResult_Request = {
  "nav2_msgs::action",
  "Wait_GetResult_Request",
  _Wait_GetResult_Request__cdr_serialize,
  _Wait_GetResult_Request__cdr_deserialize,
  _Wait_GetResult_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_GetResult_Request,
  _Wait_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _Wait_GetResult_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_GetResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_GetResult_Request)() {
  return &_Wait_GetResult_Request__type_support;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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
// #include "nav2_msgs/action/detail/wait__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__Wait_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__Wait_Result(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Result)();


typedef nav2_msgs__action__Wait_GetResult_Response _Wait_GetResult_Response__ros_msg_type;

static bool _Wait_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_GetResult_Response__ros_msg_type * ros_message = (_Wait_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: status
  rv = ucdr_serialize_int8_t(cdr, ros_message->status);
  // Member: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Result
      )()->data))->cdr_serialize(&ros_message->result, cdr);

  return rv;
}

static bool _Wait_GetResult_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_GetResult_Response__ros_msg_type * ros_message = (_Wait_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: status
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->status);
  // Field name: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Result
      )()->data))->cdr_deserialize(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_GetResult_Response__ros_msg_type * ros_message = (const _Wait_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: status
  {
    const size_t item_size = sizeof(ros_message->status);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: result
  current_alignment +=
    get_serialized_size_nav2_msgs__action__Wait_Result(&ros_message->result, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_GetResult_Response(
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
    max_serialized_size_nav2_msgs__action__Wait_Result(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Wait_GetResult_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_GetResult_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_GetResult_Response = {
  "nav2_msgs::action",
  "Wait_GetResult_Response",
  _Wait_GetResult_Response__cdr_serialize,
  _Wait_GetResult_Response__cdr_deserialize,
  _Wait_GetResult_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_GetResult_Response,
  _Wait_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _Wait_GetResult_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_GetResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_GetResult_Response)() {
  return &_Wait_GetResult_Response__type_support;
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
// #include "nav2_msgs/action/wait.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Wait_GetResult__callbacks = {
  "nav2_msgs::action",
  "Wait_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_GetResult_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_GetResult_Response),
};

static rosidl_service_type_support_t Wait_GetResult__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &Wait_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_GetResult)() {
  return &Wait_GetResult__handle;
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
// #include "nav2_msgs/action/detail/wait__struct.h"
// already included above
// #include "nav2_msgs/action/detail/wait__functions.h"

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
// #include "nav2_msgs/action/detail/wait__functions.h"  // feedback
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__action__Wait_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__action__Wait_Feedback(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Feedback)();
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


typedef nav2_msgs__action__Wait_FeedbackMessage _Wait_FeedbackMessage__ros_msg_type;

static bool _Wait_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Wait_FeedbackMessage__ros_msg_type * ros_message = (_Wait_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Feedback
      )()->data))->cdr_serialize(&ros_message->feedback, cdr);

  return rv;
}

static bool _Wait_FeedbackMessage__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Wait_FeedbackMessage__ros_msg_type * ros_message = (_Wait_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_Feedback
      )()->data))->cdr_deserialize(cdr, &ros_message->feedback);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__action__Wait_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Wait_FeedbackMessage__ros_msg_type * ros_message = (const _Wait_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: feedback
  current_alignment +=
    get_serialized_size_nav2_msgs__action__Wait_Feedback(&ros_message->feedback, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Wait_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__action__Wait_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__action__Wait_FeedbackMessage(
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
    max_serialized_size_nav2_msgs__action__Wait_Feedback(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Wait_FeedbackMessage__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__action__Wait_FeedbackMessage(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Wait_FeedbackMessage = {
  "nav2_msgs::action",
  "Wait_FeedbackMessage",
  _Wait_FeedbackMessage__cdr_serialize,
  _Wait_FeedbackMessage__cdr_deserialize,
  _Wait_FeedbackMessage__get_serialized_size,
  get_serialized_size_nav2_msgs__action__Wait_FeedbackMessage,
  _Wait_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _Wait_FeedbackMessage__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Wait_FeedbackMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, action, Wait_FeedbackMessage)() {
  return &_Wait_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
