import ctypes
from ctypes import *


def errcheck(result,func,args):
    if result == float('inf'):
        raise ZeroDivisionError()
    return args

# Загружаем библиотеку
adder = CDLL('./adder.so')
adder.add.argtypes = [ctypes.c_double, ctypes.c_double]
adder.add.restype = ctypes.c_double
add = adder.add

adder.sub.argtypes = [ctypes.c_double, ctypes.c_double]
adder.sub.restype = ctypes.c_double
sub = adder.sub

adder.mul.argtypes = [ctypes.c_double, ctypes.c_double]
adder.mul.restype = ctypes.c_double
mul = adder.mul

adder.div.argtypes = [ctypes.c_double, ctypes.c_double]
adder.div.restype = ctypes.c_double
adder.div.errcheck = errcheck
div = adder.div