# generated from rosidl_generator_py/resource/_idl.py.em
# with input from marvelmind_ros2_msgs:msg/BeaconPositionAddressed.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BeaconPositionAddressed(type):
    """Metaclass of message 'BeaconPositionAddressed'."""

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
                'marvelmind_ros2_msgs.msg.BeaconPositionAddressed')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__beacon_position_addressed
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__beacon_position_addressed
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__beacon_position_addressed
            cls._TYPE_SUPPORT = module.type_support_msg__msg__beacon_position_addressed
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__beacon_position_addressed

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BeaconPositionAddressed(metaclass=Metaclass_BeaconPositionAddressed):
    """Message class 'BeaconPositionAddressed'."""

    __slots__ = [
        '_address',
        '_x_m',
        '_y_m',
        '_z_m',
    ]

    _fields_and_field_types = {
        'address': 'uint8',
        'x_m': 'double',
        'y_m': 'double',
        'z_m': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.address = kwargs.get('address', int())
        self.x_m = kwargs.get('x_m', float())
        self.y_m = kwargs.get('y_m', float())
        self.z_m = kwargs.get('z_m', float())

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
        if self.x_m != other.x_m:
            return False
        if self.y_m != other.y_m:
            return False
        if self.z_m != other.z_m:
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
