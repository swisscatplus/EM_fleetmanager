// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__HedgeImuRaw__init(marvelmind_ros2_msgs__msg__HedgeImuRaw * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp_ms
  // acc_x
  // acc_y
  // acc_z
  // gyro_x
  // gyro_y
  // gyro_z
  // compass_x
  // compass_y
  // compass_z
  return true;
}

void
marvelmind_ros2_msgs__msg__HedgeImuRaw__fini(marvelmind_ros2_msgs__msg__HedgeImuRaw * msg)
{
  if (!msg) {
    return;
  }
  // timestamp_ms
  // acc_x
  // acc_y
  // acc_z
  // gyro_x
  // gyro_y
  // gyro_z
  // compass_x
  // compass_y
  // compass_z
}

bool
marvelmind_ros2_msgs__msg__HedgeImuRaw__are_equal(const marvelmind_ros2_msgs__msg__HedgeImuRaw * lhs, const marvelmind_ros2_msgs__msg__HedgeImuRaw * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp_ms
  if (lhs->timestamp_ms != rhs->timestamp_ms) {
    return false;
  }
  // acc_x
  if (lhs->acc_x != rhs->acc_x) {
    return false;
  }
  // acc_y
  if (lhs->acc_y != rhs->acc_y) {
    return false;
  }
  // acc_z
  if (lhs->acc_z != rhs->acc_z) {
    return false;
  }
  // gyro_x
  if (lhs->gyro_x != rhs->gyro_x) {
    return false;
  }
  // gyro_y
  if (lhs->gyro_y != rhs->gyro_y) {
    return false;
  }
  // gyro_z
  if (lhs->gyro_z != rhs->gyro_z) {
    return false;
  }
  // compass_x
  if (lhs->compass_x != rhs->compass_x) {
    return false;
  }
  // compass_y
  if (lhs->compass_y != rhs->compass_y) {
    return false;
  }
  // compass_z
  if (lhs->compass_z != rhs->compass_z) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeImuRaw__copy(
  const marvelmind_ros2_msgs__msg__HedgeImuRaw * input,
  marvelmind_ros2_msgs__msg__HedgeImuRaw * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp_ms
  output->timestamp_ms = input->timestamp_ms;
  // acc_x
  output->acc_x = input->acc_x;
  // acc_y
  output->acc_y = input->acc_y;
  // acc_z
  output->acc_z = input->acc_z;
  // gyro_x
  output->gyro_x = input->gyro_x;
  // gyro_y
  output->gyro_y = input->gyro_y;
  // gyro_z
  output->gyro_z = input->gyro_z;
  // compass_x
  output->compass_x = input->compass_x;
  // compass_y
  output->compass_y = input->compass_y;
  // compass_z
  output->compass_z = input->compass_z;
  return true;
}

marvelmind_ros2_msgs__msg__HedgeImuRaw *
marvelmind_ros2_msgs__msg__HedgeImuRaw__create()
{
  marvelmind_ros2_msgs__msg__HedgeImuRaw * msg = (marvelmind_ros2_msgs__msg__HedgeImuRaw *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeImuRaw));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__HedgeImuRaw));
  bool success = marvelmind_ros2_msgs__msg__HedgeImuRaw__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__HedgeImuRaw__destroy(marvelmind_ros2_msgs__msg__HedgeImuRaw * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__HedgeImuRaw__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__init(marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__HedgeImuRaw * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__HedgeImuRaw *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__HedgeImuRaw));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__HedgeImuRaw__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__HedgeImuRaw__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__fini(marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__HedgeImuRaw__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence *
marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * array = (marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__destroy(marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__are_equal(const marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * lhs, const marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__HedgeImuRaw__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence__copy(
  const marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * input,
  marvelmind_ros2_msgs__msg__HedgeImuRaw__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__HedgeImuRaw);
    marvelmind_ros2_msgs__msg__HedgeImuRaw * data =
      (marvelmind_ros2_msgs__msg__HedgeImuRaw *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__HedgeImuRaw__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__HedgeImuRaw__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__HedgeImuRaw__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
