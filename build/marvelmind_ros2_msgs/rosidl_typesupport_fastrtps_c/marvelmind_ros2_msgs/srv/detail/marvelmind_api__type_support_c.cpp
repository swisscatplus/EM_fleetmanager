// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from marvelmind_ros2_msgs:srv/MarvelmindAPI.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__struct.h"
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // request
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // request

// forward declare type support functions


using _MarvelmindAPI_Request__ros_msg_type = marvelmind_ros2_msgs__srv__MarvelmindAPI_Request;

static bool _MarvelmindAPI_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MarvelmindAPI_Request__ros_msg_type * ros_message = static_cast<const _MarvelmindAPI_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: command_id
  {
    cdr << ros_message->command_id;
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MarvelmindAPI_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MarvelmindAPI_Request__ros_msg_type * ros_message = static_cast<_MarvelmindAPI_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: command_id
  {
    cdr >> ros_message->command_id;
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->request.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->request);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MarvelmindAPI_Request__ros_msg_type * ros_message = static_cast<const _MarvelmindAPI_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name command_id
  {
    size_t item_size = sizeof(ros_message->command_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MarvelmindAPI_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: command_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: request
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _MarvelmindAPI_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MarvelmindAPI_Request = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI_Request",
  _MarvelmindAPI_Request__cdr_serialize,
  _MarvelmindAPI_Request__cdr_deserialize,
  _MarvelmindAPI_Request__get_serialized_size,
  _MarvelmindAPI_Request__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindAPI_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MarvelmindAPI_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Request)() {
  return &_MarvelmindAPI_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__struct.h"
// already included above
// #include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // response
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // response

// forward declare type support functions


using _MarvelmindAPI_Response__ros_msg_type = marvelmind_ros2_msgs__srv__MarvelmindAPI_Response;

static bool _MarvelmindAPI_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MarvelmindAPI_Response__ros_msg_type * ros_message = static_cast<const _MarvelmindAPI_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: error_code
  {
    cdr << ros_message->error_code;
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MarvelmindAPI_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MarvelmindAPI_Response__ros_msg_type * ros_message = static_cast<_MarvelmindAPI_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: error_code
  {
    cdr >> ros_message->error_code;
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->response.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->response);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MarvelmindAPI_Response__ros_msg_type * ros_message = static_cast<const _MarvelmindAPI_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name error_code
  {
    size_t item_size = sizeof(ros_message->error_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MarvelmindAPI_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_marvelmind_ros2_msgs
size_t max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: error_code
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: response
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _MarvelmindAPI_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_marvelmind_ros2_msgs__srv__MarvelmindAPI_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MarvelmindAPI_Response = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI_Response",
  _MarvelmindAPI_Response__cdr_serialize,
  _MarvelmindAPI_Response__cdr_deserialize,
  _MarvelmindAPI_Response__get_serialized_size,
  _MarvelmindAPI_Response__max_serialized_size
};

static rosidl_message_type_support_t _MarvelmindAPI_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MarvelmindAPI_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Response)() {
  return &_MarvelmindAPI_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "marvelmind_ros2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "marvelmind_ros2_msgs/srv/marvelmind_api.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MarvelmindAPI__callbacks = {
  "marvelmind_ros2_msgs::srv",
  "MarvelmindAPI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, srv, MarvelmindAPI_Response)(),
};

static rosidl_service_type_support_t MarvelmindAPI__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MarvelmindAPI__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, marvelmind_ros2_msgs, srv, MarvelmindAPI)() {
  return &MarvelmindAPI__handle;
}

#if defined(__cplusplus)
}
#endif
