// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeQuality.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__HedgeQuality__init(marvelmind_ros2_msgs__msg__HedgeQuality * msg)
{
  if (!msg) {
    return false;
  }
  // address
  // quality_percents
  return true;
}

void
marvelmind_ros2_msgs__msg__HedgeQuality__fini(marvelmind_ros2_msgs__msg__HedgeQuality * msg)
{
  if (!msg) {
    return;
  }
  // address
  // quality_percents
}

bool
marvelmind_ros2_msgs__msg__HedgeQuality__are_equal(const marvelmind_ros2_msgs__msg__HedgeQuality * lhs, const marvelmind_ros2_msgs__msg__HedgeQuality * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // address
  if (lhs->address != rhs->address) {
    return false;
  }
  // quality_percents
  if (lhs->quality_percents != rhs->quality_percents) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeQuality__copy(
  const marvelmind_ros2_msgs__msg__HedgeQuality * input,
  marvelmind_ros2_msgs__msg__HedgeQuality * output)
{
  if (!input || !output) {
    return false;
  }
  // address
  output->address = input->address;
  // quality_percents
  output->quality_percents = input->quality_percents;
  return true;
}

marvelmind_ros2_msgs__msg__HedgeQuality *
marvelmind_ros2_msgs__msg__HedgeQuality__create()
{
  marvelmind_ros2_msgs__msg__HedgeQuality * msg = (marvelmind_ros2_msgs__msg__HedgeQuality *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeQuality));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__HedgeQuality));
  bool success = marvelmind_ros2_msgs__msg__HedgeQuality__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__HedgeQuality__destroy(marvelmind_ros2_msgs__msg__HedgeQuality * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__HedgeQuality__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__init(marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__HedgeQuality * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__HedgeQuality *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__HedgeQuality));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__HedgeQuality__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__HedgeQuality__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__fini(marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__HedgeQuality__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__HedgeQuality__Sequence *
marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * array = (marvelmind_ros2_msgs__msg__HedgeQuality__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeQuality__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__destroy(marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__are_equal(const marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * lhs, const marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__HedgeQuality__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeQuality__Sequence__copy(
  const marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * input,
  marvelmind_ros2_msgs__msg__HedgeQuality__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__HedgeQuality);
    marvelmind_ros2_msgs__msg__HedgeQuality * data =
      (marvelmind_ros2_msgs__msg__HedgeQuality *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__HedgeQuality__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__HedgeQuality__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__HedgeQuality__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
