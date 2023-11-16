# generated from rosidl_generator_py/resource/_idl.py.em
# with input from marvelmind_ros2_msgs:msg/HedgeImuRaw.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HedgeImuRaw(type):
    """Metaclass of message 'HedgeImuRaw'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('marvelmind_ros2_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'marvelmind_ros2_msgs.msg.HedgeImuRaw')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hedge_imu_raw
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hedge_imu_raw
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hedge_imu_raw
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hedge_imu_raw
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hedge_imu_raw

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HedgeImuRaw(metaclass=Metaclass_HedgeImuRaw):
    """Message class 'HedgeImuRaw'."""

    __slots__ = [
        '_timestamp_ms',
        '_acc_x',
        '_acc_y',
        '_acc_z',
        '_gyro_x',
        '_gyro_y',
        '_gyro_z',
        '_compass_x',
        '_compass_y',
        '_compass_z',
    ]

    _fields_and_field_types = {
        'timestamp_ms': 'int64',
        'acc_x': 'int16',
        'acc_y': 'int16',
        'acc_z': 'int16',
        'gyro_x': 'int16',
        'gyro_y': 'int16',
        'gyro_z': 'int16',
        'compass_x': 'int16',
        'compass_y': 'int16',
        'compass_z': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.timestamp_ms = kwargs.get('timestamp_ms', int())
        self.acc_x = kwargs.get('acc_x', int())
        self.acc_y = kwargs.get('acc_y', int())
        self.acc_z = kwargs.get('acc_z', int())
        self.gyro_x = kwargs.get('gyro_x', int())
        self.gyro_y = kwargs.get('gyro_y', int())
        self.gyro_z = kwargs.get('gyro_z', int())
        self.compass_x = kwargs.get('compass_x', int())
        self.compass_y = kwargs.get('compass_y', int())
        self.compass_z = kwargs.get('compass_z', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.timestamp_ms != other.timestamp_ms:
            return False
        if self.acc_x != other.acc_x:
            return False
        if self.acc_y != other.acc_y:
            return False
        if self.acc_z != other.acc_z:
            return False
        if self.gyro_x != other.gyro_x:
            return False
        if self.gyro_y != other.gyro_y:
            return False
        if self.gyro_z != other.gyro_z:
            return False
        if self.compass_x != other.compass_x:
            return False
        if self.compass_y != other.compass_y:
            return False
        if self.compass_z != other.compass_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def timestamp_ms(self):
        """Message field 'timestamp_ms'."""
        return self._timestamp_ms

    @timestamp_ms.setter
    def timestamp_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp_ms' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'timestamp_ms' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._timestamp_ms = value

    @property
    def acc_x(self):
        """Message field 'acc_x'."""
        return self._acc_x

    @acc_x.setter
    def acc_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'acc_x' field must be an integer in [-32768, 32767]"
        self._acc_x = value

    @property
    def acc_y(self):
        """Message field 'acc_y'."""
        return self._acc_y

    @acc_y.setter
    def acc_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'acc_y' field must be an integer in [-32768, 32767]"
        self._acc_y = value

    @property
    def acc_z(self):
        """Message field 'acc_z'."""
        return self._acc_z

    @acc_z.setter
    def acc_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'acc_z' field must be an integer in [-32768, 32767]"
        self._acc_z = value

    @property
    def gyro_x(self):
        """Message field 'gyro_x'."""
        return self._gyro_x

    @gyro_x.setter
    def gyro_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gyro_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'gyro_x' field must be an integer in [-32768, 32767]"
        self._gyro_x = value

    @property
    def gyro_y(self):
        """Message field 'gyro_y'."""
        return self._gyro_y

    @gyro_y.setter
    def gyro_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gyro_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'gyro_y' field must be an integer in [-32768, 32767]"
        self._gyro_y = value

    @property
    def gyro_z(self):
        """Message field 'gyro_z'."""
        return self._gyro_z

    @gyro_z.setter
    def gyro_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gyro_z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'gyro_z' field must be an integer in [-32768, 32767]"
        self._gyro_z = value

    @property
    def compass_x(self):
        """Message field 'compass_x'."""
        return self._compass_x

    @compass_x.setter
    def compass_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'compass_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'compass_x' field must be an integer in [-32768, 32767]"
        self._compass_x = value

    @property
    def compass_y(self):
        """Message field 'compass_y'."""
        return self._compass_y

    @compass_y.setter
    def compass_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'compass_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'compass_y' field must be an integer in [-32768, 32767]"
        self._compass_y = value

    @property
    def compass_z(self):
        """Message field 'compass_z'."""
        return self._compass_z

    @compass_z.setter
    def compass_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'compass_z' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'compass_z' field must be an integer in [-32768, 32767]"
        self._compass_z = value
