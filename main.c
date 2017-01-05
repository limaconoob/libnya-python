#include <dlfcn.h>

#include <stdio.h>
#include "neko.h"

int main(void)
{ void* bundle = dlopen("libss.so", RTLD_LAZY);
  t_lbstat *lib;
  void (*start)(t_lbstat*, void**);
  void (*end)(t_lbstat*, void**);
  start = dlsym(bundle, "start");
  end = dlsym(bundle, "end");
  (*start)(lib, (void**)lib);
  (*end)(lib, (void**)lib);
  dlclose(bundle); }
