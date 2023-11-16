// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgePosition.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__rosidl_typesupport_fastrtps_cpp.hpp"
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace marvelmind_ros2_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_serialize(
  const marvelmind_ros2_msgs::msg::HedgePosition & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: timestamp_ms
  cdr << ros_message.timestamp_ms;
  // Member: x_m
  cdr << ros_message.x_m;
  // Member: y_m
  cdr << ros_message.y_m;
  // Member: z_m
  cdr << ros_message.z_m;
  // Member: flags
  cdr << ros_message.flags;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  marvelmind_ros2_msgs::msg::HedgePosition & ros_message)
{
  // Member: timestamp_ms
  cdr >> ros_message.timestamp_ms;

  // Member: x_m
  cdr >> ros_message.x_m;

  // Member: y_m
  cdr >> ros_message.y_m;

  // Member: z_m
  cdr >> ros_message.z_m;

  // Member: flags
  cdr >> ros_message.flags;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::msg::HedgePosition & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: timestamp_ms
  {
    size_t item_size = sizeof(ros_message.timestamp_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: x_m
  {
    size_t item_size = sizeof(ros_message.x_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y_m
  {
    size_t item_size = sizeof(ros_message.y_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: z_m
  {
    size_t item_size = sizeof(ros_message.z_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flags
  {
    size_t item_size = sizeof(ros_message.flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_HedgePosition(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: timestamp_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: x_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: y_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: z_m
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: flags
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _HedgePosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgePosition *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HedgePosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::msg::HedgePosition *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HedgePosition__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgePosition *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HedgePosition__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_HedgePosition(full_bounded, 0);
}

static message_type_support_callbacks_t _HedgePosition__callbacks = {
  "marvelmind_ros2_msgs::msg",
  "HedgePosition",
  _HedgePosition__cdr_serialize,
  _HedgePosition__cdr_deserialize,
  _HedgePosition__get_serialized_size,
  _HedgePosition__max_serialized_size
};

static rosidl_message_type_support_t _HedgePosition__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HedgePosition__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace marvelmind_ros2_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_marvelmind_ros2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<marvelmind_ros2_msgs::msg::HedgePosition>()
{
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_HedgePosition__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, marvelmind_ros2_msgs, msg, HedgePosition)() {
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_HedgePosition__handle;
}

#ifdef __cplusplus
}
#endif
