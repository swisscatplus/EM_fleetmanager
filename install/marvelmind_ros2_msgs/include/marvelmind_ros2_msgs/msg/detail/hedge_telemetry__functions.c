// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeTelemetry.idl
// generated code does not contain a copyright notice
#include "marvelmind_ros2_msgs/msg/detail/hedge_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
marvelmind_ros2_msgs__msg__HedgeTelemetry__init(marvelmind_ros2_msgs__msg__HedgeTelemetry * msg)
{
  if (!msg) {
    return false;
  }
  // battery_voltage
  // rssi_dbm
  return true;
}

void
marvelmind_ros2_msgs__msg__HedgeTelemetry__fini(marvelmind_ros2_msgs__msg__HedgeTelemetry * msg)
{
  if (!msg) {
    return;
  }
  // battery_voltage
  // rssi_dbm
}

bool
marvelmind_ros2_msgs__msg__HedgeTelemetry__are_equal(const marvelmind_ros2_msgs__msg__HedgeTelemetry * lhs, const marvelmind_ros2_msgs__msg__HedgeTelemetry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // rssi_dbm
  if (lhs->rssi_dbm != rhs->rssi_dbm) {
    return false;
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeTelemetry__copy(
  const marvelmind_ros2_msgs__msg__HedgeTelemetry * input,
  marvelmind_ros2_msgs__msg__HedgeTelemetry * output)
{
  if (!input || !output) {
    return false;
  }
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // rssi_dbm
  output->rssi_dbm = input->rssi_dbm;
  return true;
}

marvelmind_ros2_msgs__msg__HedgeTelemetry *
marvelmind_ros2_msgs__msg__HedgeTelemetry__create()
{
  marvelmind_ros2_msgs__msg__HedgeTelemetry * msg = (marvelmind_ros2_msgs__msg__HedgeTelemetry *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeTelemetry));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(marvelmind_ros2_msgs__msg__HedgeTelemetry));
  bool success = marvelmind_ros2_msgs__msg__HedgeTelemetry__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
marvelmind_ros2_msgs__msg__HedgeTelemetry__destroy(marvelmind_ros2_msgs__msg__HedgeTelemetry * msg)
{
  if (msg) {
    marvelmind_ros2_msgs__msg__HedgeTelemetry__fini(msg);
  }
  free(msg);
}


bool
marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__init(marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  marvelmind_ros2_msgs__msg__HedgeTelemetry * data = NULL;
  if (size) {
    data = (marvelmind_ros2_msgs__msg__HedgeTelemetry *)calloc(size, sizeof(marvelmind_ros2_msgs__msg__HedgeTelemetry));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = marvelmind_ros2_msgs__msg__HedgeTelemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        marvelmind_ros2_msgs__msg__HedgeTelemetry__fini(&data[i - 1]);
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
marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__fini(marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      marvelmind_ros2_msgs__msg__HedgeTelemetry__fini(&array->data[i]);
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

marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence *
marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__create(size_t size)
{
  marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * array = (marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence *)malloc(sizeof(marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__destroy(marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * array)
{
  if (array) {
    marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__fini(array);
  }
  free(array);
}

bool
marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__are_equal(const marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * lhs, const marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!marvelmind_ros2_msgs__msg__HedgeTelemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence__copy(
  const marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * input,
  marvelmind_ros2_msgs__msg__HedgeTelemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(marvelmind_ros2_msgs__msg__HedgeTelemetry);
    marvelmind_ros2_msgs__msg__HedgeTelemetry * data =
      (marvelmind_ros2_msgs__msg__HedgeTelemetry *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!marvelmind_ros2_msgs__msg__HedgeTelemetry__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          marvelmind_ros2_msgs__msg__HedgeTelemetry__fini(&data[i]);
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
    if (!marvelmind_ros2_msgs__msg__HedgeTelemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
