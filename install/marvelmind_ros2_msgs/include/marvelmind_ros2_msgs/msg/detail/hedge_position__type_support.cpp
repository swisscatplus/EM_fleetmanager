// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/HedgePosition.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_position__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace marvelmind_ros2_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HedgePosition_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) marvelmind_ros2_msgs::msg::HedgePosition(_init);
}

void HedgePosition_fini_function(void * message_memory)
{
  auto typed_message = static_cast<marvelmind_ros2_msgs::msg::HedgePosition *>(message_memory);
  typed_message->~HedgePosition();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HedgePosition_message_member_array[5] = {
  {
    "timestamp_ms",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::HedgePosition, timestamp_ms),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "x_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::HedgePosition, x_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::HedgePosition, y_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::HedgePosition, z_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "flags",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::HedgePosition, flags),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HedgePosition_message_members = {
  "marvelmind_ros2_msgs::msg",  // message namespace
  "HedgePosition",  // message name
  5,  // number of fields
  sizeof(marvelmind_ros2_msgs::msg::HedgePosition),
  HedgePosition_message_member_array,  // message members
  HedgePosition_init_function,  // function to initialize message memory (memory has to be allocated)
  HedgePosition_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HedgePosition_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HedgePosition_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace marvelmind_ros2_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<marvelmind_ros2_msgs::msg::HedgePosition>()
{
  return &::marvelmind_ros2_msgs::msg::rosidl_typesupport_introspection_cpp::HedgePosition_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, marvelmind_ros2_msgs, msg, HedgePosition)() {
  return &::marvelmind_ros2_msgs::msg::rosidl_typesupport_introspection_cpp::HedgePosition_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
