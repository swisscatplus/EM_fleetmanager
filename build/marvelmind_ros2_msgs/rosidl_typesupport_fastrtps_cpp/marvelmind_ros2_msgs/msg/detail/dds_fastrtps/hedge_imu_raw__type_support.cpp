// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__rosidl_typesupport_fastrtps_cpp.hpp"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__struct.hpp"

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
  const marvelmind_ros2_msgs::msg::HedgeImuRaw & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: timestamp_ms
  cdr << ros_message.timestamp_ms;
  // Member: acc_x
  cdr << ros_message.acc_x;
  // Member: acc_y
  cdr << ros_message.acc_y;
  // Member: acc_z
  cdr << ros_message.acc_z;
  // Member: gyro_x
  cdr << ros_message.gyro_x;
  // Member: gyro_y
  cdr << ros_message.gyro_y;
  // Member: gyro_z
  cdr << ros_message.gyro_z;
  // Member: compass_x
  cdr << ros_message.compass_x;
  // Member: compass_y
  cdr << ros_message.compass_y;
  // Member: compass_z
  cdr << ros_message.compass_z;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  marvelmind_ros2_msgs::msg::HedgeImuRaw & ros_message)
{
  // Member: timestamp_ms
  cdr >> ros_message.timestamp_ms;

  // Member: acc_x
  cdr >> ros_message.acc_x;

  // Member: acc_y
  cdr >> ros_message.acc_y;

  // Member: acc_z
  cdr >> ros_message.acc_z;

  // Member: gyro_x
  cdr >> ros_message.gyro_x;

  // Member: gyro_y
  cdr >> ros_message.gyro_y;

  // Member: gyro_z
  cdr >> ros_message.gyro_z;

  // Member: compass_x
  cdr >> ros_message.compass_x;

  // Member: compass_y
  cdr >> ros_message.compass_y;

  // Member: compass_z
  cdr >> ros_message.compass_z;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::msg::HedgeImuRaw & ros_message,
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
  // Member: acc_x
  {
    size_t item_size = sizeof(ros_message.acc_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_y
  {
    size_t item_size = sizeof(ros_message.acc_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_z
  {
    size_t item_size = sizeof(ros_message.acc_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_x
  {
    size_t item_size = sizeof(ros_message.gyro_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_y
  {
    size_t item_size = sizeof(ros_message.gyro_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_z
  {
    size_t item_size = sizeof(ros_message.gyro_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: compass_x
  {
    size_t item_size = sizeof(ros_message.compass_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: compass_y
  {
    size_t item_size = sizeof(ros_message.compass_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: compass_z
  {
    size_t item_size = sizeof(ros_message.compass_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_HedgeImuRaw(
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

  // Member: acc_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: acc_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: acc_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gyro_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gyro_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gyro_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: compass_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: compass_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: compass_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _HedgeImuRaw__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HedgeImuRaw__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HedgeImuRaw__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuRaw *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HedgeImuRaw__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_HedgeImuRaw(full_bounded, 0);
}

static message_type_support_callbacks_t _HedgeImuRaw__callbacks = {
  "marvelmind_ros2_msgs::msg",
  "HedgeImuRaw",
  _HedgeImuRaw__cdr_serialize,
  _HedgeImuRaw__cdr_deserialize,
  _HedgeImuRaw__get_serialized_size,
  _HedgeImuRaw__max_serialized_size
};

static rosidl_message_type_support_t _HedgeImuRaw__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HedgeImuRaw__callbacks,
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
get_message_type_support_handle<marvelmind_ros2_msgs::msg::HedgeImuRaw>()
{
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_HedgeImuRaw__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, marvelmind_ros2_msgs, msg, HedgeImuRaw)() {
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_HedgeImuRaw__handle;
}

#ifdef __cplusplus
}
#endif
