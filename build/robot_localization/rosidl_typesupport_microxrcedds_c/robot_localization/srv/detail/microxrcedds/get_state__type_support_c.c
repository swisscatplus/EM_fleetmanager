// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from robot_localization:srv/GetState.idl
// generated code does not contain a copyright notice
#include "robot_localization/srv/detail/get_state__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/detail/get_state__struct.h"
#include "robot_localization/srv/detail/get_state__functions.h"

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

#include "builtin_interfaces/msg/detail/time__functions.h"  // time_stamp
#include "rosidl_runtime_c/string.h"  // frame_id
#include "rosidl_runtime_c/string_functions.h"  // frame_id

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time)();


typedef robot_localization__srv__GetState_Request _GetState_Request__ros_msg_type;

static bool _GetState_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetState_Request__ros_msg_type * ros_message = (_GetState_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: time_stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->time_stamp, cdr);
  // Member: frame_id
 {
    uint32_t string_len = (ros_message->frame_id.data == NULL) ? 0 : (uint32_t)strlen(ros_message->frame_id.data) + 1;
    ros_message->frame_id.size = (ros_message->frame_id.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->frame_id.data, string_len);
  }

  return rv;
}

static bool _GetState_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetState_Request__ros_msg_type * ros_message = (_GetState_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: time_stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->time_stamp);
  // Field name: frame_id
  {
    size_t capacity = ros_message->frame_id.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->frame_id.data, capacity, &string_size);
    if (rv) {
      ros_message->frame_id.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->frame_id.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__GetState_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetState_Request__ros_msg_type * ros_message = (const _GetState_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: time_stamp
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->time_stamp, current_alignment);
  // Member: frame_id
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->frame_id.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _GetState_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__GetState_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__GetState_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: time_stamp
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: frame_id
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _GetState_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__GetState_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetState_Request = {
  "robot_localization::srv",
  "GetState_Request",
  _GetState_Request__cdr_serialize,
  _GetState_Request__cdr_deserialize,
  _GetState_Request__get_serialized_size,
  get_serialized_size_robot_localization__srv__GetState_Request,
  _GetState_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetState_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetState_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, GetState_Request)() {
  return &_GetState_Request__type_support;
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
// #include "robot_localization/srv/detail/get_state__struct.h"
// already included above
// #include "robot_localization/srv/detail/get_state__functions.h"

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


typedef robot_localization__srv__GetState_Response _GetState_Response__ros_msg_type;

static bool _GetState_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetState_Response__ros_msg_type * ros_message = (_GetState_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: state
  {
    const size_t size = 15;
    rv = ucdr_serialize_array_double(cdr, ros_message->state, size);
  }
  // Member: covariance
  {
    const size_t size = 225;
    rv = ucdr_serialize_array_double(cdr, ros_message->covariance, size);
  }

  return rv;
}

static bool _GetState_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetState_Response__ros_msg_type * ros_message = (_GetState_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: state
  {
    const size_t size = 15;
    rv = ucdr_deserialize_array_double(cdr, ros_message->state, size);
  }
  // Field name: covariance
  {
    const size_t size = 225;
    rv = ucdr_deserialize_array_double(cdr, ros_message->covariance, size);
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__GetState_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetState_Response__ros_msg_type * ros_message = (const _GetState_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: state
  {
    const size_t array_size = 15;
    const size_t item_size = sizeof(ros_message->state[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: covariance
  {
    const size_t array_size = 225;
    const size_t item_size = sizeof(ros_message->covariance[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GetState_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__GetState_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__GetState_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: state
  {
    const size_t array_size = 15;
    current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + (array_size * sizeof(double));
  }
  // Member: covariance
  {
    const size_t array_size = 225;
    current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + (array_size * sizeof(double));
  }

  return current_alignment - initial_alignment;
}

static size_t _GetState_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__GetState_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetState_Response = {
  "robot_localization::srv",
  "GetState_Response",
  _GetState_Response__cdr_serialize,
  _GetState_Response__cdr_deserialize,
  _GetState_Response__get_serialized_size,
  get_serialized_size_robot_localization__srv__GetState_Response,
  _GetState_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetState_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetState_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, GetState_Response)() {
  return &_GetState_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/get_state.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetState__callbacks = {
  "robot_localization::srv",
  "GetState",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, GetState_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, GetState_Response),
};

static rosidl_service_type_support_t GetState__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &GetState__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, GetState)() {
  return &GetState__handle;
}

#if defined(__cplusplus)
}
#endif
