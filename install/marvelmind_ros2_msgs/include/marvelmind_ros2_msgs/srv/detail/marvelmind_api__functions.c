// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:srv/MarvelmindAPI.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/srv/detail/marvelmind_api__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `request`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__init(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command_id
  // request
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->request, 0)) {
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__fini(msg);
    return false;
  }
  return true;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__fini(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * msg)
{
  if (!msg) {
    return;
  }
  // command_id
  // request
  rosidl_runtime_c__uint8__Sequence__fini(&msg->request);
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__are_equal(const marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * lhs, const marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command_id
  if (lhs->command_id != rhs->command_id) {
    return false;
  }
  // request
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__copy(
  const marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * input,
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command_id
  output->command_id = input->command_id;
  // request
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  return true;
}

marvelmind_ros2_msgs__srv__MarvelmindAPI_Request *
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__create()
{
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * msg = (marvelmind_ros2_msgs__srv__MarvelmindAPI_Request *)malloc(sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request));
  bool success = marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__destroy(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__init(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__srv__MarvelmindAPI_Request *)calloc(size, sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__fini(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence *
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * array = (marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__destroy(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__are_equal(const marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * lhs, const marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence__copy(
  const marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * input,
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Request);
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Request * data =
      (marvelmind_ros2_msgs__srv__MarvelmindAPI_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!marvelmind_ros2_msgs__srv__MarvelmindAPI_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__init(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_code
  // response
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->response, 0)) {
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__fini(msg);
    return false;
  }
  return true;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__fini(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_code
  // response
  rosidl_runtime_c__uint8__Sequence__fini(&msg->response);
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__are_equal(const marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * lhs, const marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__copy(
  const marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * input,
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_code
  output->error_code = input->error_code;
  // response
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

marvelmind_ros2_msgs__srv__MarvelmindAPI_Response *
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__create()
{
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * msg = (marvelmind_ros2_msgs__srv__MarvelmindAPI_Response *)malloc(sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response));
  bool success = marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__destroy(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__init(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__srv__MarvelmindAPI_Response *)calloc(size, sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__fini(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence *
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * array = (marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__destroy(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__are_equal(const marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * lhs, const marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence__copy(
  const marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * input,
  marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__srv__MarvelmindAPI_Response);
    marvelmind_ros2_msgs__srv__MarvelmindAPI_Response * data =
      (marvelmind_ros2_msgs__srv__MarvelmindAPI_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!marvelmind_ros2_msgs__srv__MarvelmindAPI_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
