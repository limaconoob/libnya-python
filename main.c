
#include <dlfcn.h>

#include <stdio.h>
#include "neko.h"

int main(void)
{ void* bundle = dlopen("libnya-python.dylib", RTLD_LAZY);
  t_lbstat lib[1];
  unsigned long data = 4;
  void (*start)(t_lbstat*, void**);
  void (*end)(t_lbstat*, void**);
  start = dlsym(bundle, "start");
  end = dlsym(bundle, "end");
  (*start)(lib, (void**)data);
  (*end)(lib, (void**)data);
  dlclose(bundle); }
