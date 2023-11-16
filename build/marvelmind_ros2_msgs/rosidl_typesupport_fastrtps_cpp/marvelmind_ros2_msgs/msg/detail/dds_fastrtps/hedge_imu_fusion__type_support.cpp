// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuFusion.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__rosidl_typesupport_fastrtps_cpp.hpp"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__struct.hpp"

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
  const marvelmind_ros2_msgs::msg::HedgeImuFusion & ros_message,
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
  // Member: qw
  cdr << ros_message.qw;
  // Member: qx
  cdr << ros_message.qx;
  // Member: qy
  cdr << ros_message.qy;
  // Member: qz
  cdr << ros_message.qz;
  // Member: vx
  cdr << ros_message.vx;
  // Member: vy
  cdr << ros_message.vy;
  // Member: vz
  cdr << ros_message.vz;
  // Member: ax
  cdr << ros_message.ax;
  // Member: ay
  cdr << ros_message.ay;
  // Member: az
  cdr << ros_message.az;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  marvelmind_ros2_msgs::msg::HedgeImuFusion & ros_message)
{
  // Member: timestamp_ms
  cdr >> ros_message.timestamp_ms;

  // Member: x_m
  cdr >> ros_message.x_m;

  // Member: y_m
  cdr >> ros_message.y_m;

  // Member: z_m
  cdr >> ros_message.z_m;

  // Member: qw
  cdr >> ros_message.qw;

  // Member: qx
  cdr >> ros_message.qx;

  // Member: qy
  cdr >> ros_message.qy;

  // Member: qz
  cdr >> ros_message.qz;

  // Member: vx
  cdr >> ros_message.vx;

  // Member: vy
  cdr >> ros_message.vy;

  // Member: vz
  cdr >> ros_message.vz;

  // Member: ax
  cdr >> ros_message.ax;

  // Member: ay
  cdr >> ros_message.ay;

  // Member: az
  cdr >> ros_message.az;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::msg::HedgeImuFusion & ros_message,
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
  // Member: qw
  {
    size_t item_size = sizeof(ros_message.qw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: qx
  {
    size_t item_size = sizeof(ros_message.qx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: qy
  {
    size_t item_size = sizeof(ros_message.qy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: qz
  {
    size_t item_size = sizeof(ros_message.qz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vx
  {
    size_t item_size = sizeof(ros_message.vx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vy
  {
    size_t item_size = sizeof(ros_message.vy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vz
  {
    size_t item_size = sizeof(ros_message.vz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ax
  {
    size_t item_size = sizeof(ros_message.ax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ay
  {
    size_t item_size = sizeof(ros_message.ay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: az
  {
    size_t item_size = sizeof(ros_message.az);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_HedgeImuFusion(
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

  // Member: qw
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: qx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: qy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: qz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ax
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ay
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: az
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _HedgeImuFusion__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuFusion *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HedgeImuFusion__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::msg::HedgeImuFusion *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HedgeImuFusion__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::msg::HedgeImuFusion *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HedgeImuFusion__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_HedgeImuFusion(full_bounded, 0);
}

static message_type_support_callbacks_t _HedgeImuFusion__callbacks = {
  "marvelmind_ros2_msgs::msg",
  "HedgeImuFusion",
  _HedgeImuFusion__cdr_serialize,
  _HedgeImuFusion__cdr_deserialize,
  _HedgeImuFusion__get_serialized_size,
  _HedgeImuFusion__max_serialized_size
};

static rosidl_message_type_support_t _HedgeImuFusion__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HedgeImuFusion__callbacks,
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
get_message_type_support_handle<marvelmind_ros2_msgs::msg::HedgeImuFusion>()
{
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_HedgeImuFusion__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, marvelmind_ros2_msgs, msg, HedgeImuFusion)() {
  return &marvelmind_ros2_msgs::msg::typesupport_fastrtps_cpp::_HedgeImuFusion__handle;
}

#ifdef __cplusplus
}
#endif
