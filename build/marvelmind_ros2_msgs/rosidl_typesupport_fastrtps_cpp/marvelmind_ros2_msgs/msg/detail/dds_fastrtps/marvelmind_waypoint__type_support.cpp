// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindWaypoint.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__rosidl_typesupport_fastrtps_cpp.hpp"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__struct.hpp"

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
  const marvelmind_ros2_msgs::msg::MarvelmindWaypoint & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: total_items
  cdr << ros_message.total_items;
  // Member: item_index
  cdr << ros_message.item_index;
  // Member: movement_type
  cdr << ros_message.movement_type;
  // Member: param1
  cdr << ros_message.param1;
  // Member: param2
  cdr << ros_message.param2;
  // Member: param3
  cdr << ros_message.param3;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  marvelmind_ros2_msgs::msg::MarvelmindWaypoint & ros_message)
{
  // Member: total_items
  cdr >> ros_message.total_items;

  // Member: item_index
  cdr >> ros_message.item_index;

  // Member: movement_type
  cdr >> ros_message.movement_type;

  // Member: param1
  cdr >> ros_message.param1;

  // Member: param2
  cdr >> ros_message.param2;

  // Member: param3
  cdr >> ros_message.param3;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::msg::MarvelmindWaypoint & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: total_items
  {
    size_t item_size = sizeof(ros_message.total_items);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: item_index
  {
    size_t item_size = sizeof(ros_message.item_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: movement_type
  {
    size_t item_size = sizeof(ros_message.movement_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: param1
  {
    size_t item_size = sizeof(ros_message.param1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: param2
  {
    size_t item_size = sizeof(ros_message.param2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: param3
  {
    size_t item_size = sizeof(ros_message.param3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_MarvelmindWaypoint(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: total_items
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: item_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: movement_type
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: param1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: param2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: param3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MarvelmindWaypoint__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MarvelmindWaypoint__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MarvelmindWaypoint__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::MarvelmindWaypoint *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MarvelmindWaypoint__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MarvelmindWaypoint(full_bounded, 0);
}

static message_type_support_callbacks_t _MarvelmindWaypoint__callbacks = {
  "marvelmind_ros2_msgs::msg",
  "MarvelmindWaypoint",
  _MarvelmindWaypoint__cdr_serialize,
  _MarvelmindWaypoint__cdr_deserialize,
  _MarvelmindWaypoint__get_serialized_size,
  _MarvelmindWaypoint__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindWaypoint__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MarvelmindWaypoint__callbacks,
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
get_message_type_support_handle<marvelmind_ros2_msgs::msg::MarvelmindWaypoint>()
{
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_MarvelmindWaypoint__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, marvelmind_ros2_msgs, msg, MarvelmindWaypoint)() {
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_MarvelmindWaypoint__handle;
}

#ifdef __cplusplus
}
#endif
