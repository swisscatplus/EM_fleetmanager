// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from robot_localization:srv/ToLL.idl
// generated code does not contain a copyright notice
#include "robot_localization/srv/detail/to_ll__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "robot_localization/srv/detail/to_ll__struct.hpp"

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
  const geometry_msgs::msg::Point &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Point &);

size_t get_serialized_size(
  const geometry_msgs::msg::Point &,
  size_t current_alignment);

size_t
max_serialized_size_Point(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace robot_localization
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_serialize(
  const robot_localization::srv::ToLL_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: map_point
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.map_point,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_deserialize(
  ucdrBuffer * cdr,
  robot_localization::srv::ToLL_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: map_point
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.map_point);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
get_serialized_size(
  const robot_localization::srv::ToLL_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map_point
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.map_point,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
max_serialized_size_ToLL_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map_point
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Point(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ToLL_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToLL_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ToLL_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_localization::srv::ToLL_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ToLL_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToLL_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ToLL_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToLL_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ToLL_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ToLL_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _ToLL_Request__callbacks = {
  "robot_localization::srv",
  "ToLL_Request",
  _ToLL_Request__cdr_serialize,
  _ToLL_Request__cdr_deserialize,
  _ToLL_Request__get_serialized_size,
  _ToLL_Request__get_serialized_size_with_initial_alignment,
  _ToLL_Request__max_serialized_size
};

static rosidl_message_type_support_t _ToLL_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ToLL_Request__callbacks,
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
get_message_type_support_handle<robot_localization::srv::ToLL_Request>()
{
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToLL_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToLL_Request)() {
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToLL_Request__handle;
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
namespace geographic_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geographic_msgs::msg::GeoPoint &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geographic_msgs::msg::GeoPoint &);

size_t get_serialized_size(
  const geographic_msgs::msg::GeoPoint &,
  size_t current_alignment);

size_t
max_serialized_size_GeoPoint(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geographic_msgs


namespace robot_localization
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_serialize(
  const robot_localization::srv::ToLL_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: ll_point
  rv = geographic_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.ll_point,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
cdr_deserialize(
  ucdrBuffer * cdr,
  robot_localization::srv::ToLL_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: ll_point
  rv = geographic_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.ll_point);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
get_serialized_size(
  const robot_localization::srv::ToLL_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: ll_point
  current_alignment += geographic_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.ll_point,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_robot_localization
max_serialized_size_ToLL_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: ll_point
  current_alignment += geographic_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_GeoPoint(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ToLL_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToLL_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ToLL_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_localization::srv::ToLL_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ToLL_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToLL_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ToLL_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const robot_localization::srv::ToLL_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ToLL_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ToLL_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _ToLL_Response__callbacks = {
  "robot_localization::srv",
  "ToLL_Response",
  _ToLL_Response__cdr_serialize,
  _ToLL_Response__cdr_deserialize,
  _ToLL_Response__get_serialized_size,
  _ToLL_Response__get_serialized_size_with_initial_alignment,
  _ToLL_Response__max_serialized_size
};

static rosidl_message_type_support_t _ToLL_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ToLL_Response__callbacks,
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
get_message_type_support_handle<robot_localization::srv::ToLL_Response>()
{
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToLL_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToLL_Response)() {
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToLL_Response__handle;
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

static service_type_support_callbacks_t _ToLL__callbacks = {
  "robot_localization::srv",
  "ToLL",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToLL_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToLL_Response),
};

static rosidl_service_type_support_t _ToLL__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ToLL__callbacks,
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
get_service_type_support_handle<robot_localization::srv::ToLL>()
{
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToLL__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, robot_localization, srv, ToLL)() {
  return &robot_localization::srv::typesupport_microxrcedds_cpp::_ToLL__handle;
}

#ifdef __cplusplus
}
#endif
