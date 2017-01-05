import cffi
import sys
import traceback

ffi = cffi.FFI()
ffi.cdef(file('neko.h').read())
noGCDict = {}

@ffi.callback("int (t_lbstat*, int)")
def start(x, y):
  return y

@ffi.callback("int (t_lbstat*, int)")
def end(x, y):
  return y

def fill_api(ptr):
  global the_ffi
  the_ffi = ffi.cast("struct API*", ptr)
  the_ffi.start = start
  the_ffi.end = end
