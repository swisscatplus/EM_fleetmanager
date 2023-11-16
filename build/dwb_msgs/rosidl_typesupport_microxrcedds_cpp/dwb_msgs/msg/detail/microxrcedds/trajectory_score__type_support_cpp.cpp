// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from dwb_msgs:msg/TrajectoryScore.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/msg/detail/trajectory_score__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "dwb_msgs/msg/detail/trajectory_score__struct.hpp"

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
namespace dwb_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const dwb_msgs::msg::Trajectory2D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  dwb_msgs::msg::Trajectory2D &);

size_t get_serialized_size(
  const dwb_msgs::msg::Trajectory2D &,
  size_t current_alignment);

size_t
max_serialized_size_Trajectory2D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace dwb_msgs

namespace dwb_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const dwb_msgs::msg::CriticScore &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  dwb_msgs::msg::CriticScore &);

size_t get_serialized_size(
  const dwb_msgs::msg::CriticScore &,
  size_t current_alignment);

size_t
max_serialized_size_CriticScore(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace dwb_msgs


namespace dwb_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_serialize(
  const dwb_msgs::msg::TrajectoryScore & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: traj
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.traj,
    cdr);
  // Member: scores
  {
    size_t size = ros_message.scores.size();
    rv = ucdr_serialize_uint32_t(cdr, size);

    size_t i = 0;
    while (i < size && rv) {
      rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
        ros_message.scores[i],
        cdr);
      i++;
    }
  }
  // Member: total
  rv = ucdr_serialize_float(cdr, ros_message.total);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  dwb_msgs::msg::TrajectoryScore & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: traj
  rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.traj);
  // Member: scores
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);
    ros_message.scores.resize(size);

    size_t i = 0;
    while (i < size && rv) {
      rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
        cdr,
        ros_message.scores[i]);
      i++;
    }
  }
  // Member: total
  rv = ucdr_deserialize_float(cdr, &ros_message.total);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
get_serialized_size(
  const dwb_msgs::msg::TrajectoryScore & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.traj,
    current_alignment);
  // Member: scores
  {
  // Member is abstractsequence
    const size_t sequence_size = ros_message.scores.size();
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for (size_t i = 0; i < sequence_size; i++) {
      const size_t item_size = dwb_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
        ros_message.scores[i],
        current_alignment);
      current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
    }
  }
  // Member: total
  {
    const size_t item_size = sizeof(ros_message.total);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
max_serialized_size_TrajectoryScore(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: traj
  current_alignment += dwb_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Trajectory2D(
    full_bounded,
    current_alignment);
  // Member: scores
  {
    *full_bounded = false;
  }
  // Member: total
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static bool _TrajectoryScore__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const dwb_msgs::msg::TrajectoryScore *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TrajectoryScore__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dwb_msgs::msg::TrajectoryScore *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TrajectoryScore__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dwb_msgs::msg::TrajectoryScore *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TrajectoryScore__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const dwb_msgs::msg::TrajectoryScore *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _TrajectoryScore__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_TrajectoryScore(&full_bounded, 0);
}

static message_type_support_callbacks_t _TrajectoryScore__callbacks = {
  "dwb_msgs::msg",
  "TrajectoryScore",
  _TrajectoryScore__cdr_serialize,
  _TrajectoryScore__cdr_deserialize,
  _TrajectoryScore__get_serialized_size,
  _TrajectoryScore__get_serialized_size_with_initial_alignment,
  _TrajectoryScore__max_serialized_size
};

static rosidl_message_type_support_t _TrajectoryScore__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_TrajectoryScore__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace dwb_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_dwb_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<dwb_msgs::msg::TrajectoryScore>()
{
  return &dwb_msgs::msg::typesupport_microxrcedds_cpp::_TrajectoryScore__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, msg, TrajectoryScore)() {
  return &dwb_msgs::msg::typesupport_microxrcedds_cpp::_TrajectoryScore__handle;
}

#ifdef __cplusplus
}
#endif
