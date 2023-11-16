// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeQuality.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__functions.h"
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


using _HedgeQuality__ros_msg_type = marvelmind_ros2_msgs__msg__HedgeQuality;

static bool _HedgeQuality__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HedgeQuality__ros_msg_type * ros_message = static_cast<const _HedgeQuality__ros_msg_type *>(untyped_ros_message);
  // Field name: address
  {
    cdr << ros_message->address;
  }

  // Field name: quality_percents
  {
    cdr << ros_message->quality_percents;
  }

  return true;
}

static bool _HedgeQuality__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HedgeQuality__ros_msg_type * ros_message = static_cast<_HedgeQuality__ros_msg_type *>(untyped_ros_message);
  // Field name: address
  {
    cdr >> ros_message->address;
  }

  // Field name: quality_percents
  {
    cdr >> ros_message->quality_percents;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HedgeQuality__ros_msg_type * ros_message = static_cast<const _HedgeQuality__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name address
  {
    size_t item_size = sizeof(ros_message->address);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name quality_percents
  {
    size_t item_size = sizeof(ros_message->quality_percents);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HedgeQuality__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: address
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: quality_percents
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _HedgeQuality__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_marvelmind_ros2_msgs__msg__HedgeQuality(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HedgeQuality = {
  "marvelmind_ros2_msgs::msg",
  "HedgeQuality",
  _HedgeQuality__cdr_serialize,
  _HedgeQuality__cdr_deserialize,
  _HedgeQuality__get_serialized_size,
  _HedgeQuality__max_serialized_size
};

static rosidl_message_type_support_t _HedgeQuality__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HedgeQuality,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, msg, HedgeQuality)() {
  return &_HedgeQuality__type_support;
}

#if defined(__cplusplus)
}
#endif
