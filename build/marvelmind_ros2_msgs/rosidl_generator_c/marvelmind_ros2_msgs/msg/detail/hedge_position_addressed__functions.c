// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/HedgePositionAddressed.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_position_addressed__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__HedgePositionAddressed__init(marvelmind_ros2_msgs__msg__HedgePositionAddressed * msg)
{
  if (!msg) {
    return false;
  }
  // address
  // timestamp_ms
  // x_m
  // y_m
  // z_m
  // flags
  return true;
}

void
marvelmind_ros2_msgs__msg__HedgePositionAddressed__fini(marvelmind_ros2_msgs__msg__HedgePositionAddressed * msg)
{
  if (!msg) {
    return;
  }
  // address
  // timestamp_ms
  // x_m
  // y_m
  // z_m
  // flags
}

bool
marvelmind_ros2_msgs__msg__HedgePositionAddressed__are_equal(const marvelmind_ros2_msgs__msg__HedgePositionAddressed * lhs, const marvelmind_ros2_msgs__msg__HedgePositionAddressed * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // address
  if (lhs->address != rhs->address) {
    return false;
  }
  // timestamp_ms
  if (lhs->timestamp_ms != rhs->timestamp_ms) {
    return false;
  }
  // x_m
  if (lhs->x_m != rhs->x_m) {
    return false;
  }
  // y_m
  if (lhs->y_m != rhs->y_m) {
    return false;
  }
  // z_m
  if (lhs->z_m != rhs->z_m) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgePositionAddressed__copy(
  const marvelmind_ros2_msgs__msg__HedgePositionAddressed * input,
  marvelmind_ros2_msgs__msg__HedgePositionAddressed * output)
{
  if (!input || !output) {
    return false;
  }
  // address
  output->address = input->address;
  // timestamp_ms
  output->timestamp_ms = input->timestamp_ms;
  // x_m
  output->x_m = input->x_m;
  // y_m
  output->y_m = input->y_m;
  // z_m
  output->z_m = input->z_m;
  // flags
  output->flags = input->flags;
  return true;
}

marvelmind_ros2_msgs__msg__HedgePositionAddressed *
marvelmind_ros2_msgs__msg__HedgePositionAddressed__create()
{
  marvelmind_ros2_msgs__msg__HedgePositionAddressed * msg = (marvelmind_ros2_msgs__msg__HedgePositionAddressed *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgePositionAddressed));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__HedgePositionAddressed));
  bool success = marvelmind_ros2_msgs__msg__HedgePositionAddressed__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__HedgePositionAddressed__destroy(marvelmind_ros2_msgs__msg__HedgePositionAddressed * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__HedgePositionAddressed__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__init(marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__HedgePositionAddressed * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__HedgePositionAddressed *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__HedgePositionAddressed));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__HedgePositionAddressed__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__HedgePositionAddressed__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__fini(marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__HedgePositionAddressed__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence *
marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * array = (marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__destroy(marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__are_equal(const marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * lhs, const marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__HedgePositionAddressed__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence__copy(
  const marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * input,
  marvelmind_ros2_msgs__msg__HedgePositionAddressed__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__HedgePositionAddressed);
    marvelmind_ros2_msgs__msg__HedgePositionAddressed * data =
      (marvelmind_ros2_msgs__msg__HedgePositionAddressed *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__HedgePositionAddressed__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__HedgePositionAddressed__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__HedgePositionAddressed__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
