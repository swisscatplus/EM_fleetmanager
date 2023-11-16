// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dwb_msgs:msg/LocalPlanEvaluation.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/msg/detail/local_plan_evaluation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `twists`
#include "dwb_msgs/msg/detail/trajectory_score__functions.h"

bool
dwb_msgs__msg__LocalPlanEvaluation__init(dwb_msgs__msg__LocalPlanEvaluation * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    dwb_msgs__msg__LocalPlanEvaluation__fini(msg);
    return false;
  }
  // twists
  if (!dwb_msgs__msg__TrajectoryScore__Sequence__init(&msg->twists, 0)) {
    dwb_msgs__msg__LocalPlanEvaluation__fini(msg);
    return false;
  }
  // best_index
  // worst_index
  return true;
}

void
dwb_msgs__msg__LocalPlanEvaluation__fini(dwb_msgs__msg__LocalPlanEvaluation * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // twists
  dwb_msgs__msg__TrajectoryScore__Sequence__fini(&msg->twists);
  // best_index
  // worst_index
}

bool
dwb_msgs__msg__LocalPlanEvaluation__are_equal(const dwb_msgs__msg__LocalPlanEvaluation * lhs, const dwb_msgs__msg__LocalPlanEvaluation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // twists
  if (!dwb_msgs__msg__TrajectoryScore__Sequence__are_equal(
      &(lhs->twists), &(rhs->twists)))
  {
    return false;
  }
  // best_index
  if (lhs->best_index != rhs->best_index) {
    return false;
  }
  // worst_index
  if (lhs->worst_index != rhs->worst_index) {
    return false;
  }
  return true;
}

bool
dwb_msgs__msg__LocalPlanEvaluation__copy(
  const dwb_msgs__msg__LocalPlanEvaluation * input,
  dwb_msgs__msg__LocalPlanEvaluation * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // twists
  if (!dwb_msgs__msg__TrajectoryScore__Sequence__copy(
      &(input->twists), &(output->twists)))
  {
    return false;
  }
  // best_index
  output->best_index = input->best_index;
  // worst_index
  output->worst_index = input->worst_index;
  return true;
}

dwb_msgs__msg__LocalPlanEvaluation *
dwb_msgs__msg__LocalPlanEvaluation__create()
{
  dwb_msgs__msg__LocalPlanEvaluation * msg = (dwb_msgs__msg__LocalPlanEvaluation *)malloc(sizeof(dwb_msgs__msg__LocalPlanEvaluation));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dwb_msgs__msg__LocalPlanEvaluation));
  bool success = dwb_msgs__msg__LocalPlanEvaluation__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
dwb_msgs__msg__LocalPlanEvaluation__destroy(dwb_msgs__msg__LocalPlanEvaluation * msg)
{
  if (msg) {
    dwb_msgs__msg__LocalPlanEvaluation__fini(msg);
  }
  free(msg);
}


bool
dwb_msgs__msg__LocalPlanEvaluation__Sequence__init(dwb_msgs__msg__LocalPlanEvaluation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  dwb_msgs__msg__LocalPlanEvaluation * data = NULL;
  if (size) {
    data = (dwb_msgs__msg__LocalPlanEvaluation *)calloc(size, sizeof(dwb_msgs__msg__LocalPlanEvaluation));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dwb_msgs__msg__LocalPlanEvaluation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dwb_msgs__msg__LocalPlanEvaluation__fini(&data[i - 1]);
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
dwb_msgs__msg__LocalPlanEvaluation__Sequence__fini(dwb_msgs__msg__LocalPlanEvaluation__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dwb_msgs__msg__LocalPlanEvaluation__fini(&array->data[i]);
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

dwb_msgs__msg__LocalPlanEvaluation__Sequence *
dwb_msgs__msg__LocalPlanEvaluation__Sequence__create(size_t size)
{
  dwb_msgs__msg__LocalPlanEvaluation__Sequence * array = (dwb_msgs__msg__LocalPlanEvaluation__Sequence *)malloc(sizeof(dwb_msgs__msg__LocalPlanEvaluation__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = dwb_msgs__msg__LocalPlanEvaluation__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
dwb_msgs__msg__LocalPlanEvaluation__Sequence__destroy(dwb_msgs__msg__LocalPlanEvaluation__Sequence * array)
{
  if (array) {
    dwb_msgs__msg__LocalPlanEvaluation__Sequence__fini(array);
  }
  free(array);
}

bool
dwb_msgs__msg__LocalPlanEvaluation__Sequence__are_equal(const dwb_msgs__msg__LocalPlanEvaluation__Sequence * lhs, const dwb_msgs__msg__LocalPlanEvaluation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dwb_msgs__msg__LocalPlanEvaluation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dwb_msgs__msg__LocalPlanEvaluation__Sequence__copy(
  const dwb_msgs__msg__LocalPlanEvaluation__Sequence * input,
  dwb_msgs__msg__LocalPlanEvaluation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dwb_msgs__msg__LocalPlanEvaluation);
    dwb_msgs__msg__LocalPlanEvaluation * data =
      (dwb_msgs__msg__LocalPlanEvaluation *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dwb_msgs__msg__LocalPlanEvaluation__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dwb_msgs__msg__LocalPlanEvaluation__fini(&data[i]);
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
    if (!dwb_msgs__msg__LocalPlanEvaluation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
