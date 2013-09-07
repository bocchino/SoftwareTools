// arr.h
// ----------------------------------------------------------------------
// Operations on array types
// ----------------------------------------------------------------------

#ifndef ARR_H
#define ARR_H

#include <stdlib.h>
#include "arr_type.h"
#include "error.h"

#define ARR_HEAP(a,t,n) \
  ARR(t) a = malloc(n * sizeof(t)); \
  if (!a) error("ARR_HEAP: out of memory");
#define ARR_STACK(a,t,n) \
  ARR(t) a = alloca(n * sizeof(t)); \
  if (!a) error("ARR_STACK: out of memory");
#define ARR_AT(a,i) a[i-1]

#endif
