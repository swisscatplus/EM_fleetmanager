// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeQuality.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_quality__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool marvelmind_ros2_msgs__msg__hedge_quality__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("marvelmind_ros2_msgs.msg._hedge_quality.HedgeQuality", full_classname_dest, 52) == 0);
  }
  marvelmind_ros2_msgs__msg__HedgeQuality * ros_message = _ros_message;
  {  // address
    PyObject * field = PyObject_GetAttrString(_pymsg, "address");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->address = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // quality_percents
    PyObject * field = PyObject_GetAttrString(_pymsg, "quality_percents");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->quality_percents = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * marvelmind_ros2_msgs__msg__hedge_quality__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HedgeQuality */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("marvelmind_ros2_msgs.msg._hedge_quality");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HedgeQuality");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  marvelmind_ros2_msgs__msg__HedgeQuality * ros_message = (marvelmind_ros2_msgs__msg__HedgeQuality *)raw_ros_message;
  {  // address
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->address);
    {
      int rc = PyObject_SetAttrString(_pymessage, "address", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quality_percents
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->quality_percents);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quality_percents", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
