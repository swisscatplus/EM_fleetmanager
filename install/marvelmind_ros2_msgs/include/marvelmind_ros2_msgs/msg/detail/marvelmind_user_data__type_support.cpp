// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindUserData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_user_data__struct.hpp"
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

void MarvelmindUserData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) marvelmind_ros2_msgs::msg::MarvelmindUserData(_init);
}

void MarvelmindUserData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<marvelmind_ros2_msgs::msg::MarvelmindUserData *>(message_memory);
  typed_message->~MarvelmindUserData();
}

size_t size_function__MarvelmindUserData__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarvelmindUserData__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MarvelmindUserData__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void resize_function__MarvelmindUserData__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MarvelmindUserData_message_member_array[2] = {
  {
    "timestamp_ms",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::MarvelmindUserData, timestamp_ms),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs::msg::MarvelmindUserData, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarvelmindUserData__data,  // size() function pointer
    get_const_function__MarvelmindUserData__data,  // get_const(index) function pointer
    get_function__MarvelmindUserData__data,  // get(index) function pointer
    resize_function__MarvelmindUserData__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MarvelmindUserData_message_members = {
  "marvelmind_ros2_msgs::msg",  // message namespace
  "MarvelmindUserData",  // message name
  2,  // number of fields
  sizeof(marvelmind_ros2_msgs::msg::MarvelmindUserData),
  MarvelmindUserData_message_member_array,  // message members
  MarvelmindUserData_init_function,  // function to initialize message memory (memory has to be allocated)
  MarvelmindUserData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MarvelmindUserData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MarvelmindUserData_message_members,
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
get_message_type_support_handle<marvelmind_ros2_msgs::msg::MarvelmindUserData>()
{
  return &::marvelmind_ros2_msgs::msg::rosidl_typesupport_introspection_cpp::MarvelmindUserData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, marvelmind_ros2_msgs, msg, MarvelmindUserData)() {
  return &::marvelmind_ros2_msgs::msg::rosidl_typesupport_introspection_cpp::MarvelmindUserData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
