from google.protobuf.internal import containers as _containers
from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Iterable as _Iterable, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class AlignmentState(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    Problem: _ClassVar[AlignmentState]
    Ally: _ClassVar[AlignmentState]
    Enemy: _ClassVar[AlignmentState]

class ClassName(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    Problem_2: _ClassVar[ClassName]
    Corvette: _ClassVar[ClassName]
    Frigate: _ClassVar[ClassName]
    Cruiser: _ClassVar[ClassName]
    Destroyer: _ClassVar[ClassName]
    Carrier: _ClassVar[ClassName]
    Dreadnought: _ClassVar[ClassName]

class DumbProtoBool(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    Problem3: _ClassVar[DumbProtoBool]
    True: _ClassVar[DumbProtoBool]
    False: _ClassVar[DumbProtoBool]
Problem: AlignmentState
Ally: AlignmentState
Enemy: AlignmentState
Problem_2: ClassName
Corvette: ClassName
Frigate: ClassName
Cruiser: ClassName
Destroyer: ClassName
Carrier: ClassName
Dreadnought: ClassName
Problem3: DumbProtoBool
True: DumbProtoBool
False: DumbProtoBool

class Officers(_message.Message):
    __slots__ = ("firstName", "lastName", "rank")
    FIRSTNAME_FIELD_NUMBER: _ClassVar[int]
    LASTNAME_FIELD_NUMBER: _ClassVar[int]
    RANK_FIELD_NUMBER: _ClassVar[int]
    firstName: str
    lastName: str
    rank: str
    def __init__(self, firstName: _Optional[str] = ..., lastName: _Optional[str] = ..., rank: _Optional[str] = ...) -> None: ...

class Ships(_message.Message):
    __slots__ = ("alignment", "name", "classs", "length", "crew_size", "armed", "oficer_crew")
    ALIGNMENT_FIELD_NUMBER: _ClassVar[int]
    NAME_FIELD_NUMBER: _ClassVar[int]
    CLASSS_FIELD_NUMBER: _ClassVar[int]
    LENGTH_FIELD_NUMBER: _ClassVar[int]
    CREW_SIZE_FIELD_NUMBER: _ClassVar[int]
    ARMED_FIELD_NUMBER: _ClassVar[int]
    OFICER_CREW_FIELD_NUMBER: _ClassVar[int]
    alignment: AlignmentState
    name: str
    classs: ClassName
    length: float
    crew_size: int
    armed: DumbProtoBool
    oficer_crew: _containers.RepeatedCompositeFieldContainer[Officers]
    def __init__(self, alignment: _Optional[_Union[AlignmentState, str]] = ..., name: _Optional[str] = ..., classs: _Optional[_Union[ClassName, str]] = ..., length: _Optional[float] = ..., crew_size: _Optional[int] = ..., armed: _Optional[_Union[DumbProtoBool, str]] = ..., oficer_crew: _Optional[_Iterable[_Union[Officers, _Mapping]]] = ...) -> None: ...

class CoordinatesRequest(_message.Message):
    __slots__ = ("asc_hour", "asc_min", "asc_sec", "dec_fir", "dec_sec", "dec_thi")
    ASC_HOUR_FIELD_NUMBER: _ClassVar[int]
    ASC_MIN_FIELD_NUMBER: _ClassVar[int]
    ASC_SEC_FIELD_NUMBER: _ClassVar[int]
    DEC_FIR_FIELD_NUMBER: _ClassVar[int]
    DEC_SEC_FIELD_NUMBER: _ClassVar[int]
    DEC_THI_FIELD_NUMBER: _ClassVar[int]
    asc_hour: float
    asc_min: float
    asc_sec: float
    dec_fir: float
    dec_sec: float
    dec_thi: float
    def __init__(self, asc_hour: _Optional[float] = ..., asc_min: _Optional[float] = ..., asc_sec: _Optional[float] = ..., dec_fir: _Optional[float] = ..., dec_sec: _Optional[float] = ..., dec_thi: _Optional[float] = ...) -> None: ...

class ShipsResponse(_message.Message):
    __slots__ = ("ship",)
    SHIP_FIELD_NUMBER: _ClassVar[int]
    ship: _containers.RepeatedCompositeFieldContainer[Ships]
    def __init__(self, ship: _Optional[_Iterable[_Union[Ships, _Mapping]]] = ...) -> None: ...
