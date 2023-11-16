// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from robot_localization:srv/ToggleFilterProcessing.idl
// generated code does not contain a copyright notice
#include "robot_localization/srv/detail/toggle_filter_processing__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "robot_localization/srv/detail/toggle_filter_processing__struct.hpp"

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

namespace robot_localization
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_serialize(
  const robot_localization::srv::ToggleFilterProcessing_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: on
  rv = ucdr_serialize_bool(cdr, ros_message.on);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_deserialize(
  ucdrBuffer * cdr,
  robot_localization::srv::ToggleFilterProcessing_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: on
  rv = ucdr_deserialize_bool(cdr, &ros_message.on);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
get_serialized_size(
  const robot_localization::srv::ToggleFilterProcessing_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: on
  {
    const size_t item_size = sizeof(ros_message.on);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
max_serialized_size_ToggleFilterProcessing_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: on
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static bool _ToggleFilterProcessing_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToggleFilterProcessing_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ToggleFilterProcessing_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_localization::srv::ToggleFilterProcessing_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ToggleFilterProcessing_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToggleFilterProcessing_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ToggleFilterProcessing_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToggleFilterProcessing_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ToggleFilterProcessing_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ToggleFilterProcessing_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _ToggleFilterProcessing_Request__callbacks = {
  "robot_localization::srv",
  "ToggleFilterProcessing_Request",
  _ToggleFilterProcessing_Request__cdr_serialize,
  _ToggleFilterProcessing_Request__cdr_deserialize,
  _ToggleFilterProcessing_Request__get_serialized_size,
  _ToggleFilterProcessing_Request__get_serialized_size_with_initial_alignment,
  _ToggleFilterProcessing_Request__max_serialized_size
};

static rosidl_message_type_support_t _ToggleFilterProcessing_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ToggleFilterProcessing_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace robot_localization

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_robot_localization
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_localization::srv::ToggleFilterProcessing_Request>()
{
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToggleFilterProcessing_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToggleFilterProcessing_Request)() {
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToggleFilterProcessing_Request__handle;
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

namespace robot_localization
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_serialize(
  const robot_localization::srv::ToggleFilterProcessing_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: status
  rv = ucdr_serialize_bool(cdr, ros_message.status);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_deserialize(
  ucdrBuffer * cdr,
  robot_localization::srv::ToggleFilterProcessing_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: status
  rv = ucdr_deserialize_bool(cdr, &ros_message.status);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
get_serialized_size(
  const robot_localization::srv::ToggleFilterProcessing_Response & ros_message,
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

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
max_serialized_size_ToggleFilterProcessing_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: status
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static bool _ToggleFilterProcessing_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToggleFilterProcessing_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ToggleFilterProcessing_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_localization::srv::ToggleFilterProcessing_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ToggleFilterProcessing_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToggleFilterProcessing_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ToggleFilterProcessing_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToggleFilterProcessing_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ToggleFilterProcessing_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ToggleFilterProcessing_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _ToggleFilterProcessing_Response__callbacks = {
  "robot_localization::srv",
  "ToggleFilterProcessing_Response",
  _ToggleFilterProcessing_Response__cdr_serialize,
  _ToggleFilterProcessing_Response__cdr_deserialize,
  _ToggleFilterProcessing_Response__get_serialized_size,
  _ToggleFilterProcessing_Response__get_serialized_size_with_initial_alignment,
  _ToggleFilterProcessing_Response__max_serialized_size
};

static rosidl_message_type_support_t _ToggleFilterProcessing_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ToggleFilterProcessing_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace robot_localization

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_robot_localization
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_localization::srv::ToggleFilterProcessing_Response>()
{
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToggleFilterProcessing_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToggleFilterProcessing_Response)() {
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToggleFilterProcessing_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace robot_localization
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _ToggleFilterProcessing__callbacks = {
  "robot_localization::srv",
  "ToggleFilterProcessing",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToggleFilterProcessing_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToggleFilterProcessing_Response),
};

static rosidl_service_type_support_t _ToggleFilterProcessing__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ToggleFilterProcessing__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace robot_localization

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_robot_localization
const rosidl_service_type_support_t *
get_service_type_support_handle<robot_localization::srv::ToggleFilterProcessing>()
{
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToggleFilterProcessing__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToggleFilterProcessing)() {
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToggleFilterProcessing__handle;
}

#ifdef __cplusplus
}
#endif
