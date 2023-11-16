// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuFusion.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__HedgeImuFusion__init(marvelmind_ros2_msgs__msg__HedgeImuFusion * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp_ms
  // x_m
  // y_m
  // z_m
  // qw
  // qx
  // qy
  // qz
  // vx
  // vy
  // vz
  // ax
  // ay
  // az
  return true;
}

void
marvelmind_ros2_msgs__msg__HedgeImuFusion__fini(marvelmind_ros2_msgs__msg__HedgeImuFusion * msg)
{
  if (!msg) {
    return;
  }
  // timestamp_ms
  // x_m
  // y_m
  // z_m
  // qw
  // qx
  // qy
  // qz
  // vx
  // vy
  // vz
  // ax
  // ay
  // az
}

bool
marvelmind_ros2_msgs__msg__HedgeImuFusion__are_equal(const marvelmind_ros2_msgs__msg__HedgeImuFusion * lhs, const marvelmind_ros2_msgs__msg__HedgeImuFusion * rhs)
{
  if (!lhs || !rhs) {
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
  // qw
  if (lhs->qw != rhs->qw) {
    return false;
  }
  // qx
  if (lhs->qx != rhs->qx) {
    return false;
  }
  // qy
  if (lhs->qy != rhs->qy) {
    return false;
  }
  // qz
  if (lhs->qz != rhs->qz) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeImuFusion__copy(
  const marvelmind_ros2_msgs__msg__HedgeImuFusion * input,
  marvelmind_ros2_msgs__msg__HedgeImuFusion * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp_ms
  output->timestamp_ms = input->timestamp_ms;
  // x_m
  output->x_m = input->x_m;
  // y_m
  output->y_m = input->y_m;
  // z_m
  output->z_m = input->z_m;
  // qw
  output->qw = input->qw;
  // qx
  output->qx = input->qx;
  // qy
  output->qy = input->qy;
  // qz
  output->qz = input->qz;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  return true;
}

marvelmind_ros2_msgs__msg__HedgeImuFusion *
marvelmind_ros2_msgs__msg__HedgeImuFusion__create()
{
  marvelmind_ros2_msgs__msg__HedgeImuFusion * msg = (marvelmind_ros2_msgs__msg__HedgeImuFusion *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeImuFusion));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__HedgeImuFusion));
  bool success = marvelmind_ros2_msgs__msg__HedgeImuFusion__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__HedgeImuFusion__destroy(marvelmind_ros2_msgs__msg__HedgeImuFusion * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__HedgeImuFusion__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__init(marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__HedgeImuFusion * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__HedgeImuFusion *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__HedgeImuFusion));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__HedgeImuFusion__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__HedgeImuFusion__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__fini(marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__HedgeImuFusion__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence *
marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * array = (marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__destroy(marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__are_equal(const marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * lhs, const marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__HedgeImuFusion__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence__copy(
  const marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * input,
  marvelmind_ros2_msgs__msg__HedgeImuFusion__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__HedgeImuFusion);
    marvelmind_ros2_msgs__msg__HedgeImuFusion * data =
      (marvelmind_ros2_msgs__msg__HedgeImuFusion *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__HedgeImuFusion__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__HedgeImuFusion__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__HedgeImuFusion__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
