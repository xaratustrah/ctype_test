#!/usr/bin/env python

# Example to wrap C functions in python using ctypes

# See http://stackoverflow.com/questions/145270/calling-c-c-from-python

# ** Python wrapper file **
# To be used with example C++ file: http://pastebin.com/pyUXf3RW
# Tested in Ubuntu 14.04

from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_double

lib = cdll.LoadLibrary('./libfoo.so')


class Foo(object):
    def __init__(self):
        self.obj = lib.Foo_new()

    def bar(self):
        lib.Foo_bar(self.obj)

    def doubleme(self, intnumber):
        return lib.Foo_doubleme(self.obj, intnumber)

    def printfloat(self, doublenumber):
        lib.Foo_printfloat(self.obj, c_double(doublenumber))


f = Foo()
f.bar()
test = f.doubleme(4)
print(test)
f.printfloat(6.3)

