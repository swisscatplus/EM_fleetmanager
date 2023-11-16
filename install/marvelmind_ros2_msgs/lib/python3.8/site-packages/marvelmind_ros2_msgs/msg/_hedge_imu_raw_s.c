// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
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
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_raw__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool marvelmind_ros2_msgs__msg__hedge_imu_raw__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("marvelmind_ros2_msgs.msg._hedge_imu_raw.HedgeImuRaw", full_classname_dest, 51) == 0);
  }
  marvelmind_ros2_msgs__msg__HedgeImuRaw * ros_message = _ros_message;
  {  // timestamp_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp_ms = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // acc_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_x = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // acc_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_y = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // acc_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_z = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gyro_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gyro_x = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gyro_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gyro_y = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gyro_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gyro_z = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // compass_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "compass_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->compass_x = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // compass_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "compass_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->compass_y = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // compass_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "compass_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->compass_z = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * marvelmind_ros2_msgs__msg__hedge_imu_raw__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HedgeImuRaw */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("marvelmind_ros2_msgs.msg._hedge_imu_raw");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HedgeImuRaw");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  marvelmind_ros2_msgs__msg__HedgeImuRaw * ros_message = (marvelmind_ros2_msgs__msg__HedgeImuRaw *)raw_ros_message;
  {  // timestamp_ms
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->timestamp_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->acc_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->acc_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_z
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->acc_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gyro_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gyro_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_z
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gyro_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // compass_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->compass_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "compass_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // compass_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->compass_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "compass_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // compass_z
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->compass_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "compass_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
