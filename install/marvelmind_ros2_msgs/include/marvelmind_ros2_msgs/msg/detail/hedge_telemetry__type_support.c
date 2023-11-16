// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeTelemetry.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__rosidl_typesupport_introspection_c.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__functions.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  marvelmind_ros2_msgs__msg__HedgeTelemetry__init(message_memory);
}

void HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_fini_function(void * message_memory)
{
  marvelmind_ros2_msgs__msg__HedgeTelemetry__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_member_array[2] = {
  {
    "battery_voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs__msg__HedgeTelemetry, battery_voltage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rssi_dbm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(marvelmind_ros2_msgs__msg__HedgeTelemetry, rssi_dbm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_members = {
  "marvelmind_ros2_msgs__msg",  // message namespace
  "HedgeTelemetry",  // message name
  2,  // number of fields
  sizeof(marvelmind_ros2_msgs__msg__HedgeTelemetry),
  HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_member_array,  // message members
  HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_init_function,  // function to initialize message memory (memory has to be allocated)
  HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_type_support_handle = {
  0,
  &HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_marvelmind_ros2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, marvelmind_ros2_msgs, msg, HedgeTelemetry)() {
  if (!HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_type_support_handle.typesupport_identifier) {
    HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HedgeTelemetry__rosidl_typesupport_introspection_c__HedgeTelemetry_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
