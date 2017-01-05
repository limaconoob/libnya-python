#include <dlfcn.h>

#include <stdio.h>
#include "neko.h"

int main(void)
{ void* bundle = dlopen("libss.so", RTLD_LAZY);
  t_lbstat lib[1];
  unsigned long data = 4;
  printf("1 LIB::%p\n", lib);
  void (*start)(t_lbstat*, void**);
  void (*end)(t_lbstat*, void**);
  printf("2\n");
  start = dlsym(bundle, "start");
  end = dlsym(bundle, "end");
  printf("3\n");
  (*start)(lib, data);
  (*end)(lib, data);
  dlclose(bundle); }
