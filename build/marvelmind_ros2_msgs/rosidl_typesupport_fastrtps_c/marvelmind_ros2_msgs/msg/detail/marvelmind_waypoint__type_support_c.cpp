// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindWaypoint.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MarvelmindWaypoint__ros_msg_type = marvelmind_ros2_msgs__msg__MarvelmindWaypoint;

static bool _MarvelmindWaypoint__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MarvelmindWaypoint__ros_msg_type * ros_message = static_cast<const _MarvelmindWaypoint__ros_msg_type *>(untyped_ros_message);
  // Field name: total_items
  {
    cdr << ros_message->total_items;
  }

  // Field name: item_index
  {
    cdr << ros_message->item_index;
  }

  // Field name: movement_type
  {
    cdr << ros_message->movement_type;
  }

  // Field name: param1
  {
    cdr << ros_message->param1;
  }

  // Field name: param2
  {
    cdr << ros_message->param2;
  }

  // Field name: param3
  {
    cdr << ros_message->param3;
  }

  return true;
}

static bool _MarvelmindWaypoint__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MarvelmindWaypoint__ros_msg_type * ros_message = static_cast<_MarvelmindWaypoint__ros_msg_type *>(untyped_ros_message);
  // Field name: total_items
  {
    cdr >> ros_message->total_items;
  }

  // Field name: item_index
  {
    cdr >> ros_message->item_index;
  }

  // Field name: movement_type
  {
    cdr >> ros_message->movement_type;
  }

  // Field name: param1
  {
    cdr >> ros_message->param1;
  }

  // Field name: param2
  {
    cdr >> ros_message->param2;
  }

  // Field name: param3
  {
    cdr >> ros_message->param3;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindWaypoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MarvelmindWaypoint__ros_msg_type * ros_message = static_cast<const _MarvelmindWaypoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name total_items
  {
    size_t item_size = sizeof(ros_message->total_items);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name item_index
  {
    size_t item_size = sizeof(ros_message->item_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name movement_type
  {
    size_t item_size = sizeof(ros_message->movement_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name param1
  {
    size_t item_size = sizeof(ros_message->param1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name param2
  {
    size_t item_size = sizeof(ros_message->param2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name param3
  {
    size_t item_size = sizeof(ros_message->param3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MarvelmindWaypoint__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindWaypoint(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindWaypoint(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: total_items
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: item_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: movement_type
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: param1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: param2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: param3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _MarvelmindWaypoint__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_marvelmind_ros2_msgs__msg__MarvelmindWaypoint(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MarvelmindWaypoint = {
  "marvelmind_ros2_msgs::msg",
  "MarvelmindWaypoint",
  _MarvelmindWaypoint__cdr_serialize,
  _MarvelmindWaypoint__cdr_deserialize,
  _MarvelmindWaypoint__get_serialized_size,
  _MarvelmindWaypoint__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindWaypoint__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MarvelmindWaypoint,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, msg, MarvelmindWaypoint)() {
  return &_MarvelmindWaypoint__type_support;
}

#if defined(__cplusplus)
}
#endif
