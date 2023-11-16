# generated from rosidl_generator_py/resource/_idl.py.em
# with input from marvelmind_ros2_msgs:msg/HedgePositionAngle.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HedgePositionAngle(type):
    """Metaclass of message 'HedgePositionAngle'."""

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
                'marvelmind_ros2_msgs.msg.HedgePositionAngle')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hedge_position_angle
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hedge_position_angle
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hedge_position_angle
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hedge_position_angle
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hedge_position_angle

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HedgePositionAngle(metaclass=Metaclass_HedgePositionAngle):
    """Message class 'HedgePositionAngle'."""

    __slots__ = [
        '_address',
        '_timestamp_ms',
        '_x_m',
        '_y_m',
        '_z_m',
        '_flags',
        '_angle',
    ]

    _fields_and_field_types = {
        'address': 'uint8',
        'timestamp_ms': 'int64',
        'x_m': 'double',
        'y_m': 'double',
        'z_m': 'double',
        'flags': 'uint8',
        'angle': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.address = kwargs.get('address', int())
        self.timestamp_ms = kwargs.get('timestamp_ms', int())
        self.x_m = kwargs.get('x_m', float())
        self.y_m = kwargs.get('y_m', float())
        self.z_m = kwargs.get('z_m', float())
        self.flags = kwargs.get('flags', int())
        self.angle = kwargs.get('angle', float())

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
        if self.address != other.address:
            return False
        if self.timestamp_ms != other.timestamp_ms:
            return False
        if self.x_m != other.x_m:
            return False
        if self.y_m != other.y_m:
            return False
        if self.z_m != other.z_m:
            return False
        if self.flags != other.flags:
            return False
        if self.angle != other.angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def address(self):
        """Message field 'address'."""
        return self._address

    @address.setter
    def address(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'address' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'address' field must be an unsigned integer in [0, 255]"
        self._address = value

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
    def x_m(self):
        """Message field 'x_m'."""
        return self._x_m

    @x_m.setter
    def x_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_m' field must be of type 'float'"
        self._x_m = value

    @property
    def y_m(self):
        """Message field 'y_m'."""
        return self._y_m

    @y_m.setter
    def y_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_m' field must be of type 'float'"
        self._y_m = value

    @property
    def z_m(self):
        """Message field 'z_m'."""
        return self._z_m

    @z_m.setter
    def z_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z_m' field must be of type 'float'"
        self._z_m = value

    @property
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'flags' field must be an unsigned integer in [0, 255]"
        self._flags = value

    @property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angle' field must be of type 'float'"
        self._angle = value
