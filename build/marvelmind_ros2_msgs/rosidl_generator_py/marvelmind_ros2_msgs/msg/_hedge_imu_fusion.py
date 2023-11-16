# generated from rosidl_generator_py/resource/_idl.py.em
# with input from marvelmind_ros2_msgs:msg/HedgeImuFusion.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HedgeImuFusion(type):
    """Metaclass of message 'HedgeImuFusion'."""

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
                'marvelmind_ros2_msgs.msg.HedgeImuFusion')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hedge_imu_fusion
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hedge_imu_fusion
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hedge_imu_fusion
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hedge_imu_fusion
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hedge_imu_fusion

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HedgeImuFusion(metaclass=Metaclass_HedgeImuFusion):
    """Message class 'HedgeImuFusion'."""

    __slots__ = [
        '_timestamp_ms',
        '_x_m',
        '_y_m',
        '_z_m',
        '_qw',
        '_qx',
        '_qy',
        '_qz',
        '_vx',
        '_vy',
        '_vz',
        '_ax',
        '_ay',
        '_az',
    ]

    _fields_and_field_types = {
        'timestamp_ms': 'int64',
        'x_m': 'double',
        'y_m': 'double',
        'z_m': 'double',
        'qw': 'double',
        'qx': 'double',
        'qy': 'double',
        'qz': 'double',
        'vx': 'double',
        'vy': 'double',
        'vz': 'double',
        'ax': 'double',
        'ay': 'double',
        'az': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.timestamp_ms = kwargs.get('timestamp_ms', int())
        self.x_m = kwargs.get('x_m', float())
        self.y_m = kwargs.get('y_m', float())
        self.z_m = kwargs.get('z_m', float())
        self.qw = kwargs.get('qw', float())
        self.qx = kwargs.get('qx', float())
        self.qy = kwargs.get('qy', float())
        self.qz = kwargs.get('qz', float())
        self.vx = kwargs.get('vx', float())
        self.vy = kwargs.get('vy', float())
        self.vz = kwargs.get('vz', float())
        self.ax = kwargs.get('ax', float())
        self.ay = kwargs.get('ay', float())
        self.az = kwargs.get('az', float())

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
        if self.x_m != other.x_m:
            return False
        if self.y_m != other.y_m:
            return False
        if self.z_m != other.z_m:
            return False
        if self.qw != other.qw:
            return False
        if self.qx != other.qx:
            return False
        if self.qy != other.qy:
            return False
        if self.qz != other.qz:
            return False
        if self.vx != other.vx:
            return False
        if self.vy != other.vy:
            return False
        if self.vz != other.vz:
            return False
        if self.ax != other.ax:
            return False
        if self.ay != other.ay:
            return False
        if self.az != other.az:
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
    def qw(self):
        """Message field 'qw'."""
        return self._qw

    @qw.setter
    def qw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'qw' field must be of type 'float'"
        self._qw = value

    @property
    def qx(self):
        """Message field 'qx'."""
        return self._qx

    @qx.setter
    def qx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'qx' field must be of type 'float'"
        self._qx = value

    @property
    def qy(self):
        """Message field 'qy'."""
        return self._qy

    @qy.setter
    def qy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'qy' field must be of type 'float'"
        self._qy = value

    @property
    def qz(self):
        """Message field 'qz'."""
        return self._qz

    @qz.setter
    def qz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'qz' field must be of type 'float'"
        self._qz = value

    @property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vx' field must be of type 'float'"
        self._vx = value

    @property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vy' field must be of type 'float'"
        self._vy = value

    @property
    def vz(self):
        """Message field 'vz'."""
        return self._vz

    @vz.setter
    def vz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vz' field must be of type 'float'"
        self._vz = value

    @property
    def ax(self):
        """Message field 'ax'."""
        return self._ax

    @ax.setter
    def ax(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ax' field must be of type 'float'"
        self._ax = value

    @property
    def ay(self):
        """Message field 'ay'."""
        return self._ay

    @ay.setter
    def ay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ay' field must be of type 'float'"
        self._ay = value

    @property
    def az(self):
        """Message field 'az'."""
        return self._az

    @az.setter
    def az(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'az' field must be of type 'float'"
        self._az = value
