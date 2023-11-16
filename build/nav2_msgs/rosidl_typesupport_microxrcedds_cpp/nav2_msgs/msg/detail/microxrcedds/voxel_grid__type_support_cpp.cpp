// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:msg/VoxelGrid.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/voxel_grid__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "nav2_msgs/msg/detail/voxel_grid__struct.hpp"

#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstring>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
#include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  std_msgs::msg::Header &);

size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);

size_t
max_serialized_size_Header(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace std_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Point32 &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Point32 &);

size_t get_serialized_size(
  const geometry_msgs::msg::Point32 &,
  size_t current_alignment);

size_t
max_serialized_size_Point32(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Vector3 &);

size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);

size_t
max_serialized_size_Vector3(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace nav2_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::msg::VoxelGrid & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: data
  {
    size_t size = ros_message.data.size();
    rv = ucdr_serialize_sequence_uint32_t(cdr, &ros_message.data[0], size);
  }
  // Member: origin
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.origin,
    cdr);
  // Member: resolutions
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.resolutions,
    cdr);
  // Member: size_x
  rv = ucdr_serialize_uint32_t(cdr, ros_message.size_x);
  // Member: size_y
  rv = ucdr_serialize_uint32_t(cdr, ros_message.size_y);
  // Member: size_z
  rv = ucdr_serialize_uint32_t(cdr, ros_message.size_z);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::msg::VoxelGrid & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.header);
  // Member: data
  {
    uint32_t size;
    const size_t capacity = ros_message.data.capacity();
    ros_message.data.resize(capacity);
    rv = ucdr_deserialize_sequence_uint32_t(cdr, &ros_message.data[0], capacity, &size);
    if (rv) {
      ros_message.data.resize(size);
    }
  }
  // Member: origin
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.origin);
  // Member: resolutions
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.resolutions);
  // Member: size_x
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message.size_x);
  // Member: size_y
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message.size_y);
  // Member: size_z
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message.size_z);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::msg::VoxelGrid & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.header,
    current_alignment);
  // Member: data
  {
  // Member is abstractsequence
    size_t sequence_size = ros_message.data.size();
    size_t item_size = sizeof(ros_message.data[0]);
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
    current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
  }
  // Member: origin
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.origin,
    current_alignment);
  // Member: resolutions
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.resolutions,
    current_alignment);
  // Member: size_x
  {
    const size_t item_size = sizeof(ros_message.size_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: size_y
  {
    const size_t item_size = sizeof(ros_message.size_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: size_z
  {
    const size_t item_size = sizeof(ros_message.size_z);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_VoxelGrid(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Header(
    full_bounded,
    current_alignment);
  // Member: data
  {
    *full_bounded = false;
  }
  // Member: origin
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Point32(
    full_bounded,
    current_alignment);
  // Member: resolutions
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Vector3(
    full_bounded,
    current_alignment);
  // Member: size_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: size_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: size_z
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);

  return current_alignment - initial_alignment;
}

static bool _VoxelGrid__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::VoxelGrid *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _VoxelGrid__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::msg::VoxelGrid *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _VoxelGrid__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::VoxelGrid *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _VoxelGrid__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::msg::VoxelGrid *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _VoxelGrid__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_VoxelGrid(&full_bounded, 0);
}

static message_type_support_callbacks_t _VoxelGrid__callbacks = {
  "nav2_msgs::msg",
  "VoxelGrid",
  _VoxelGrid__cdr_serialize,
  _VoxelGrid__cdr_deserialize,
  _VoxelGrid__get_serialized_size,
  _VoxelGrid__get_serialized_size_with_initial_alignment,
  _VoxelGrid__max_serialized_size
};

static rosidl_message_type_support_t _VoxelGrid__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_VoxelGrid__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::msg::VoxelGrid>()
{
  return &nav2_msgs::msg::typesupport_microxrcedds_cpp::_VoxelGrid__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, msg, VoxelGrid)() {
  return &nav2_msgs::msg::typesupport_microxrcedds_cpp::_VoxelGrid__handle;
}

#ifdef __cplusplus
}
#endif
