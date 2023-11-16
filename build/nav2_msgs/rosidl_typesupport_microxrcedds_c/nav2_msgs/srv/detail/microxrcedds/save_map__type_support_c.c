// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:srv/SaveMap.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/srv/detail/save_map__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/detail/save_map__struct.h"
#include "nav2_msgs/srv/detail/save_map__functions.h"

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

#include "rosidl_runtime_c/string.h"  // image_format, map_mode, map_topic, map_url
#include "rosidl_runtime_c/string_functions.h"  // image_format, map_mode, map_topic, map_url

// forward declare type support functions


typedef nav2_msgs__srv__SaveMap_Request _SaveMap_Request__ros_msg_type;

static bool _SaveMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _SaveMap_Request__ros_msg_type * ros_message = (_SaveMap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: map_topic
 {
    uint32_t string_len = (ros_message->map_topic.data == NULL) ? 0 : (uint32_t)strlen(ros_message->map_topic.data) + 1;
    ros_message->map_topic.size = (ros_message->map_topic.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->map_topic.data, string_len);
  }
  // Member: map_url
 {
    uint32_t string_len = (ros_message->map_url.data == NULL) ? 0 : (uint32_t)strlen(ros_message->map_url.data) + 1;
    ros_message->map_url.size = (ros_message->map_url.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->map_url.data, string_len);
  }
  // Member: image_format
 {
    uint32_t string_len = (ros_message->image_format.data == NULL) ? 0 : (uint32_t)strlen(ros_message->image_format.data) + 1;
    ros_message->image_format.size = (ros_message->image_format.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->image_format.data, string_len);
  }
  // Member: map_mode
 {
    uint32_t string_len = (ros_message->map_mode.data == NULL) ? 0 : (uint32_t)strlen(ros_message->map_mode.data) + 1;
    ros_message->map_mode.size = (ros_message->map_mode.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->map_mode.data, string_len);
  }
  // Member: free_thresh
  rv = ucdr_serialize_float(cdr, ros_message->free_thresh);
  // Member: occupied_thresh
  rv = ucdr_serialize_float(cdr, ros_message->occupied_thresh);

  return rv;
}

static bool _SaveMap_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _SaveMap_Request__ros_msg_type * ros_message = (_SaveMap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: map_topic
  {
    size_t capacity = ros_message->map_topic.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->map_topic.data, capacity, &string_size);
    if (rv) {
      ros_message->map_topic.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->map_topic.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: map_url
  {
    size_t capacity = ros_message->map_url.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->map_url.data, capacity, &string_size);
    if (rv) {
      ros_message->map_url.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->map_url.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: image_format
  {
    size_t capacity = ros_message->image_format.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->image_format.data, capacity, &string_size);
    if (rv) {
      ros_message->image_format.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->image_format.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: map_mode
  {
    size_t capacity = ros_message->map_mode.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->map_mode.data, capacity, &string_size);
    if (rv) {
      ros_message->map_mode.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->map_mode.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: free_thresh
  rv = ucdr_deserialize_float(cdr, &ros_message->free_thresh);
  // Field name: occupied_thresh
  rv = ucdr_deserialize_float(cdr, &ros_message->occupied_thresh);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__SaveMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _SaveMap_Request__ros_msg_type * ros_message = (const _SaveMap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map_topic
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->map_topic.size + 1;
  // Member: map_url
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->map_url.size + 1;
  // Member: image_format
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->image_format.size + 1;
  // Member: map_mode
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->map_mode.size + 1;
  // Member: free_thresh
  {
    const size_t item_size = sizeof(ros_message->free_thresh);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: occupied_thresh
  {
    const size_t item_size = sizeof(ros_message->occupied_thresh);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SaveMap_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__SaveMap_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__SaveMap_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map_topic
  *full_bounded = false;
  // Member: map_url
  *full_bounded = false;
  // Member: image_format
  *full_bounded = false;
  // Member: map_mode
  *full_bounded = false;
  // Member: free_thresh
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: occupied_thresh
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static size_t _SaveMap_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__SaveMap_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_SaveMap_Request = {
  "nav2_msgs::srv",
  "SaveMap_Request",
  _SaveMap_Request__cdr_serialize,
  _SaveMap_Request__cdr_deserialize,
  _SaveMap_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__SaveMap_Request,
  _SaveMap_Request__max_serialized_size
};

static rosidl_message_type_support_t _SaveMap_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_SaveMap_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, SaveMap_Request)() {
  return &_SaveMap_Request__type_support;
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
// #include "nav2_msgs/srv/detail/save_map__struct.h"
// already included above
// #include "nav2_msgs/srv/detail/save_map__functions.h"

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


typedef nav2_msgs__srv__SaveMap_Response _SaveMap_Response__ros_msg_type;

static bool _SaveMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _SaveMap_Response__ros_msg_type * ros_message = (_SaveMap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: result
  rv = ucdr_serialize_bool(cdr, (ros_message->result) ? 0x01 : 0x00);

  return rv;
}

static bool _SaveMap_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _SaveMap_Response__ros_msg_type * ros_message = (_SaveMap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: result
  rv = ucdr_deserialize_bool(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__SaveMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _SaveMap_Response__ros_msg_type * ros_message = (const _SaveMap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: result
  {
    const size_t item_size = sizeof(ros_message->result);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SaveMap_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__SaveMap_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__SaveMap_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: result
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static size_t _SaveMap_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__SaveMap_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_SaveMap_Response = {
  "nav2_msgs::srv",
  "SaveMap_Response",
  _SaveMap_Response__cdr_serialize,
  _SaveMap_Response__cdr_deserialize,
  _SaveMap_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__SaveMap_Response,
  _SaveMap_Response__max_serialized_size
};

static rosidl_message_type_support_t _SaveMap_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_SaveMap_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, SaveMap_Response)() {
  return &_SaveMap_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/save_map.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SaveMap__callbacks = {
  "nav2_msgs::srv",
  "SaveMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, SaveMap_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, SaveMap_Response),
};

static rosidl_service_type_support_t SaveMap__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &SaveMap__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, SaveMap)() {
  return &SaveMap__handle;
}

#if defined(__cplusplus)
}
#endif
