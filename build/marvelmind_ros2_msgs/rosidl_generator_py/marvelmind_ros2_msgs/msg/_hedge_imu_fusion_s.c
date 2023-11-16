// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from marvelmind_ros2_msgs:msg/HedgeImuFusion.idl
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
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__struct.h"
#include "marvelmind_ros2_msgs/msg/detail/hedge_imu_fusion__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool marvelmind_ros2_msgs__msg__hedge_imu_fusion__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
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
    assert(strncmp("marvelmind_ros2_msgs.msg._hedge_imu_fusion.HedgeImuFusion", full_classname_dest, 57) == 0);
  }
  marvelmind_ros2_msgs__msg__HedgeImuFusion * ros_message = _ros_message;
  {  // timestamp_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp_ms = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // x_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_m = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_m = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_m = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // qw
    PyObject * field = PyObject_GetAttrString(_pymsg, "qw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->qw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // qx
    PyObject * field = PyObject_GetAttrString(_pymsg, "qx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->qx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // qy
    PyObject * field = PyObject_GetAttrString(_pymsg, "qy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->qy = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // qz
    PyObject * field = PyObject_GetAttrString(_pymsg, "qz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->qz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vx
    PyObject * field = PyObject_GetAttrString(_pymsg, "vx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vy
    PyObject * field = PyObject_GetAttrString(_pymsg, "vy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vy = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vz
    PyObject * field = PyObject_GetAttrString(_pymsg, "vz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ax
    PyObject * field = PyObject_GetAttrString(_pymsg, "ax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ax = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ay
    PyObject * field = PyObject_GetAttrString(_pymsg, "ay");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ay = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // az
    PyObject * field = PyObject_GetAttrString(_pymsg, "az");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->az = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * marvelmind_ros2_msgs__msg__hedge_imu_fusion__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HedgeImuFusion */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("marvelmind_ros2_msgs.msg._hedge_imu_fusion");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HedgeImuFusion");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  marvelmind_ros2_msgs__msg__HedgeImuFusion * ros_message = (marvelmind_ros2_msgs__msg__HedgeImuFusion *)raw_ros_message;
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
  {  // x_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // qw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->qw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "qw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // qx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->qx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "qx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // qy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->qy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "qy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // qz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->qz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "qz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ay
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ay);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // az
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->az);
    {
      int rc = PyObject_SetAttrString(_pymessage, "az", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
