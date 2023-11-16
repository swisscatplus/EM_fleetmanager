# generated from rosidl_generator_py/resource/_idl.py.em
# with input from marvelmind_ros2_msgs:srv/MarvelmindAPI.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'request'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MarvelmindAPI_Request(type):
    """Metaclass of message 'MarvelmindAPI_Request'."""

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
                'marvelmind_ros2_msgs.srv.MarvelmindAPI_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__marvelmind_api__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__marvelmind_api__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__marvelmind_api__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__marvelmind_api__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__marvelmind_api__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarvelmindAPI_Request(metaclass=Metaclass_MarvelmindAPI_Request):
    """Message class 'MarvelmindAPI_Request'."""

    __slots__ = [
        '_command_id',
        '_request',
    ]

    _fields_and_field_types = {
        'command_id': 'int64',
        'request': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.command_id = kwargs.get('command_id', int())
        self.request = array.array('B', kwargs.get('request', []))

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
        if self.command_id != other.command_id:
            return False
        if self.request != other.request:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def command_id(self):
        """Message field 'command_id'."""
        return self._command_id

    @command_id.setter
    def command_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command_id' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'command_id' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._command_id = value

    @property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'request' array.array() must have the type code of 'B'"
            self._request = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'request' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._request = array.array('B', value)


# Import statements for member types

# Member 'response'
# already imported above
# import array

# already imported above
# import rosidl_parser.definition


class Metaclass_MarvelmindAPI_Response(type):
    """Metaclass of message 'MarvelmindAPI_Response'."""

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
                'marvelmind_ros2_msgs.srv.MarvelmindAPI_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__marvelmind_api__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__marvelmind_api__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__marvelmind_api__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__marvelmind_api__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__marvelmind_api__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarvelmindAPI_Response(metaclass=Metaclass_MarvelmindAPI_Response):
    """Message class 'MarvelmindAPI_Response'."""

    __slots__ = [
        '_success',
        '_error_code',
        '_response',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'error_code': 'int32',
        'response': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.error_code = kwargs.get('error_code', int())
        self.response = array.array('B', kwargs.get('response', []))

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
        if self.success != other.success:
            return False
        if self.error_code != other.error_code:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @property
    def error_code(self):
        """Message field 'error_code'."""
        return self._error_code

    @error_code.setter
    def error_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'error_code' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'error_code' field must be an integer in [-2147483648, 2147483647]"
        self._error_code = value

    @property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'response' array.array() must have the type code of 'B'"
            self._response = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'response' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._response = array.array('B', value)


class Metaclass_MarvelmindAPI(type):
    """Metaclass of service 'MarvelmindAPI'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('marvelmind_ros2_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'marvelmind_ros2_msgs.srv.MarvelmindAPI')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__marvelmind_api

            from marvelmind_ros2_msgs.srv import _marvelmind_api
            if _marvelmind_api.Metaclass_MarvelmindAPI_Request._TYPE_SUPPORT is None:
                _marvelmind_api.Metaclass_MarvelmindAPI_Request.__import_type_support__()
            if _marvelmind_api.Metaclass_MarvelmindAPI_Response._TYPE_SUPPORT is None:
                _marvelmind_api.Metaclass_MarvelmindAPI_Response.__import_type_support__()


class MarvelmindAPI(metaclass=Metaclass_MarvelmindAPI):
    from marvelmind_ros2_msgs.srv._marvelmind_api import MarvelmindAPI_Request as Request
    from marvelmind_ros2_msgs.srv._marvelmind_api import MarvelmindAPI_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
