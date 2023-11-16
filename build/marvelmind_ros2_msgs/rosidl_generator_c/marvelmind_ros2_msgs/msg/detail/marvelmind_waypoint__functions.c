// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/MarvelmindWaypoint.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/marvelmind_waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__init(marvelmind_ros2_msgs__msg__MarvelmindWaypoint * msg)
{
  if (!msg) {
    return false;
  }
  // total_items
  // item_index
  // movement_type
  // param1
  // param2
  // param3
  return true;
}

void
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__fini(marvelmind_ros2_msgs__msg__MarvelmindWaypoint * msg)
{
  if (!msg) {
    return;
  }
  // total_items
  // item_index
  // movement_type
  // param1
  // param2
  // param3
}

bool
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__are_equal(const marvelmind_ros2_msgs__msg__MarvelmindWaypoint * lhs, const marvelmind_ros2_msgs__msg__MarvelmindWaypoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // total_items
  if (lhs->total_items != rhs->total_items) {
    return false;
  }
  // item_index
  if (lhs->item_index != rhs->item_index) {
    return false;
  }
  // movement_type
  if (lhs->movement_type != rhs->movement_type) {
    return false;
  }
  // param1
  if (lhs->param1 != rhs->param1) {
    return false;
  }
  // param2
  if (lhs->param2 != rhs->param2) {
    return false;
  }
  // param3
  if (lhs->param3 != rhs->param3) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__copy(
  const marvelmind_ros2_msgs__msg__MarvelmindWaypoint * input,
  marvelmind_ros2_msgs__msg__MarvelmindWaypoint * output)
{
  if (!input || !output) {
    return false;
  }
  // total_items
  output->total_items = input->total_items;
  // item_index
  output->item_index = input->item_index;
  // movement_type
  output->movement_type = input->movement_type;
  // param1
  output->param1 = input->param1;
  // param2
  output->param2 = input->param2;
  // param3
  output->param3 = input->param3;
  return true;
}

marvelmind_ros2_msgs__msg__MarvelmindWaypoint *
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__create()
{
  marvelmind_ros2_msgs__msg__MarvelmindWaypoint * msg = (marvelmind_ros2_msgs__msg__MarvelmindWaypoint *)malloc(sizeof(marvelmind_ros2_msgs__msg__MarvelmindWaypoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__MarvelmindWaypoint));
  bool success = marvelmind_ros2_msgs__msg__MarvelmindWaypoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__destroy(marvelmind_ros2_msgs__msg__MarvelmindWaypoint * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__MarvelmindWaypoint__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__init(marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__MarvelmindWaypoint * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__MarvelmindWaypoint *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__MarvelmindWaypoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__MarvelmindWaypoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__MarvelmindWaypoint__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__fini(marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__MarvelmindWaypoint__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence *
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * array = (marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__destroy(marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__are_equal(const marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * lhs, const marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__MarvelmindWaypoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence__copy(
  const marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * input,
  marvelmind_ros2_msgs__msg__MarvelmindWaypoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__MarvelmindWaypoint);
    marvelmind_ros2_msgs__msg__MarvelmindWaypoint * data =
      (marvelmind_ros2_msgs__msg__MarvelmindWaypoint *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__MarvelmindWaypoint__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__MarvelmindWaypoint__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__MarvelmindWaypoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
