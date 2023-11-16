// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav2_msgs:srv/GetCostmap.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/srv/detail/get_costmap__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `specs`
#include "nav2_msgs/msg/detail/costmap_meta_data__functions.h"

bool
nav2_msgs__srv__GetCostmap_Request__init(nav2_msgs__srv__GetCostmap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // specs
  if (!nav2_msgs__msg__CostmapMetaData__init(&msg->specs)) {
    nav2_msgs__srv__GetCostmap_Request__fini(msg);
    return false;
  }
  return true;
}

void
nav2_msgs__srv__GetCostmap_Request__fini(nav2_msgs__srv__GetCostmap_Request * msg)
{
  if (!msg) {
    return;
  }
  // specs
  nav2_msgs__msg__CostmapMetaData__fini(&msg->specs);
}

bool
nav2_msgs__srv__GetCostmap_Request__are_equal(const nav2_msgs__srv__GetCostmap_Request * lhs, const nav2_msgs__srv__GetCostmap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // specs
  if (!nav2_msgs__msg__CostmapMetaData__are_equal(
      &(lhs->specs), &(rhs->specs)))
  {
    return false;
  }
  return true;
}

bool
nav2_msgs__srv__GetCostmap_Request__copy(
  const nav2_msgs__srv__GetCostmap_Request * input,
  nav2_msgs__srv__GetCostmap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // specs
  if (!nav2_msgs__msg__CostmapMetaData__copy(
      &(input->specs), &(output->specs)))
  {
    return false;
  }
  return true;
}

nav2_msgs__srv__GetCostmap_Request *
nav2_msgs__srv__GetCostmap_Request__create()
{
  nav2_msgs__srv__GetCostmap_Request * msg = (nav2_msgs__srv__GetCostmap_Request *)malloc(sizeof(nav2_msgs__srv__GetCostmap_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav2_msgs__srv__GetCostmap_Request));
  bool success = nav2_msgs__srv__GetCostmap_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
nav2_msgs__srv__GetCostmap_Request__destroy(nav2_msgs__srv__GetCostmap_Request * msg)
{
  if (msg) {
    nav2_msgs__srv__GetCostmap_Request__fini(msg);
  }
  free(msg);
}


bool
nav2_msgs__srv__GetCostmap_Request__Sequence__init(nav2_msgs__srv__GetCostmap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  nav2_msgs__srv__GetCostmap_Request * data = NULL;
  if (size) {
    data = (nav2_msgs__srv__GetCostmap_Request *)calloc(size, sizeof(nav2_msgs__srv__GetCostmap_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav2_msgs__srv__GetCostmap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav2_msgs__srv__GetCostmap_Request__fini(&data[i - 1]);
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
nav2_msgs__srv__GetCostmap_Request__Sequence__fini(nav2_msgs__srv__GetCostmap_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nav2_msgs__srv__GetCostmap_Request__fini(&array->data[i]);
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

nav2_msgs__srv__GetCostmap_Request__Sequence *
nav2_msgs__srv__GetCostmap_Request__Sequence__create(size_t size)
{
  nav2_msgs__srv__GetCostmap_Request__Sequence * array = (nav2_msgs__srv__GetCostmap_Request__Sequence *)malloc(sizeof(nav2_msgs__srv__GetCostmap_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = nav2_msgs__srv__GetCostmap_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
nav2_msgs__srv__GetCostmap_Request__Sequence__destroy(nav2_msgs__srv__GetCostmap_Request__Sequence * array)
{
  if (array) {
    nav2_msgs__srv__GetCostmap_Request__Sequence__fini(array);
  }
  free(array);
}

bool
nav2_msgs__srv__GetCostmap_Request__Sequence__are_equal(const nav2_msgs__srv__GetCostmap_Request__Sequence * lhs, const nav2_msgs__srv__GetCostmap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav2_msgs__srv__GetCostmap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav2_msgs__srv__GetCostmap_Request__Sequence__copy(
  const nav2_msgs__srv__GetCostmap_Request__Sequence * input,
  nav2_msgs__srv__GetCostmap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nav2_msgs__srv__GetCostmap_Request);
    nav2_msgs__srv__GetCostmap_Request * data =
      (nav2_msgs__srv__GetCostmap_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav2_msgs__srv__GetCostmap_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          nav2_msgs__srv__GetCostmap_Request__fini(&data[i]);
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
    if (!nav2_msgs__srv__GetCostmap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `map`
#include "nav2_msgs/msg/detail/costmap__functions.h"

bool
nav2_msgs__srv__GetCostmap_Response__init(nav2_msgs__srv__GetCostmap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // map
  if (!nav2_msgs__msg__Costmap__init(&msg->map)) {
    nav2_msgs__srv__GetCostmap_Response__fini(msg);
    return false;
  }
  return true;
}

void
nav2_msgs__srv__GetCostmap_Response__fini(nav2_msgs__srv__GetCostmap_Response * msg)
{
  if (!msg) {
    return;
  }
  // map
  nav2_msgs__msg__Costmap__fini(&msg->map);
}

bool
nav2_msgs__srv__GetCostmap_Response__are_equal(const nav2_msgs__srv__GetCostmap_Response * lhs, const nav2_msgs__srv__GetCostmap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // map
  if (!nav2_msgs__msg__Costmap__are_equal(
      &(lhs->map), &(rhs->map)))
  {
    return false;
  }
  return true;
}

bool
nav2_msgs__srv__GetCostmap_Response__copy(
  const nav2_msgs__srv__GetCostmap_Response * input,
  nav2_msgs__srv__GetCostmap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // map
  if (!nav2_msgs__msg__Costmap__copy(
      &(input->map), &(output->map)))
  {
    return false;
  }
  return true;
}

nav2_msgs__srv__GetCostmap_Response *
nav2_msgs__srv__GetCostmap_Response__create()
{
  nav2_msgs__srv__GetCostmap_Response * msg = (nav2_msgs__srv__GetCostmap_Response *)malloc(sizeof(nav2_msgs__srv__GetCostmap_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav2_msgs__srv__GetCostmap_Response));
  bool success = nav2_msgs__srv__GetCostmap_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
nav2_msgs__srv__GetCostmap_Response__destroy(nav2_msgs__srv__GetCostmap_Response * msg)
{
  if (msg) {
    nav2_msgs__srv__GetCostmap_Response__fini(msg);
  }
  free(msg);
}


bool
nav2_msgs__srv__GetCostmap_Response__Sequence__init(nav2_msgs__srv__GetCostmap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  nav2_msgs__srv__GetCostmap_Response * data = NULL;
  if (size) {
    data = (nav2_msgs__srv__GetCostmap_Response *)calloc(size, sizeof(nav2_msgs__srv__GetCostmap_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav2_msgs__srv__GetCostmap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav2_msgs__srv__GetCostmap_Response__fini(&data[i - 1]);
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
nav2_msgs__srv__GetCostmap_Response__Sequence__fini(nav2_msgs__srv__GetCostmap_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nav2_msgs__srv__GetCostmap_Response__fini(&array->data[i]);
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

nav2_msgs__srv__GetCostmap_Response__Sequence *
nav2_msgs__srv__GetCostmap_Response__Sequence__create(size_t size)
{
  nav2_msgs__srv__GetCostmap_Response__Sequence * array = (nav2_msgs__srv__GetCostmap_Response__Sequence *)malloc(sizeof(nav2_msgs__srv__GetCostmap_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = nav2_msgs__srv__GetCostmap_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
nav2_msgs__srv__GetCostmap_Response__Sequence__destroy(nav2_msgs__srv__GetCostmap_Response__Sequence * array)
{
  if (array) {
    nav2_msgs__srv__GetCostmap_Response__Sequence__fini(array);
  }
  free(array);
}

bool
nav2_msgs__srv__GetCostmap_Response__Sequence__are_equal(const nav2_msgs__srv__GetCostmap_Response__Sequence * lhs, const nav2_msgs__srv__GetCostmap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav2_msgs__srv__GetCostmap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav2_msgs__srv__GetCostmap_Response__Sequence__copy(
  const nav2_msgs__srv__GetCostmap_Response__Sequence * input,
  nav2_msgs__srv__GetCostmap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nav2_msgs__srv__GetCostmap_Response);
    nav2_msgs__srv__GetCostmap_Response * data =
      (nav2_msgs__srv__GetCostmap_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav2_msgs__srv__GetCostmap_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          nav2_msgs__srv__GetCostmap_Response__fini(&data[i]);
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
    if (!nav2_msgs__srv__GetCostmap_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
