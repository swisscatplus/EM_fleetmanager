// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from marvelmind_ros2_msgs:msg/BeaconDistance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__rosidl_typesupport_introspection_c.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__functions.h"
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  marvelmind_ros2_msgs__msg__BeaconDistance__init(message_memory);
}

void BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_fini_function(void * message_memory)
{
  marvelmind_ros2_msgs__msg__BeaconDistance__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_member_array[3] = {
  {
    "address_hedge",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs__msg__BeaconDistance, address_hedge),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "address_beacon",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs__msg__BeaconDistance, address_beacon),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs__msg__BeaconDistance, distance_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_members = {
  "marvelmind_ros2_msgs__msg",  // message namespace
  "BeaconDistance",  // message name
  3,  // number of fields
  sizeof(marvelmind_ros2_msgs__msg__BeaconDistance),
  BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_member_array,  // message members
  BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_init_function,  // function to initialize message memory (memory has to be allocated)
  BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_type_support_handle = {
  0,
  &BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_marvelmind_ros2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, marvelmind_ros2_msgs, msg, BeaconDistance)() {
  if (!BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_type_support_handle.typesupport_identifier) {
    BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &BeaconDistance__rosidl_typesupport_introspection_c__BeaconDistance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
