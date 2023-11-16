// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from marvelmind_ros2_msgs:srv/MarvelmindAPI.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__struct.h"
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__functions.h"

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

#include "rosidl_runtime_c/primitives_sequence.h"  // request
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // request

// forward declare type support functions


typedef marvelmind_ros2_msgs__srv__MarvelmindAPI_Request _MarvelmindAPI_Request__ros_msg_type;

static bool _MarvelmindAPI_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _MarvelmindAPI_Request__ros_msg_type * ros_message = (_MarvelmindAPI_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: command_id
  rv = ucdr_serialize_int64_t(cdr, ros_message->command_id);
  // Member: request
  {
    const size_t size = ros_message->request.size;
    rv = ucdr_serialize_sequence_uint8_t(cdr, ros_message->request.data, size);
  }

  return rv;
}

static bool _MarvelmindAPI_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _MarvelmindAPI_Request__ros_msg_type * ros_message = (_MarvelmindAPI_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: command_id
  rv = ucdr_deserialize_int64_t(cdr, &ros_message->command_id);
  // Field name: request
  {
    uint32_t size;
    const size_t capacity = ros_message->request.capacity;
    rv = ucdr_deserialize_sequence_uint8_t(cdr, ros_message->request.data, capacity, &size);
    if (rv) {
      ros_message->request.size = size;
    } else if(size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->request.size = 0;
      ucdr_align_to(cdr, sizeof(uint8_t));
      ucdr_advance_buffer(cdr, size * sizeof(uint8_t));
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _MarvelmindAPI_Request__ros_msg_type * ros_message = (const _MarvelmindAPI_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: command_id
  {
    const size_t item_size = sizeof(ros_message->command_id);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: request
  {
    size_t sequence_size = ros_message->request.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    if (0 < sequence_size) {
      size_t item_size = sizeof(ros_message->request.data[0]);
      current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MarvelmindAPI_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: command_id
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: request
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _MarvelmindAPI_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_MarvelmindAPI_Request = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI_Request",
  _MarvelmindAPI_Request__cdr_serialize,
  _MarvelmindAPI_Request__cdr_deserialize,
  _MarvelmindAPI_Request__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request,
  _MarvelmindAPI_Request__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindAPI_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_MarvelmindAPI_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Request)() {
  return &_MarvelmindAPI_Request__type_support;
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
// #include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__struct.h"
// already included above
// #include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__functions.h"

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
// #include "rosidl_runtime_c/primitives_sequence.h"  // response
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // response

// forward declare type support functions


typedef marvelmind_ros2_msgs__srv__MarvelmindAPI_Response _MarvelmindAPI_Response__ros_msg_type;

static bool _MarvelmindAPI_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _MarvelmindAPI_Response__ros_msg_type * ros_message = (_MarvelmindAPI_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: success
  rv = ucdr_serialize_bool(cdr, (ros_message->success) ? 0x01 : 0x00);
  // Member: error_code
  rv = ucdr_serialize_int32_t(cdr, ros_message->error_code);
  // Member: response
  {
    const size_t size = ros_message->response.size;
    rv = ucdr_serialize_sequence_uint8_t(cdr, ros_message->response.data, size);
  }

  return rv;
}

static bool _MarvelmindAPI_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _MarvelmindAPI_Response__ros_msg_type * ros_message = (_MarvelmindAPI_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: success
  rv = ucdr_deserialize_bool(cdr, &ros_message->success);
  // Field name: error_code
  rv = ucdr_deserialize_int32_t(cdr, &ros_message->error_code);
  // Field name: response
  {
    uint32_t size;
    const size_t capacity = ros_message->response.capacity;
    rv = ucdr_deserialize_sequence_uint8_t(cdr, ros_message->response.data, capacity, &size);
    if (rv) {
      ros_message->response.size = size;
    } else if(size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->response.size = 0;
      ucdr_align_to(cdr, sizeof(uint8_t));
      ucdr_advance_buffer(cdr, size * sizeof(uint8_t));
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _MarvelmindAPI_Response__ros_msg_type * ros_message = (const _MarvelmindAPI_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: success
  {
    const size_t item_size = sizeof(ros_message->success);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: error_code
  {
    const size_t item_size = sizeof(ros_message->error_code);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: response
  {
    size_t sequence_size = ros_message->response.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    if (0 < sequence_size) {
      size_t item_size = sizeof(ros_message->response.data[0]);
      current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MarvelmindAPI_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: success
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: error_code
  current_alignment += ucdr_alignment(current_alignment, sizeof(int32_t)) + sizeof(int32_t);
  // Member: response
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _MarvelmindAPI_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_MarvelmindAPI_Response = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI_Response",
  _MarvelmindAPI_Response__cdr_serialize,
  _MarvelmindAPI_Response__cdr_deserialize,
  _MarvelmindAPI_Response__get_serialized_size,
  get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response,
  _MarvelmindAPI_Response__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindAPI_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_MarvelmindAPI_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Response)() {
  return &_MarvelmindAPI_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "marvelmind_ros2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "marvelmind_ros2_msgs/srv/marvelmind_api.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MarvelmindAPI__callbacks = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Response),
};

static rosidl_service_type_support_t MarvelmindAPI__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &MarvelmindAPI__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, marvelmind_ros2_msgs, srv, MarvelmindAPI)() {
  return &MarvelmindAPI__handle;
}

#if defined(__cplusplus)
}
#endif
