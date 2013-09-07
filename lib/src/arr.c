// arr.c
// ----------------------------------------------------------------------
// Array implementation
// ----------------------------------------------------------------------

#include "arr.h"
#include "error.h"
#include "allocate.h"

void *__arr_new(size_t length, size_t tsize) {
  size_t p = (size_t) __allocate(length * tsize);
  return (void *) (p - tsize); 
}

