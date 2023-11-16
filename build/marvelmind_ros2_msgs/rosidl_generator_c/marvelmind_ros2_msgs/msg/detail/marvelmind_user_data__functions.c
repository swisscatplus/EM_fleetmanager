// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindUserData.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_user_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
marvelmind_ros2_msgs__msg__MarvelmindUserData__init(marvelmind_ros2_msgs__msg__MarvelmindUserData * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp_ms
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    marvelmind_ros2_msgs__msg__MarvelmindUserData__fini(msg);
    return false;
  }
  return true;
}

void
marvelmind_ros2_msgs__msg__MarvelmindUserData__fini(marvelmind_ros2_msgs__msg__MarvelmindUserData * msg)
{
  if (!msg) {
    return;
  }
  // timestamp_ms
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
marvelmind_ros2_msgs__msg__MarvelmindUserData__are_equal(const marvelmind_ros2_msgs__msg__MarvelmindUserData * lhs, const marvelmind_ros2_msgs__msg__MarvelmindUserData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp_ms
  if (lhs->timestamp_ms != rhs->timestamp_ms) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__MarvelmindUserData__copy(
  const marvelmind_ros2_msgs__msg__MarvelmindUserData * input,
  marvelmind_ros2_msgs__msg__MarvelmindUserData * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp_ms
  output->timestamp_ms = input->timestamp_ms;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

marvelmind_ros2_msgs__msg__MarvelmindUserData *
marvelmind_ros2_msgs__msg__MarvelmindUserData__create()
{
  marvelmind_ros2_msgs__msg__MarvelmindUserData * msg = (marvelmind_ros2_msgs__msg__MarvelmindUserData *)malloc(sizeof(marvelmind_ros2_msgs__msg__MarvelmindUserData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__MarvelmindUserData));
  bool success = marvelmind_ros2_msgs__msg__MarvelmindUserData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__MarvelmindUserData__destroy(marvelmind_ros2_msgs__msg__MarvelmindUserData * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__MarvelmindUserData__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__init(marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__MarvelmindUserData * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__MarvelmindUserData *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__MarvelmindUserData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__MarvelmindUserData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__MarvelmindUserData__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__fini(marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__MarvelmindUserData__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence *
marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * array = (marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__destroy(marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__are_equal(const marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * lhs, const marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__MarvelmindUserData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence__copy(
  const marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * input,
  marvelmind_ros2_msgs__msg__MarvelmindUserData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__MarvelmindUserData);
    marvelmind_ros2_msgs__msg__MarvelmindUserData * data =
      (marvelmind_ros2_msgs__msg__MarvelmindUserData *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__MarvelmindUserData__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__MarvelmindUserData__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__MarvelmindUserData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
