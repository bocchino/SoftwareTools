// arr.c
// ----------------------------------------------------------------------
// Array implementation
// ----------------------------------------------------------------------

#include "arr.h"
#include "error.h"
#include "allocate.h"

void *__arr_new(size_t length, size_t tsize) {
#ifdef DEBUG
  void *p = __allocate(sizeof(size_t) + length * tsize);
  *((size_t*) p) = length * tsize;
  return p;
#else
  size_t p = (size_t) __allocate(length * tsize);
  return (void *) (p - tsize); 
#endif
}

#ifdef DEBUG
void *__arr_at(void * const a, size_t i, size_t tsize) {
  size_t len = ARR_LEN(a);
  if (i == 0) error(STR_CONST("zero index not allowed"));
  if (i * tsize > len) error(STR_CONST("index too large"));
  size_t p = (size_t) a;
  return (void*) (p + sizeof(size_t) + (i - 1) * tsize);
}
#endif

