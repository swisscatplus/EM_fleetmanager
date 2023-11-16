// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/BeaconPositionAddressed.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/beacon_position_addressed__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__init(marvelmind_ros2_msgs__msg__BeaconPositionAddressed * msg)
{
  if (!msg) {
    return false;
  }
  // address
  // x_m
  // y_m
  // z_m
  return true;
}

void
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__fini(marvelmind_ros2_msgs__msg__BeaconPositionAddressed * msg)
{
  if (!msg) {
    return;
  }
  // address
  // x_m
  // y_m
  // z_m
}

bool
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__are_equal(const marvelmind_ros2_msgs__msg__BeaconPositionAddressed * lhs, const marvelmind_ros2_msgs__msg__BeaconPositionAddressed * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // address
  if (lhs->address != rhs->address) {
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
  return true;
}

bool
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__copy(
  const marvelmind_ros2_msgs__msg__BeaconPositionAddressed * input,
  marvelmind_ros2_msgs__msg__BeaconPositionAddressed * output)
{
  if (!input || !output) {
    return false;
  }
  // address
  output->address = input->address;
  // x_m
  output->x_m = input->x_m;
  // y_m
  output->y_m = input->y_m;
  // z_m
  output->z_m = input->z_m;
  return true;
}

marvelmind_ros2_msgs__msg__BeaconPositionAddressed *
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__create()
{
  marvelmind_ros2_msgs__msg__BeaconPositionAddressed * msg = (marvelmind_ros2_msgs__msg__BeaconPositionAddressed *)malloc(sizeof(marvelmind_ros2_msgs__msg__BeaconPositionAddressed));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__BeaconPositionAddressed));
  bool success = marvelmind_ros2_msgs__msg__BeaconPositionAddressed__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__destroy(marvelmind_ros2_msgs__msg__BeaconPositionAddressed * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__BeaconPositionAddressed__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__init(marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__BeaconPositionAddressed * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__BeaconPositionAddressed *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__BeaconPositionAddressed));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__BeaconPositionAddressed__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__BeaconPositionAddressed__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__fini(marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__BeaconPositionAddressed__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence *
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * array = (marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__destroy(marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__are_equal(const marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * lhs, const marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__BeaconPositionAddressed__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence__copy(
  const marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * input,
  marvelmind_ros2_msgs__msg__BeaconPositionAddressed__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__BeaconPositionAddressed);
    marvelmind_ros2_msgs__msg__BeaconPositionAddressed * data =
      (marvelmind_ros2_msgs__msg__BeaconPositionAddressed *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__BeaconPositionAddressed__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__BeaconPositionAddressed__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__BeaconPositionAddressed__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
