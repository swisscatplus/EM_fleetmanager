// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:action/ComputePathThroughPoses.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/action/detail/compute_path_through_poses__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "nav2_msgs/action/detail/compute_path_through_poses__struct.hpp"

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
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::PoseStamped &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::PoseStamped &);

size_t get_serialized_size(
  const geometry_msgs::msg::PoseStamped &,
  size_t current_alignment);

size_t
max_serialized_size_PoseStamped(
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
  const geometry_msgs::msg::PoseStamped &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::PoseStamped &);

size_t get_serialized_size(
  const geometry_msgs::msg::PoseStamped &,
  size_t current_alignment);

size_t
max_serialized_size_PoseStamped(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_Goal & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: goals
  {
    size_t size = ros_message.goals.size();
    rv = ucdr_serialize_uint32_t(cdr, size);

    size_t i = 0;
    while (i < size && rv) {
      rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
        ros_message.goals[i],
        cdr);
      i++;
    }
  }
  // Member: start
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.start,
    cdr);
  // Member: planner_id
  rv = ucdr_serialize_string(cdr, ros_message.planner_id.c_str());
  // Member: use_start
  rv = ucdr_serialize_bool(cdr, ros_message.use_start);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_Goal & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: goals
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);
    ros_message.goals.resize(size);

    size_t i = 0;
    while (i < size && rv) {
      rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
        cdr,
        ros_message.goals[i]);
      i++;
    }
  }
  // Member: start
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.start);
  // Member: planner_id
  ros_message.planner_id.resize(ros_message.planner_id.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.planner_id[0], ros_message.planner_id.capacity());
  if (rv) {
    ros_message.planner_id.resize(std::strlen(&ros_message.planner_id[0]));
  }
  // Member: use_start
  rv = ucdr_deserialize_bool(cdr, &ros_message.use_start);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_Goal & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goals
  {
  // Member is abstractsequence
    const size_t sequence_size = ros_message.goals.size();
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for (size_t i = 0; i < sequence_size; i++) {
      const size_t item_size = geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
        ros_message.goals[i],
        current_alignment);
      current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
    }
  }
  // Member: start
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.start,
    current_alignment);
  // Member: planner_id
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.planner_id.size() + 1;
  // Member: use_start
  {
    const size_t item_size = sizeof(ros_message.use_start);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_Goal(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goals
  {
    *full_bounded = false;
  }
  // Member: start
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_PoseStamped(
    full_bounded,
    current_alignment);
  // Member: planner_id
  *full_bounded = false;
  // Member: use_start
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_Goal__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Goal *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_Goal__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_Goal *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_Goal__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Goal *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_Goal__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Goal *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_Goal__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_Goal(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_Goal__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_Goal",
  _ComputePathThroughPoses_Goal__cdr_serialize,
  _ComputePathThroughPoses_Goal__cdr_deserialize,
  _ComputePathThroughPoses_Goal__get_serialized_size,
  _ComputePathThroughPoses_Goal__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_Goal__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_Goal__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_Goal__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_Goal>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_Goal__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_Goal)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_Goal__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace nav_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav_msgs::msg::Path &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav_msgs::msg::Path &);

size_t get_serialized_size(
  const nav_msgs::msg::Path &,
  size_t current_alignment);

size_t
max_serialized_size_Path(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace nav_msgs

namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Duration &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  builtin_interfaces::msg::Duration &);

size_t get_serialized_size(
  const builtin_interfaces::msg::Duration &,
  size_t current_alignment);

size_t
max_serialized_size_Duration(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_Result & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: path
  rv = nav_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.path,
    cdr);
  // Member: planning_time
  rv = builtin_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.planning_time,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_Result & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: path
  rv = nav_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.path);
  // Member: planning_time
  rv = builtin_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.planning_time);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_Result & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: path
  current_alignment += nav_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.path,
    current_alignment);
  // Member: planning_time
  current_alignment += builtin_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.planning_time,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_Result(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: path
  current_alignment += nav_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Path(
    full_bounded,
    current_alignment);
  // Member: planning_time
  current_alignment += builtin_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_Duration(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_Result__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Result *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_Result__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_Result *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_Result__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Result *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_Result__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Result *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_Result__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_Result(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_Result__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_Result",
  _ComputePathThroughPoses_Result__cdr_serialize,
  _ComputePathThroughPoses_Result__cdr_deserialize,
  _ComputePathThroughPoses_Result__get_serialized_size,
  _ComputePathThroughPoses_Result__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_Result__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_Result__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_Result__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_Result>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_Result__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_Result)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_Result__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions

namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_Feedback & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_serialize_uint8_t(cdr, ros_message.structure_needs_at_least_one_member);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_Feedback & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message.structure_needs_at_least_one_member);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_Feedback & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  {
    const size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_Feedback(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Feedback *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_Feedback__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_Feedback *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_Feedback__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Feedback *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_Feedback__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_Feedback *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_Feedback__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_Feedback(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_Feedback__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_Feedback",
  _ComputePathThroughPoses_Feedback__cdr_serialize,
  _ComputePathThroughPoses_Feedback__cdr_deserialize,
  _ComputePathThroughPoses_Feedback__get_serialized_size,
  _ComputePathThroughPoses_Feedback__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_Feedback__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_Feedback__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_Feedback>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_Feedback__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_Feedback)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_Feedback__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace unique_identifier_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const unique_identifier_msgs::msg::UUID &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  unique_identifier_msgs::msg::UUID &);

size_t get_serialized_size(
  const unique_identifier_msgs::msg::UUID &,
  size_t current_alignment);

size_t
max_serialized_size_UUID(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace unique_identifier_msgs

namespace nav2_msgs
{
namespace action
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_Goal &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav2_msgs::action::ComputePathThroughPoses_Goal &);

size_t get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_Goal &,
  size_t current_alignment);

size_t
max_serialized_size_ComputePathThroughPoses_Goal(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace action
}  // namespace nav2_msgs


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: goal_id
  rv = unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.goal_id,
    cdr);
  // Member: goal
  rv = nav2_msgs::action::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.goal,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: goal_id
  rv = unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.goal_id);
  // Member: goal
  rv = nav2_msgs::action::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.goal);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment += unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.goal_id,
    current_alignment);
  // Member: goal
  current_alignment += nav2_msgs::action::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.goal,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_SendGoal_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment += unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_UUID(
    full_bounded,
    current_alignment);
  // Member: goal
  current_alignment += nav2_msgs::action::typesupport_microxrcedds_cpp::max_serialized_size_ComputePathThroughPoses_Goal(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_SendGoal_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_SendGoal_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_SendGoal_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_SendGoal_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_SendGoal_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_SendGoal_Request__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_SendGoal_Request",
  _ComputePathThroughPoses_SendGoal_Request__cdr_serialize,
  _ComputePathThroughPoses_SendGoal_Request__cdr_deserialize,
  _ComputePathThroughPoses_SendGoal_Request__get_serialized_size,
  _ComputePathThroughPoses_SendGoal_Request__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_SendGoal_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_SendGoal_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_SendGoal_Request>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_SendGoal_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_SendGoal_Request)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_SendGoal_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  builtin_interfaces::msg::Time &);

size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);

size_t
max_serialized_size_Time(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: accepted
  rv = ucdr_serialize_bool(cdr, ros_message.accepted);
  // Member: stamp
  rv = builtin_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.stamp,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: accepted
  rv = ucdr_deserialize_bool(cdr, &ros_message.accepted);
  // Member: stamp
  rv = builtin_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.stamp);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: accepted
  {
    const size_t item_size = sizeof(ros_message.accepted);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: stamp
  current_alignment += builtin_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.stamp,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_SendGoal_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: accepted
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: stamp
  current_alignment += builtin_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_Time(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_SendGoal_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_SendGoal_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_SendGoal_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_SendGoal_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_SendGoal_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_SendGoal_Response__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_SendGoal_Response",
  _ComputePathThroughPoses_SendGoal_Response__cdr_serialize,
  _ComputePathThroughPoses_SendGoal_Response__cdr_deserialize,
  _ComputePathThroughPoses_SendGoal_Response__get_serialized_size,
  _ComputePathThroughPoses_SendGoal_Response__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_SendGoal_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_SendGoal_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_SendGoal_Response>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_SendGoal_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_SendGoal_Response)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_SendGoal_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _ComputePathThroughPoses_SendGoal__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_SendGoal_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_SendGoal_Response),
};

static rosidl_service_type_support_t _ComputePathThroughPoses_SendGoal__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_SendGoal>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_SendGoal__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_SendGoal)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_SendGoal__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace unique_identifier_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const unique_identifier_msgs::msg::UUID &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  unique_identifier_msgs::msg::UUID &);

size_t get_serialized_size(
  const unique_identifier_msgs::msg::UUID &,
  size_t current_alignment);

size_t
max_serialized_size_UUID(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace unique_identifier_msgs


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_GetResult_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: goal_id
  rv = unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.goal_id,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_GetResult_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: goal_id
  rv = unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.goal_id);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_GetResult_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment += unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.goal_id,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_GetResult_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment += unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_UUID(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_GetResult_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_GetResult_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_GetResult_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_GetResult_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_GetResult_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_GetResult_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_GetResult_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_GetResult_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_GetResult_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_GetResult_Request__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_GetResult_Request",
  _ComputePathThroughPoses_GetResult_Request__cdr_serialize,
  _ComputePathThroughPoses_GetResult_Request__cdr_deserialize,
  _ComputePathThroughPoses_GetResult_Request__get_serialized_size,
  _ComputePathThroughPoses_GetResult_Request__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_GetResult_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_GetResult_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_GetResult_Request>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_GetResult_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_GetResult_Request)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_GetResult_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace nav2_msgs
{
namespace action
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_Result &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav2_msgs::action::ComputePathThroughPoses_Result &);

size_t get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_Result &,
  size_t current_alignment);

size_t
max_serialized_size_ComputePathThroughPoses_Result(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace action
}  // namespace nav2_msgs


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_GetResult_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: status
  rv = ucdr_serialize_int8_t(cdr, ros_message.status);
  // Member: result
  rv = nav2_msgs::action::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.result,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_GetResult_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: status
  rv = ucdr_deserialize_int8_t(cdr, &ros_message.status);
  // Member: result
  rv = nav2_msgs::action::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.result);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_GetResult_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: status
  {
    const size_t item_size = sizeof(ros_message.status);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: result
  current_alignment += nav2_msgs::action::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.result,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_GetResult_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: status
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);
  // Member: result
  current_alignment += nav2_msgs::action::typesupport_microxrcedds_cpp::max_serialized_size_ComputePathThroughPoses_Result(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_GetResult_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_GetResult_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_GetResult_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_GetResult_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_GetResult_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_GetResult_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_GetResult_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_GetResult_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_GetResult_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_GetResult_Response__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_GetResult_Response",
  _ComputePathThroughPoses_GetResult_Response__cdr_serialize,
  _ComputePathThroughPoses_GetResult_Response__cdr_deserialize,
  _ComputePathThroughPoses_GetResult_Response__get_serialized_size,
  _ComputePathThroughPoses_GetResult_Response__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_GetResult_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_GetResult_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_GetResult_Response>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_GetResult_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_GetResult_Response)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_GetResult_Response__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _ComputePathThroughPoses_GetResult__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_GetResult_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_GetResult_Response),
};

static rosidl_service_type_support_t _ComputePathThroughPoses_GetResult__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_GetResult>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_GetResult__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_GetResult)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_GetResult__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace unique_identifier_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const unique_identifier_msgs::msg::UUID &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  unique_identifier_msgs::msg::UUID &);

size_t get_serialized_size(
  const unique_identifier_msgs::msg::UUID &,
  size_t current_alignment);

size_t
max_serialized_size_UUID(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace unique_identifier_msgs

namespace nav2_msgs
{
namespace action
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_Feedback &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  nav2_msgs::action::ComputePathThroughPoses_Feedback &);

size_t get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_Feedback &,
  size_t current_alignment);

size_t
max_serialized_size_ComputePathThroughPoses_Feedback(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace action
}  // namespace nav2_msgs


namespace nav2_msgs
{

namespace action
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: goal_id
  rv = unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.goal_id,
    cdr);
  // Member: feedback
  rv = nav2_msgs::action::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.feedback,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: goal_id
  rv = unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.goal_id);
  // Member: feedback
  rv = nav2_msgs::action::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.feedback);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment += unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.goal_id,
    current_alignment);
  // Member: feedback
  current_alignment += nav2_msgs::action::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.feedback,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_ComputePathThroughPoses_FeedbackMessage(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment += unique_identifier_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_UUID(
    full_bounded,
    current_alignment);
  // Member: feedback
  current_alignment += nav2_msgs::action::typesupport_microxrcedds_cpp::max_serialized_size_ComputePathThroughPoses_Feedback(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ComputePathThroughPoses_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePathThroughPoses_FeedbackMessage__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePathThroughPoses_FeedbackMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePathThroughPoses_FeedbackMessage__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ComputePathThroughPoses_FeedbackMessage__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ComputePathThroughPoses_FeedbackMessage(&full_bounded, 0);
}

static message_type_support_callbacks_t _ComputePathThroughPoses_FeedbackMessage__callbacks = {
  "nav2_msgs::action",
  "ComputePathThroughPoses_FeedbackMessage",
  _ComputePathThroughPoses_FeedbackMessage__cdr_serialize,
  _ComputePathThroughPoses_FeedbackMessage__cdr_deserialize,
  _ComputePathThroughPoses_FeedbackMessage__get_serialized_size,
  _ComputePathThroughPoses_FeedbackMessage__get_serialized_size_with_initial_alignment,
  _ComputePathThroughPoses_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _ComputePathThroughPoses_FeedbackMessage__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ComputePathThroughPoses_FeedbackMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace action

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::action::ComputePathThroughPoses_FeedbackMessage>()
{
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_FeedbackMessage__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, action, ComputePathThroughPoses_FeedbackMessage)() {
  return &nav2_msgs::action::typesupport_microxrcedds_cpp::_ComputePathThroughPoses_FeedbackMessage__handle;
}

#ifdef __cplusplus
}
#endif
