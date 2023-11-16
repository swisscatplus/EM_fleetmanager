// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from robot_localization:srv/ToLL.idl
// generated code does not contain a copyright notice
#include "robot_localization/srv/detail/to_ll__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/detail/to_ll__struct.h"
#include "robot_localization/srv/detail/to_ll__functions.h"

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

#include "geometry_msgs/msg/detail/point__functions.h"  // map_point

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point)();


typedef robot_localization__srv__ToLL_Request _ToLL_Request__ros_msg_type;

static bool _ToLL_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ToLL_Request__ros_msg_type * ros_message = (_ToLL_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: map_point
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point
      )()->data))->cdr_serialize(&ros_message->map_point, cdr);

  return rv;
}

static bool _ToLL_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ToLL_Request__ros_msg_type * ros_message = (_ToLL_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: map_point
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point
      )()->data))->cdr_deserialize(cdr, &ros_message->map_point);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__ToLL_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ToLL_Request__ros_msg_type * ros_message = (const _ToLL_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map_point
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Point(&ros_message->map_point, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ToLL_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__ToLL_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__ToLL_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map_point
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Point(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ToLL_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__ToLL_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ToLL_Request = {
  "robot_localization::srv",
  "ToLL_Request",
  _ToLL_Request__cdr_serialize,
  _ToLL_Request__cdr_deserialize,
  _ToLL_Request__get_serialized_size,
  get_serialized_size_robot_localization__srv__ToLL_Request,
  _ToLL_Request__max_serialized_size
};

static rosidl_message_type_support_t _ToLL_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ToLL_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToLL_Request)() {
  return &_ToLL_Request__type_support;
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
// #include "robot_localization/srv/detail/to_ll__struct.h"
// already included above
// #include "robot_localization/srv/detail/to_ll__functions.h"

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

#include "geographic_msgs/msg/detail/geo_point__functions.h"  // ll_point

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t get_serialized_size_geographic_msgs__msg__GeoPoint(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
size_t max_serialized_size_geographic_msgs__msg__GeoPoint(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_robot_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geographic_msgs, msg, GeoPoint)();


typedef robot_localization__srv__ToLL_Response _ToLL_Response__ros_msg_type;

static bool _ToLL_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ToLL_Response__ros_msg_type * ros_message = (_ToLL_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: ll_point
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geographic_msgs, msg, GeoPoint
      )()->data))->cdr_serialize(&ros_message->ll_point, cdr);

  return rv;
}

static bool _ToLL_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ToLL_Response__ros_msg_type * ros_message = (_ToLL_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: ll_point
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geographic_msgs, msg, GeoPoint
      )()->data))->cdr_deserialize(cdr, &ros_message->ll_point);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t get_serialized_size_robot_localization__srv__ToLL_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ToLL_Response__ros_msg_type * ros_message = (const _ToLL_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: ll_point
  current_alignment +=
    get_serialized_size_geographic_msgs__msg__GeoPoint(&ros_message->ll_point, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ToLL_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_robot_localization__srv__ToLL_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_robot_localization
size_t max_serialized_size_robot_localization__srv__ToLL_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: ll_point
  current_alignment +=
    max_serialized_size_geographic_msgs__msg__GeoPoint(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ToLL_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_robot_localization__srv__ToLL_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ToLL_Response = {
  "robot_localization::srv",
  "ToLL_Response",
  _ToLL_Response__cdr_serialize,
  _ToLL_Response__cdr_deserialize,
  _ToLL_Response__get_serialized_size,
  get_serialized_size_robot_localization__srv__ToLL_Response,
  _ToLL_Response__max_serialized_size
};

static rosidl_message_type_support_t _ToLL_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ToLL_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToLL_Response)() {
  return &_ToLL_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "robot_localization/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "robot_localization/srv/to_ll.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ToLL__callbacks = {
  "robot_localization::srv",
  "ToLL",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToLL_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToLL_Response),
};

static rosidl_service_type_support_t ToLL__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &ToLL__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, robot_localization, srv, ToLL)() {
  return &ToLL__handle;
}

#if defined(__cplusplus)
}
#endif
