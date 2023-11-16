// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:srv/ClearEntireCostmap.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/srv/detail/clear_entire_costmap__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/detail/clear_entire_costmap__struct.h"
#include "nav2_msgs/srv/detail/clear_entire_costmap__functions.h"

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

#include "std_msgs/msg/detail/empty__functions.h"  // request

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


typedef nav2_msgs__srv__ClearEntireCostmap_Request _ClearEntireCostmap_Request__ros_msg_type;

static bool _ClearEntireCostmap_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ClearEntireCostmap_Request__ros_msg_type * ros_message = (_ClearEntireCostmap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: request
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_serialize(&ros_message->request, cdr);

  return rv;
}

static bool _ClearEntireCostmap_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ClearEntireCostmap_Request__ros_msg_type * ros_message = (_ClearEntireCostmap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: request
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_deserialize(cdr, &ros_message->request);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ClearEntireCostmap_Request__ros_msg_type * ros_message = (const _ClearEntireCostmap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: request
  current_alignment +=
    get_serialized_size_std_msgs__msg__Empty(&ros_message->request, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ClearEntireCostmap_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: request
  current_alignment +=
    max_serialized_size_std_msgs__msg__Empty(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ClearEntireCostmap_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ClearEntireCostmap_Request = {
  "nav2_msgs::srv",
  "ClearEntireCostmap_Request",
  _ClearEntireCostmap_Request__cdr_serialize,
  _ClearEntireCostmap_Request__cdr_deserialize,
  _ClearEntireCostmap_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Request,
  _ClearEntireCostmap_Request__max_serialized_size
};

static rosidl_message_type_support_t _ClearEntireCostmap_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ClearEntireCostmap_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearEntireCostmap_Request)() {
  return &_ClearEntireCostmap_Request__type_support;
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
// #include "nav2_msgs/srv/detail/clear_entire_costmap__struct.h"
// already included above
// #include "nav2_msgs/srv/detail/clear_entire_costmap__functions.h"

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
// #include "std_msgs/msg/detail/empty__functions.h"  // response

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


typedef nav2_msgs__srv__ClearEntireCostmap_Response _ClearEntireCostmap_Response__ros_msg_type;

static bool _ClearEntireCostmap_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ClearEntireCostmap_Response__ros_msg_type * ros_message = (_ClearEntireCostmap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: response
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_serialize(&ros_message->response, cdr);

  return rv;
}

static bool _ClearEntireCostmap_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ClearEntireCostmap_Response__ros_msg_type * ros_message = (_ClearEntireCostmap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: response
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_deserialize(cdr, &ros_message->response);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ClearEntireCostmap_Response__ros_msg_type * ros_message = (const _ClearEntireCostmap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: response
  current_alignment +=
    get_serialized_size_std_msgs__msg__Empty(&ros_message->response, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ClearEntireCostmap_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: response
  current_alignment +=
    max_serialized_size_std_msgs__msg__Empty(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ClearEntireCostmap_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ClearEntireCostmap_Response = {
  "nav2_msgs::srv",
  "ClearEntireCostmap_Response",
  _ClearEntireCostmap_Response__cdr_serialize,
  _ClearEntireCostmap_Response__cdr_deserialize,
  _ClearEntireCostmap_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__ClearEntireCostmap_Response,
  _ClearEntireCostmap_Response__max_serialized_size
};

static rosidl_message_type_support_t _ClearEntireCostmap_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ClearEntireCostmap_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearEntireCostmap_Response)() {
  return &_ClearEntireCostmap_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/clear_entire_costmap.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ClearEntireCostmap__callbacks = {
  "nav2_msgs::srv",
  "ClearEntireCostmap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearEntireCostmap_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearEntireCostmap_Response),
};

static rosidl_service_type_support_t ClearEntireCostmap__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &ClearEntireCostmap__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearEntireCostmap)() {
  return &ClearEntireCostmap__handle;
}

#if defined(__cplusplus)
}
#endif
