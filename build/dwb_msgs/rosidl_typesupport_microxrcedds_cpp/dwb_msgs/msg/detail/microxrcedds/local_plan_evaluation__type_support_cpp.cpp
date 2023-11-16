// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from dwb_msgs:msg/LocalPlanEvaluation.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/msg/detail/local_plan_evaluation__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "dwb_msgs/msg/detail/local_plan_evaluation__struct.hpp"

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

namespace dwb_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const dwb_msgs::msg::TrajectoryScore &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  dwb_msgs::msg::TrajectoryScore &);

size_t get_serialized_size(
  const dwb_msgs::msg::TrajectoryScore &,
  size_t current_alignment);

size_t
max_serialized_size_TrajectoryScore(
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
  const dwb_msgs::msg::LocalPlanEvaluation & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: twists
  {
    size_t size = ros_message.twists.size();
    rv = ucdr_serialize_uint32_t(cdr, size);

    size_t i = 0;
    while (i < size && rv) {
      rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
        ros_message.twists[i],
        cdr);
      i++;
    }
  }
  // Member: best_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message.best_index);
  // Member: worst_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message.worst_index);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  dwb_msgs::msg::LocalPlanEvaluation & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.header);
  // Member: twists
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);
    ros_message.twists.resize(size);

    size_t i = 0;
    while (i < size && rv) {
      rv = dwb_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
        cdr,
        ros_message.twists[i]);
      i++;
    }
  }
  // Member: best_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message.best_index);
  // Member: worst_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message.worst_index);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
get_serialized_size(
  const dwb_msgs::msg::LocalPlanEvaluation & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.header,
    current_alignment);
  // Member: twists
  {
  // Member is abstractsequence
    const size_t sequence_size = ros_message.twists.size();
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for (size_t i = 0; i < sequence_size; i++) {
      const size_t item_size = dwb_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
        ros_message.twists[i],
        current_alignment);
      current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
    }
  }
  // Member: best_index
  {
    const size_t item_size = sizeof(ros_message.best_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: worst_index
  {
    const size_t item_size = sizeof(ros_message.worst_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_dwb_msgs
max_serialized_size_LocalPlanEvaluation(
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
  // Member: twists
  {
    *full_bounded = false;
  }
  // Member: best_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);
  // Member: worst_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);

  return current_alignment - initial_alignment;
}

static bool _LocalPlanEvaluation__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const dwb_msgs::msg::LocalPlanEvaluation *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LocalPlanEvaluation__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dwb_msgs::msg::LocalPlanEvaluation *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LocalPlanEvaluation__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dwb_msgs::msg::LocalPlanEvaluation *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LocalPlanEvaluation__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const dwb_msgs::msg::LocalPlanEvaluation *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _LocalPlanEvaluation__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_LocalPlanEvaluation(&full_bounded, 0);
}

static message_type_support_callbacks_t _LocalPlanEvaluation__callbacks = {
  "dwb_msgs::msg",
  "LocalPlanEvaluation",
  _LocalPlanEvaluation__cdr_serialize,
  _LocalPlanEvaluation__cdr_deserialize,
  _LocalPlanEvaluation__get_serialized_size,
  _LocalPlanEvaluation__get_serialized_size_with_initial_alignment,
  _LocalPlanEvaluation__max_serialized_size
};

static rosidl_message_type_support_t _LocalPlanEvaluation__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_LocalPlanEvaluation__callbacks,
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
get_message_type_support_handle<dwb_msgs::msg::LocalPlanEvaluation>()
{
  return &dwb_msgs::msg::typesupport_microxrcedds_cpp::_LocalPlanEvaluation__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, dwb_msgs, msg, LocalPlanEvaluation)() {
  return &dwb_msgs::msg::typesupport_microxrcedds_cpp::_LocalPlanEvaluation__handle;
}

#ifdef __cplusplus
}
#endif
