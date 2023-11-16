// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav2_msgs:msg/ParticleCloud.idl
// generated code does not contain a copyright notice
#include "nav2_msgs/msg/detail/particle_cloud__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `particles`
#include "nav2_msgs/msg/detail/particle__functions.h"

bool
nav2_msgs__msg__ParticleCloud__init(nav2_msgs__msg__ParticleCloud * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nav2_msgs__msg__ParticleCloud__fini(msg);
    return false;
  }
  // particles
  if (!nav2_msgs__msg__Particle__Sequence__init(&msg->particles, 0)) {
    nav2_msgs__msg__ParticleCloud__fini(msg);
    return false;
  }
  return true;
}

void
nav2_msgs__msg__ParticleCloud__fini(nav2_msgs__msg__ParticleCloud * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // particles
  nav2_msgs__msg__Particle__Sequence__fini(&msg->particles);
}

bool
nav2_msgs__msg__ParticleCloud__are_equal(const nav2_msgs__msg__ParticleCloud * lhs, const nav2_msgs__msg__ParticleCloud * rhs)
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
  // particles
  if (!nav2_msgs__msg__Particle__Sequence__are_equal(
      &(lhs->particles), &(rhs->particles)))
  {
    return false;
  }
  return true;
}

bool
nav2_msgs__msg__ParticleCloud__copy(
  const nav2_msgs__msg__ParticleCloud * input,
  nav2_msgs__msg__ParticleCloud * output)
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
  // particles
  if (!nav2_msgs__msg__Particle__Sequence__copy(
      &(input->particles), &(output->particles)))
  {
    return false;
  }
  return true;
}

nav2_msgs__msg__ParticleCloud *
nav2_msgs__msg__ParticleCloud__create()
{
  nav2_msgs__msg__ParticleCloud * msg = (nav2_msgs__msg__ParticleCloud *)malloc(sizeof(nav2_msgs__msg__ParticleCloud));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav2_msgs__msg__ParticleCloud));
  bool success = nav2_msgs__msg__ParticleCloud__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
nav2_msgs__msg__ParticleCloud__destroy(nav2_msgs__msg__ParticleCloud * msg)
{
  if (msg) {
    nav2_msgs__msg__ParticleCloud__fini(msg);
  }
  free(msg);
}


bool
nav2_msgs__msg__ParticleCloud__Sequence__init(nav2_msgs__msg__ParticleCloud__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  nav2_msgs__msg__ParticleCloud * data = NULL;
  if (size) {
    data = (nav2_msgs__msg__ParticleCloud *)calloc(size, sizeof(nav2_msgs__msg__ParticleCloud));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav2_msgs__msg__ParticleCloud__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav2_msgs__msg__ParticleCloud__fini(&data[i - 1]);
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
nav2_msgs__msg__ParticleCloud__Sequence__fini(nav2_msgs__msg__ParticleCloud__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nav2_msgs__msg__ParticleCloud__fini(&array->data[i]);
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

nav2_msgs__msg__ParticleCloud__Sequence *
nav2_msgs__msg__ParticleCloud__Sequence__create(size_t size)
{
  nav2_msgs__msg__ParticleCloud__Sequence * array = (nav2_msgs__msg__ParticleCloud__Sequence *)malloc(sizeof(nav2_msgs__msg__ParticleCloud__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = nav2_msgs__msg__ParticleCloud__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
nav2_msgs__msg__ParticleCloud__Sequence__destroy(nav2_msgs__msg__ParticleCloud__Sequence * array)
{
  if (array) {
    nav2_msgs__msg__ParticleCloud__Sequence__fini(array);
  }
  free(array);
}

bool
nav2_msgs__msg__ParticleCloud__Sequence__are_equal(const nav2_msgs__msg__ParticleCloud__Sequence * lhs, const nav2_msgs__msg__ParticleCloud__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav2_msgs__msg__ParticleCloud__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav2_msgs__msg__ParticleCloud__Sequence__copy(
  const nav2_msgs__msg__ParticleCloud__Sequence * input,
  nav2_msgs__msg__ParticleCloud__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nav2_msgs__msg__ParticleCloud);
    nav2_msgs__msg__ParticleCloud * data =
      (nav2_msgs__msg__ParticleCloud *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav2_msgs__msg__ParticleCloud__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          nav2_msgs__msg__ParticleCloud__fini(&data[i]);
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
    if (!nav2_msgs__msg__ParticleCloud__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
