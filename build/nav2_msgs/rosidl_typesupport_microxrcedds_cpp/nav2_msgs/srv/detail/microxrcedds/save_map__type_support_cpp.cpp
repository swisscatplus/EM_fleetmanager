// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:srv/SaveMap.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/srv/detail/save_map__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "nav2_msgs/srv/detail/save_map__struct.hpp"

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

namespace nav2_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::srv::SaveMap_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: map_topic
  rv = ucdr_serialize_string(cdr, ros_message.map_topic.c_str());
  // Member: map_url
  rv = ucdr_serialize_string(cdr, ros_message.map_url.c_str());
  // Member: image_format
  rv = ucdr_serialize_string(cdr, ros_message.image_format.c_str());
  // Member: map_mode
  rv = ucdr_serialize_string(cdr, ros_message.map_mode.c_str());
  // Member: free_thresh
  rv = ucdr_serialize_float(cdr, ros_message.free_thresh);
  // Member: occupied_thresh
  rv = ucdr_serialize_float(cdr, ros_message.occupied_thresh);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::srv::SaveMap_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: map_topic
  ros_message.map_topic.resize(ros_message.map_topic.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.map_topic[0], ros_message.map_topic.capacity());
  if (rv) {
    ros_message.map_topic.resize(std::strlen(&ros_message.map_topic[0]));
  }
  // Member: map_url
  ros_message.map_url.resize(ros_message.map_url.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.map_url[0], ros_message.map_url.capacity());
  if (rv) {
    ros_message.map_url.resize(std::strlen(&ros_message.map_url[0]));
  }
  // Member: image_format
  ros_message.image_format.resize(ros_message.image_format.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.image_format[0], ros_message.image_format.capacity());
  if (rv) {
    ros_message.image_format.resize(std::strlen(&ros_message.image_format[0]));
  }
  // Member: map_mode
  ros_message.map_mode.resize(ros_message.map_mode.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.map_mode[0], ros_message.map_mode.capacity());
  if (rv) {
    ros_message.map_mode.resize(std::strlen(&ros_message.map_mode[0]));
  }
  // Member: free_thresh
  rv = ucdr_deserialize_float(cdr, &ros_message.free_thresh);
  // Member: occupied_thresh
  rv = ucdr_deserialize_float(cdr, &ros_message.occupied_thresh);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::srv::SaveMap_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map_topic
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.map_topic.size() + 1;
  // Member: map_url
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.map_url.size() + 1;
  // Member: image_format
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.image_format.size() + 1;
  // Member: map_mode
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.map_mode.size() + 1;
  // Member: free_thresh
  {
    const size_t item_size = sizeof(ros_message.free_thresh);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: occupied_thresh
  {
    const size_t item_size = sizeof(ros_message.occupied_thresh);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_SaveMap_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map_topic
  *full_bounded = false;
  // Member: map_url
  *full_bounded = false;
  // Member: image_format
  *full_bounded = false;
  // Member: map_mode
  *full_bounded = false;
  // Member: free_thresh
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: occupied_thresh
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static bool _SaveMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::srv::SaveMap_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SaveMap_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::srv::SaveMap_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SaveMap_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::srv::SaveMap_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SaveMap_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::srv::SaveMap_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _SaveMap_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_SaveMap_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _SaveMap_Request__callbacks = {
  "nav2_msgs::srv",
  "SaveMap_Request",
  _SaveMap_Request__cdr_serialize,
  _SaveMap_Request__cdr_deserialize,
  _SaveMap_Request__get_serialized_size,
  _SaveMap_Request__get_serialized_size_with_initial_alignment,
  _SaveMap_Request__max_serialized_size
};

static rosidl_message_type_support_t _SaveMap_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_SaveMap_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::srv::SaveMap_Request>()
{
  return &nav2_msgs::srv::typesupport_microxrcedds_cpp::_SaveMap_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, srv, SaveMap_Request)() {
  return &nav2_msgs::srv::typesupport_microxrcedds_cpp::_SaveMap_Request__handle;
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

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_serialize(
  const nav2_msgs::srv::SaveMap_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: result
  rv = ucdr_serialize_bool(cdr, ros_message.result);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  nav2_msgs::srv::SaveMap_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: result
  rv = ucdr_deserialize_bool(cdr, &ros_message.result);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
get_serialized_size(
  const nav2_msgs::srv::SaveMap_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: result
  {
    const size_t item_size = sizeof(ros_message.result);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_nav2_msgs
max_serialized_size_SaveMap_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: result
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static bool _SaveMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const nav2_msgs::srv::SaveMap_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SaveMap_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav2_msgs::srv::SaveMap_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SaveMap_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav2_msgs::srv::SaveMap_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SaveMap_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const nav2_msgs::srv::SaveMap_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _SaveMap_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_SaveMap_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _SaveMap_Response__callbacks = {
  "nav2_msgs::srv",
  "SaveMap_Response",
  _SaveMap_Response__cdr_serialize,
  _SaveMap_Response__cdr_deserialize,
  _SaveMap_Response__get_serialized_size,
  _SaveMap_Response__get_serialized_size_with_initial_alignment,
  _SaveMap_Response__max_serialized_size
};

static rosidl_message_type_support_t _SaveMap_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_SaveMap_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::srv::SaveMap_Response>()
{
  return &nav2_msgs::srv::typesupport_microxrcedds_cpp::_SaveMap_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, srv, SaveMap_Response)() {
  return &nav2_msgs::srv::typesupport_microxrcedds_cpp::_SaveMap_Response__handle;
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

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _SaveMap__callbacks = {
  "nav2_msgs::srv",
  "SaveMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, srv, SaveMap_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, srv, SaveMap_Response),
};

static rosidl_service_type_support_t _SaveMap__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_SaveMap__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_nav2_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<nav2_msgs::srv::SaveMap>()
{
  return &nav2_msgs::srv::typesupport_microxrcedds_cpp::_SaveMap__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, nav2_msgs, srv, SaveMap)() {
  return &nav2_msgs::srv::typesupport_microxrcedds_cpp::_SaveMap__handle;
}

#ifdef __cplusplus
}
#endif
