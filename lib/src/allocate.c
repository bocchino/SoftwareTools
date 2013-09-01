// allocate.c
// ----------------------------------------------------------------------
// Memory allocation
// ----------------------------------------------------------------------

#include "allocate.h"
#include "error.h"

void *__allocate(size_t size) {
  void *p = malloc(size);
  if (!p) error(STR_CONST("out of memory"));
  return p;
}
