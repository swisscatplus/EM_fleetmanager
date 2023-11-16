// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:srv/MarvelmindAPI.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__struct.hpp"

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

namespace marvelmind_ros2_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_serialize(
  const marvelmind_ros2_msgs::srv::MarvelmindAPI_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: command_id
  rv = ucdr_serialize_int64_t(cdr, ros_message.command_id);
  // Member: request
  {
    size_t size = ros_message.request.size();
    rv = ucdr_serialize_sequence_uint8_t(cdr, &ros_message.request[0], size);
  }

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  marvelmind_ros2_msgs::srv::MarvelmindAPI_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: command_id
  rv = ucdr_deserialize_int64_t(cdr, &ros_message.command_id);
  // Member: request
  {
    uint32_t size;
    const size_t capacity = ros_message.request.capacity();
    ros_message.request.resize(capacity);
    rv = ucdr_deserialize_sequence_uint8_t(cdr, &ros_message.request[0], capacity, &size);
    if (rv) {
      ros_message.request.resize(size);
    }
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::srv::MarvelmindAPI_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: command_id
  {
    const size_t item_size = sizeof(ros_message.command_id);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: request
  {
  // Member is abstractsequence
    size_t sequence_size = ros_message.request.size();
    size_t item_size = sizeof(ros_message.request[0]);
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
    current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_MarvelmindAPI_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: command_id
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: request
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static bool _MarvelmindAPI_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::srv::MarvelmindAPI_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MarvelmindAPI_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::srv::MarvelmindAPI_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MarvelmindAPI_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::srv::MarvelmindAPI_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MarvelmindAPI_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::srv::MarvelmindAPI_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _MarvelmindAPI_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_MarvelmindAPI_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _MarvelmindAPI_Request__callbacks = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI_Request",
  _MarvelmindAPI_Request__cdr_serialize,
  _MarvelmindAPI_Request__cdr_deserialize,
  _MarvelmindAPI_Request__get_serialized_size,
  _MarvelmindAPI_Request__get_serialized_size_with_initial_alignment,
  _MarvelmindAPI_Request__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindAPI_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_MarvelmindAPI_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace marvelmind_ros2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_marvelmind_ros2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<marvelmind_ros2_msgs::srv::MarvelmindAPI_Request>()
{
  return &marvelmind_ros2_msgs::srv::typesupport_microxrcedds_cpp::_MarvelmindAPI_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, srv, MarvelmindAPI_Request)() {
  return &marvelmind_ros2_msgs::srv::typesupport_microxrcedds_cpp::_MarvelmindAPI_Request__handle;
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

namespace marvelmind_ros2_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_serialize(
  const marvelmind_ros2_msgs::srv::MarvelmindAPI_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: success
  rv = ucdr_serialize_bool(cdr, ros_message.success);
  // Member: error_code
  rv = ucdr_serialize_int32_t(cdr, ros_message.error_code);
  // Member: response
  {
    size_t size = ros_message.response.size();
    rv = ucdr_serialize_sequence_uint8_t(cdr, &ros_message.response[0], size);
  }

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  marvelmind_ros2_msgs::srv::MarvelmindAPI_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: success
  rv = ucdr_deserialize_bool(cdr, &ros_message.success);
  // Member: error_code
  rv = ucdr_deserialize_int32_t(cdr, &ros_message.error_code);
  // Member: response
  {
    uint32_t size;
    const size_t capacity = ros_message.response.capacity();
    ros_message.response.resize(capacity);
    rv = ucdr_deserialize_sequence_uint8_t(cdr, &ros_message.response[0], capacity, &size);
    if (rv) {
      ros_message.response.resize(size);
    }
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
get_serialized_size(
  const marvelmind_ros2_msgs::srv::MarvelmindAPI_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: success
  {
    const size_t item_size = sizeof(ros_message.success);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: error_code
  {
    const size_t item_size = sizeof(ros_message.error_code);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: response
  {
  // Member is abstractsequence
    size_t sequence_size = ros_message.response.size();
    size_t item_size = sizeof(ros_message.response[0]);
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
    current_alignment += ucdr_alignment(current_alignment, item_size) + (sequence_size * item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_marvelmind_ros2_msgs
max_serialized_size_MarvelmindAPI_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: success
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: error_code
  current_alignment += ucdr_alignment(current_alignment, sizeof(int32_t)) + sizeof(int32_t);
  // Member: response
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static bool _MarvelmindAPI_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::srv::MarvelmindAPI_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MarvelmindAPI_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<marvelmind_ros2_msgs::srv::MarvelmindAPI_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MarvelmindAPI_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::srv::MarvelmindAPI_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MarvelmindAPI_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const marvelmind_ros2_msgs::srv::MarvelmindAPI_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _MarvelmindAPI_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_MarvelmindAPI_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _MarvelmindAPI_Response__callbacks = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI_Response",
  _MarvelmindAPI_Response__cdr_serialize,
  _MarvelmindAPI_Response__cdr_deserialize,
  _MarvelmindAPI_Response__get_serialized_size,
  _MarvelmindAPI_Response__get_serialized_size_with_initial_alignment,
  _MarvelmindAPI_Response__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindAPI_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_MarvelmindAPI_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace marvelmind_ros2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_marvelmind_ros2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<marvelmind_ros2_msgs::srv::MarvelmindAPI_Response>()
{
  return &marvelmind_ros2_msgs::srv::typesupport_microxrcedds_cpp::_MarvelmindAPI_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, srv, MarvelmindAPI_Response)() {
  return &marvelmind_ros2_msgs::srv::typesupport_microxrcedds_cpp::_MarvelmindAPI_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace marvelmind_ros2_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _MarvelmindAPI__callbacks = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, srv, MarvelmindAPI_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, srv, MarvelmindAPI_Response),
};

static rosidl_service_type_support_t _MarvelmindAPI__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_MarvelmindAPI__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace marvelmind_ros2_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_marvelmind_ros2_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<marvelmind_ros2_msgs::srv::MarvelmindAPI>()
{
  return &marvelmind_ros2_msgs::srv::typesupport_microxrcedds_cpp::_MarvelmindAPI__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, marvelmind_ros2_msgs, srv, MarvelmindAPI)() {
  return &marvelmind_ros2_msgs::srv::typesupport_microxrcedds_cpp::_MarvelmindAPI__handle;
}

#ifdef __cplusplus
}
#endif
