// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from nav2_msgs:srv/ClearCostmapAroundRobot.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/srv/detail/clear_costmap_around_robot__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/detail/clear_costmap_around_robot__struct.h"
#include "nav2_msgs/srv/detail/clear_costmap_around_robot__functions.h"

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


typedef nav2_msgs__srv__ClearCostmapAroundRobot_Request _ClearCostmapAroundRobot_Request__ros_msg_type;

static bool _ClearCostmapAroundRobot_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ClearCostmapAroundRobot_Request__ros_msg_type * ros_message = (_ClearCostmapAroundRobot_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: reset_distance
  rv = ucdr_serialize_float(cdr, ros_message->reset_distance);

  return rv;
}

static bool _ClearCostmapAroundRobot_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ClearCostmapAroundRobot_Request__ros_msg_type * ros_message = (_ClearCostmapAroundRobot_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: reset_distance
  rv = ucdr_deserialize_float(cdr, &ros_message->reset_distance);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ClearCostmapAroundRobot_Request__ros_msg_type * ros_message = (const _ClearCostmapAroundRobot_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: reset_distance
  {
    const size_t item_size = sizeof(ros_message->reset_distance);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ClearCostmapAroundRobot_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: reset_distance
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static size_t _ClearCostmapAroundRobot_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ClearCostmapAroundRobot_Request = {
  "nav2_msgs::srv",
  "ClearCostmapAroundRobot_Request",
  _ClearCostmapAroundRobot_Request__cdr_serialize,
  _ClearCostmapAroundRobot_Request__cdr_deserialize,
  _ClearCostmapAroundRobot_Request__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Request,
  _ClearCostmapAroundRobot_Request__max_serialized_size
};

static rosidl_message_type_support_t _ClearCostmapAroundRobot_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ClearCostmapAroundRobot_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearCostmapAroundRobot_Request)() {
  return &_ClearCostmapAroundRobot_Request__type_support;
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
// #include "nav2_msgs/srv/detail/clear_costmap_around_robot__struct.h"
// already included above
// #include "nav2_msgs/srv/detail/clear_costmap_around_robot__functions.h"

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

#include "std_msgs/msg/detail/empty__functions.h"  // response

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


typedef nav2_msgs__srv__ClearCostmapAroundRobot_Response _ClearCostmapAroundRobot_Response__ros_msg_type;

static bool _ClearCostmapAroundRobot_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ClearCostmapAroundRobot_Response__ros_msg_type * ros_message = (_ClearCostmapAroundRobot_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: response
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_serialize(&ros_message->response, cdr);

  return rv;
}

static bool _ClearCostmapAroundRobot_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ClearCostmapAroundRobot_Response__ros_msg_type * ros_message = (_ClearCostmapAroundRobot_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: response
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Empty
      )()->data))->cdr_deserialize(cdr, &ros_message->response);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ClearCostmapAroundRobot_Response__ros_msg_type * ros_message = (const _ClearCostmapAroundRobot_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: response
  current_alignment +=
    get_serialized_size_std_msgs__msg__Empty(&ros_message->response, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ClearCostmapAroundRobot_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Response(
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

static size_t _ClearCostmapAroundRobot_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ClearCostmapAroundRobot_Response = {
  "nav2_msgs::srv",
  "ClearCostmapAroundRobot_Response",
  _ClearCostmapAroundRobot_Response__cdr_serialize,
  _ClearCostmapAroundRobot_Response__cdr_deserialize,
  _ClearCostmapAroundRobot_Response__get_serialized_size,
  get_serialized_size_nav2_msgs__srv__ClearCostmapAroundRobot_Response,
  _ClearCostmapAroundRobot_Response__max_serialized_size
};

static rosidl_message_type_support_t _ClearCostmapAroundRobot_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ClearCostmapAroundRobot_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearCostmapAroundRobot_Response)() {
  return &_ClearCostmapAroundRobot_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "nav2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "nav2_msgs/srv/clear_costmap_around_robot.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ClearCostmapAroundRobot__callbacks = {
  "nav2_msgs::srv",
  "ClearCostmapAroundRobot",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearCostmapAroundRobot_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearCostmapAroundRobot_Response),
};

static rosidl_service_type_support_t ClearCostmapAroundRobot__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &ClearCostmapAroundRobot__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, nav2_msgs, srv, ClearCostmapAroundRobot)() {
  return &ClearCostmapAroundRobot__handle;
}

#if defined(__cplusplus)
}
#endif
