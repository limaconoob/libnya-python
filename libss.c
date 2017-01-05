#include "neko.h"
#include "Python.h"
#include <stdio.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define PYVERIFY(exp) if ((exp) == 0) { fprintf(stderr, "%s[%d]: ", __FILE__, __LINE__); PyErr_Print(); exit(1); }

struct API the_ffi;

void start(t_lbstat *lib, void **data)
{ PyObject *pName, *pModule, *py_results;
  PyObject *fill_api;
  printf("FILENAME::%s, FILE::%s\n", __FILENAME__, __FILE__);
  printf("A\n");
  Py_Initialize();
  PyRun_SimpleString
  ( "import sys;"
    "sys.path.insert(0, '.')" );
  PYVERIFY(pName = PyString_FromString("interface"))
  printf("D\n");
  PYVERIFY(pModule = PyImport_Import(pName))
  printf("E\n");
  Py_DECREF(pName);
  printf("F\n");
  PYVERIFY(fill_api = PyObject_GetAttrString(pModule, "fill_api"))
  printf("G\n");
  py_results = PyObject_CallFunction(fill_api, "k", &the_ffi);
  printf("H\n");
  the_ffi.start(lib, (void**)data);
  the_ffi.end(lib, (void**)data); }

void end(t_lbstat *lib, void **data)
{ Py_Finalize(); }
