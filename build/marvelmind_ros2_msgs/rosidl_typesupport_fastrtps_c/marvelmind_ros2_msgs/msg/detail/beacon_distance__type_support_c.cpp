// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from marvelmind_ros2_msgs:msg/BeaconDistance.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__functions.h"
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


using _BeaconDistance__ros_msg_type = marvelmind_ros2_msgs__msg__BeaconDistance;

static bool _BeaconDistance__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BeaconDistance__ros_msg_type * ros_message = static_cast<const _BeaconDistance__ros_msg_type *>(untyped_ros_message);
  // Field name: address_hedge
  {
    cdr << ros_message->address_hedge;
  }

  // Field name: address_beacon
  {
    cdr << ros_message->address_beacon;
  }

  // Field name: distance_m
  {
    cdr << ros_message->distance_m;
  }

  return true;
}

static bool _BeaconDistance__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BeaconDistance__ros_msg_type * ros_message = static_cast<_BeaconDistance__ros_msg_type *>(untyped_ros_message);
  // Field name: address_hedge
  {
    cdr >> ros_message->address_hedge;
  }

  // Field name: address_beacon
  {
    cdr >> ros_message->address_beacon;
  }

  // Field name: distance_m
  {
    cdr >> ros_message->distance_m;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__msg__BeaconDistance(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BeaconDistance__ros_msg_type * ros_message = static_cast<const _BeaconDistance__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name address_hedge
  {
    size_t item_size = sizeof(ros_message->address_hedge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name address_beacon
  {
    size_t item_size = sizeof(ros_message->address_beacon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name distance_m
  {
    size_t item_size = sizeof(ros_message->distance_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BeaconDistance__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_marvelmind_ros2_msgs__msg__BeaconDistance(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__msg__BeaconDistance(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: address_hedge
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: address_beacon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: distance_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _BeaconDistance__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_marvelmind_ros2_msgs__msg__BeaconDistance(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_BeaconDistance = {
  "marvelmind_ros2_msgs::msg",
  "BeaconDistance",
  _BeaconDistance__cdr_serialize,
  _BeaconDistance__cdr_deserialize,
  _BeaconDistance__get_serialized_size,
  _BeaconDistance__max_serialized_size
};

static rosidl_message_type_support_t _BeaconDistance__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BeaconDistance,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, msg, BeaconDistance)() {
  return &_BeaconDistance__type_support;
}

#if defined(__cplusplus)
}
#endif
