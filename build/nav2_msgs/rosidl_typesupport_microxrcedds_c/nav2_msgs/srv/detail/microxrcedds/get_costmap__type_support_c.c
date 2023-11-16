// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:srv/GetCostmap.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/srv/detail/get_costmap__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/detail/get_costmap__struct.h"
#include "nav2_msgs/srv/detail/get_costmap__functions.h"

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

#include "nav2_msgs/msg/detail/costmap_meta_data__functions.h"  // specs

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__msg__CostmapMetaData(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__msg__CostmapMetaData(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, CostmapMetaData)();


typedef nav2_msgs__srv__GetCostmap_Request _GetCostmap_Request__ros_msg_type;

static bool _GetCostmap_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetCostmap_Request__ros_msg_type * ros_message = (_GetCostmap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: specs
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, CostmapMetaData
      )()->data))->cdr_serialize(&ros_message->specs, cdr);

  return rv;
}

static bool _GetCostmap_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetCostmap_Request__ros_msg_type * ros_message = (_GetCostmap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: specs
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, CostmapMetaData
      )()->data))->cdr_deserialize(cdr, &ros_message->specs);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__GetCostmap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetCostmap_Request__ros_msg_type * ros_message = (const _GetCostmap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: specs
  current_alignment +=
    get_serialized_size_nav2_msgs__msg__CostmapMetaData(&ros_message->specs, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GetCostmap_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__GetCostmap_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__GetCostmap_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: specs
  current_alignment +=
    max_serialized_size_nav2_msgs__msg__CostmapMetaData(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GetCostmap_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__GetCostmap_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetCostmap_Request = {
  "nav2_msgs::srv",
  "GetCostmap_Request",
  _GetCostmap_Request__cdr_serialize,
  _GetCostmap_Request__cdr_deserialize,
  _GetCostmap_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__GetCostmap_Request,
  _GetCostmap_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetCostmap_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetCostmap_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, GetCostmap_Request)() {
  return &_GetCostmap_Request__type_support;
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
// #include "nav2_msgs/srv/detail/get_costmap__struct.h"
// already included above
// #include "nav2_msgs/srv/detail/get_costmap__functions.h"

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

#include "nav2_msgs/msg/detail/costmap__functions.h"  // map

// forward declare type support functions
size_t get_serialized_size_nav2_msgs__msg__Costmap(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav2_msgs__msg__Costmap(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, Costmap)();


typedef nav2_msgs__srv__GetCostmap_Response _GetCostmap_Response__ros_msg_type;

static bool _GetCostmap_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetCostmap_Response__ros_msg_type * ros_message = (_GetCostmap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: map
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, Costmap
      )()->data))->cdr_serialize(&ros_message->map, cdr);

  return rv;
}

static bool _GetCostmap_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetCostmap_Response__ros_msg_type * ros_message = (_GetCostmap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: map
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, msg, Costmap
      )()->data))->cdr_deserialize(cdr, &ros_message->map);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__GetCostmap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetCostmap_Response__ros_msg_type * ros_message = (const _GetCostmap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map
  current_alignment +=
    get_serialized_size_nav2_msgs__msg__Costmap(&ros_message->map, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GetCostmap_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__GetCostmap_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__GetCostmap_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map
  current_alignment +=
    max_serialized_size_nav2_msgs__msg__Costmap(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GetCostmap_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__GetCostmap_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetCostmap_Response = {
  "nav2_msgs::srv",
  "GetCostmap_Response",
  _GetCostmap_Response__cdr_serialize,
  _GetCostmap_Response__cdr_deserialize,
  _GetCostmap_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__GetCostmap_Response,
  _GetCostmap_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetCostmap_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetCostmap_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, GetCostmap_Response)() {
  return &_GetCostmap_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/get_costmap.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetCostmap__callbacks = {
  "nav2_msgs::srv",
  "GetCostmap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, GetCostmap_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, GetCostmap_Response),
};

static rosidl_service_type_support_t GetCostmap__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &GetCostmap__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, GetCostmap)() {
  return &GetCostmap__handle;
}

#if defined(__cplusplus)
}
#endif
