#include <dlfcn.h>

#include <stdio.h>
#include "neko.h"

int main(void)
{ void* bundle = dlopen("libss.so", RTLD_LAZY);
  void (*start)();
  void (*end)();
  start = dlsym(bundle, "start");
  end = dlsym(bundle, "end");
  (*start)();
  (*end)();
  dlclose(bundle); }
