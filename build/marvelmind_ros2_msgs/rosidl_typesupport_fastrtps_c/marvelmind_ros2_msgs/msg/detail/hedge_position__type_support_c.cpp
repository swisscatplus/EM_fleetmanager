// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgePosition.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__functions.h"
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


using _HedgePosition__ros_msg_type = marvelmind_ros2_msgs__msg__HedgePosition;

static bool _HedgePosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HedgePosition__ros_msg_type * ros_message = static_cast<const _HedgePosition__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp_ms
  {
    cdr << ros_message->timestamp_ms;
  }

  // Field name: x_m
  {
    cdr << ros_message->x_m;
  }

  // Field name: y_m
  {
    cdr << ros_message->y_m;
  }

  // Field name: z_m
  {
    cdr << ros_message->z_m;
  }

  // Field name: flags
  {
    cdr << ros_message->flags;
  }

  return true;
}

static bool _HedgePosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HedgePosition__ros_msg_type * ros_message = static_cast<_HedgePosition__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp_ms
  {
    cdr >> ros_message->timestamp_ms;
  }

  // Field name: x_m
  {
    cdr >> ros_message->x_m;
  }

  // Field name: y_m
  {
    cdr >> ros_message->y_m;
  }

  // Field name: z_m
  {
    cdr >> ros_message->z_m;
  }

  // Field name: flags
  {
    cdr >> ros_message->flags;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HedgePosition__ros_msg_type * ros_message = static_cast<const _HedgePosition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name timestamp_ms
  {
    size_t item_size = sizeof(ros_message->timestamp_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_m
  {
    size_t item_size = sizeof(ros_message->x_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_m
  {
    size_t item_size = sizeof(ros_message->y_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name z_m
  {
    size_t item_size = sizeof(ros_message->z_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flags
  {
    size_t item_size = sizeof(ros_message->flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgePosition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: timestamp_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: x_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: z_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: flags
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _HedgePosition__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgePosition(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HedgePosition = {
  "marvelmind_ros2_msgs::msg",
  "HedgePosition",
  _HedgePosition__cdr_serialize,
  _HedgePosition__cdr_deserialize,
  _HedgePosition__get_serialized_size,
  _HedgePosition__max_serialized_size
};

static rosidl_message_type_support_t _HedgePosition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HedgePosition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, msg, HedgePosition)() {
  return &_HedgePosition__type_support;
}

#if defined(__cplusplus)
}
#endif
