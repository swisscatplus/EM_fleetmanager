# generated from rosidl_generator_py/resource/_idl.py.em
# with input from marvelmind_ros2_msgs:msg/MarvelmindWaypoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MarvelmindWaypoint(type):
    """Metaclass of message 'MarvelmindWaypoint'."""

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
                'marvelmind_ros2_msgs.msg.MarvelmindWaypoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__marvelmind_waypoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__marvelmind_waypoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__marvelmind_waypoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__marvelmind_waypoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__marvelmind_waypoint

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarvelmindWaypoint(metaclass=Metaclass_MarvelmindWaypoint):
    """Message class 'MarvelmindWaypoint'."""

    __slots__ = [
        '_total_items',
        '_item_index',
        '_movement_type',
        '_param1',
        '_param2',
        '_param3',
    ]

    _fields_and_field_types = {
        'total_items': 'uint8',
        'item_index': 'uint8',
        'movement_type': 'uint8',
        'param1': 'int16',
        'param2': 'int16',
        'param3': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.total_items = kwargs.get('total_items', int())
        self.item_index = kwargs.get('item_index', int())
        self.movement_type = kwargs.get('movement_type', int())
        self.param1 = kwargs.get('param1', int())
        self.param2 = kwargs.get('param2', int())
        self.param3 = kwargs.get('param3', int())

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
        if self.total_items != other.total_items:
            return False
        if self.item_index != other.item_index:
            return False
        if self.movement_type != other.movement_type:
            return False
        if self.param1 != other.param1:
            return False
        if self.param2 != other.param2:
            return False
        if self.param3 != other.param3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def total_items(self):
        """Message field 'total_items'."""
        return self._total_items

    @total_items.setter
    def total_items(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'total_items' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'total_items' field must be an unsigned integer in [0, 255]"
        self._total_items = value

    @property
    def item_index(self):
        """Message field 'item_index'."""
        return self._item_index

    @item_index.setter
    def item_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'item_index' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'item_index' field must be an unsigned integer in [0, 255]"
        self._item_index = value

    @property
    def movement_type(self):
        """Message field 'movement_type'."""
        return self._movement_type

    @movement_type.setter
    def movement_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'movement_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'movement_type' field must be an unsigned integer in [0, 255]"
        self._movement_type = value

    @property
    def param1(self):
        """Message field 'param1'."""
        return self._param1

    @param1.setter
    def param1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'param1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'param1' field must be an integer in [-32768, 32767]"
        self._param1 = value

    @property
    def param2(self):
        """Message field 'param2'."""
        return self._param2

    @param2.setter
    def param2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'param2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'param2' field must be an integer in [-32768, 32767]"
        self._param2 = value

    @property
    def param3(self):
        """Message field 'param3'."""
        return self._param3

    @param3.setter
    def param3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'param3' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'param3' field must be an integer in [-32768, 32767]"
        self._param3 = value
