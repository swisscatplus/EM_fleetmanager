// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from robot_localization:srv/ToggleFilterProcessing.idl
// generated code does not contain a copyright notice
#include "robot_localization/srv/detail/toggle_filter_processing__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/detail/toggle_filter_processing__struct.h"
#include "robot_localization/srv/detail/toggle_filter_processing__functions.h"

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


typedef robot_localization__srv__ToggleFilterProcessing_Request _ToggleFilterProcessing_Request__ros_msg_type;

static bool _ToggleFilterProcessing_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ToggleFilterProcessing_Request__ros_msg_type * ros_message = (_ToggleFilterProcessing_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: on
  rv = ucdr_serialize_bool(cdr, (ros_message->on) ? 0x01 : 0x00);

  return rv;
}

static bool _ToggleFilterProcessing_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ToggleFilterProcessing_Request__ros_msg_type * ros_message = (_ToggleFilterProcessing_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: on
  rv = ucdr_deserialize_bool(cdr, &ros_message->on);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__ToggleFilterProcessing_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ToggleFilterProcessing_Request__ros_msg_type * ros_message = (const _ToggleFilterProcessing_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: on
  {
    const size_t item_size = sizeof(ros_message->on);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ToggleFilterProcessing_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__ToggleFilterProcessing_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__ToggleFilterProcessing_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: on
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static size_t _ToggleFilterProcessing_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__ToggleFilterProcessing_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ToggleFilterProcessing_Request = {
  "robot_localization::srv",
  "ToggleFilterProcessing_Request",
  _ToggleFilterProcessing_Request__cdr_serialize,
  _ToggleFilterProcessing_Request__cdr_deserialize,
  _ToggleFilterProcessing_Request__get_serialized_size,
  get_serialized_size_robot_localization__srv__ToggleFilterProcessing_Request,
  _ToggleFilterProcessing_Request__max_serialized_size
};

static rosidl_message_type_support_t _ToggleFilterProcessing_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ToggleFilterProcessing_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToggleFilterProcessing_Request)() {
  return &_ToggleFilterProcessing_Request__type_support;
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
// #include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "robot_localization/srv/detail/toggle_filter_processing__struct.h"
// already included above
// #include "robot_localization/srv/detail/toggle_filter_processing__functions.h"

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


typedef robot_localization__srv__ToggleFilterProcessing_Response _ToggleFilterProcessing_Response__ros_msg_type;

static bool _ToggleFilterProcessing_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ToggleFilterProcessing_Response__ros_msg_type * ros_message = (_ToggleFilterProcessing_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: status
  rv = ucdr_serialize_bool(cdr, (ros_message->status) ? 0x01 : 0x00);

  return rv;
}

static bool _ToggleFilterProcessing_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ToggleFilterProcessing_Response__ros_msg_type * ros_message = (_ToggleFilterProcessing_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: status
  rv = ucdr_deserialize_bool(cdr, &ros_message->status);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__ToggleFilterProcessing_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ToggleFilterProcessing_Response__ros_msg_type * ros_message = (const _ToggleFilterProcessing_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: status
  {
    const size_t item_size = sizeof(ros_message->status);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ToggleFilterProcessing_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__ToggleFilterProcessing_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__ToggleFilterProcessing_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: status
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static size_t _ToggleFilterProcessing_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__ToggleFilterProcessing_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ToggleFilterProcessing_Response = {
  "robot_localization::srv",
  "ToggleFilterProcessing_Response",
  _ToggleFilterProcessing_Response__cdr_serialize,
  _ToggleFilterProcessing_Response__cdr_deserialize,
  _ToggleFilterProcessing_Response__get_serialized_size,
  get_serialized_size_robot_localization__srv__ToggleFilterProcessing_Response,
  _ToggleFilterProcessing_Response__max_serialized_size
};

static rosidl_message_type_support_t _ToggleFilterProcessing_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ToggleFilterProcessing_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToggleFilterProcessing_Response)() {
  return &_ToggleFilterProcessing_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/toggle_filter_processing.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ToggleFilterProcessing__callbacks = {
  "robot_localization::srv",
  "ToggleFilterProcessing",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToggleFilterProcessing_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToggleFilterProcessing_Response),
};

static rosidl_service_type_support_t ToggleFilterProcessing__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &ToggleFilterProcessing__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToggleFilterProcessing)() {
  return &ToggleFilterProcessing__handle;
}

#if defined(__cplusplus)
}
#endif
