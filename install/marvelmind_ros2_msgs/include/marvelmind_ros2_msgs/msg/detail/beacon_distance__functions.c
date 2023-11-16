// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/BeaconDistance.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/beacon_distance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__BeaconDistance__init(marvelmind_ros2_msgs__msg__BeaconDistance * msg)
{
  if (!msg) {
    return false;
  }
  // address_hedge
  // address_beacon
  // distance_m
  return true;
}

void
marvelmind_ros2_msgs__msg__BeaconDistance__fini(marvelmind_ros2_msgs__msg__BeaconDistance * msg)
{
  if (!msg) {
    return;
  }
  // address_hedge
  // address_beacon
  // distance_m
}

bool
marvelmind_ros2_msgs__msg__BeaconDistance__are_equal(const marvelmind_ros2_msgs__msg__BeaconDistance * lhs, const marvelmind_ros2_msgs__msg__BeaconDistance * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // address_hedge
  if (lhs->address_hedge != rhs->address_hedge) {
    return false;
  }
  // address_beacon
  if (lhs->address_beacon != rhs->address_beacon) {
    return false;
  }
  // distance_m
  if (lhs->distance_m != rhs->distance_m) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__BeaconDistance__copy(
  const marvelmind_ros2_msgs__msg__BeaconDistance * input,
  marvelmind_ros2_msgs__msg__BeaconDistance * output)
{
  if (!input || !output) {
    return false;
  }
  // address_hedge
  output->address_hedge = input->address_hedge;
  // address_beacon
  output->address_beacon = input->address_beacon;
  // distance_m
  output->distance_m = input->distance_m;
  return true;
}

marvelmind_ros2_msgs__msg__BeaconDistance *
marvelmind_ros2_msgs__msg__BeaconDistance__create()
{
  marvelmind_ros2_msgs__msg__BeaconDistance * msg = (marvelmind_ros2_msgs__msg__BeaconDistance *)malloc(sizeof(marvelmind_ros2_msgs__msg__BeaconDistance));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__BeaconDistance));
  bool success = marvelmind_ros2_msgs__msg__BeaconDistance__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__BeaconDistance__destroy(marvelmind_ros2_msgs__msg__BeaconDistance * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__BeaconDistance__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__init(marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__BeaconDistance * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__BeaconDistance *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__BeaconDistance));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__BeaconDistance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__BeaconDistance__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__fini(marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__BeaconDistance__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__BeaconDistance__Sequence *
marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * array = (marvelmind_ros2_msgs__msg__BeaconDistance__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__BeaconDistance__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__destroy(marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__are_equal(const marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * lhs, const marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__BeaconDistance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__BeaconDistance__Sequence__copy(
  const marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * input,
  marvelmind_ros2_msgs__msg__BeaconDistance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__BeaconDistance);
    marvelmind_ros2_msgs__msg__BeaconDistance * data =
      (marvelmind_ros2_msgs__msg__BeaconDistance *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__BeaconDistance__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__BeaconDistance__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__BeaconDistance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
