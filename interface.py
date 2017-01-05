import cffi
import sys
import traceback

ffi = cffi.FFI()
ffi.cdef(file('neko.h').read())
noGCDict = {}

@ffi.callback("void (t_lbstat*, void**)")
def start(x, y):
  x.sheet = Bust
  x.position.cardinal = LowerLeft
  print(y)

@ffi.callback("void (t_lbstat*, void**)")
def end(x, y):
  print(y)

def fill_api(ptr):
  global the_ffi
  the_ffi = ffi.cast("struct API*", ptr)
  the_ffi.start = start
  the_ffi.end = end
