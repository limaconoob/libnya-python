
#include "interface.h"
#include "Python.h"
#include <stdio.h>
#define PYVERIFY(exp) if ((exp) == 0) { fprintf(stderr, "%s[%d]: ", __FILE__, __LINE__); PyErr_Print(); exit(1); }

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
  printf("12 + 5 = %i\n", the_ffi.add_numbers(12, 5)); }

void end(void)
{ Py_Finalize(); }
