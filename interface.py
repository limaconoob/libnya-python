import cffi
import sys
import traceback

ffi = cffi.FFI()
ffi.cdef(file('interface.h').read())
noGCDict = {}

@ffi.callback("int (int, int)")
def add_numbers(x, y):
  return x + y

def fill_api(ptr):
  global the_ffi
  the_ffi = ffi.cast("struct API*", ptr)
  the_ffi.add_numbers = add_numbers
