
#include "interface.h"
#include "Python.h"
#include <stdio.h>

struct API the_ffi;

void start(void)
{ PyObject *pName, *pModule, *py_results;
  PyObject *fill_api;
  Py_Initialize();
  PyRun_SimpleString
  ( "import sys;"
    "sys.path.insert(0, '.')" );
  pName = PyString_FromString("interface");
  pModule = PyImport_Import(pName);
  Py_DECREF(pName);
  fill_api = PyObject_GetAttrString(pModule, "fill_api");
  py_results = PyObject_CallFunction(fill_api, "k", &the_ffi);
  printf("12 + 5 = %i\n", the_ffi.start(12, 5));
  printf("12 - 5 = %i\n", the_ffi.end(12, 5)); }

void end(void)
{ Py_Finalize(); }
