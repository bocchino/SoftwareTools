// arr.h
// ----------------------------------------------------------------------
// Array types
// ----------------------------------------------------------------------

#ifndef ARR_H
#define ARR_H

#include <stdlib.h>

#define ARR(t) t* const
#define ARR_NEW(t, n) ((t*) __arr_new(n, sizeof(t)))
#define ARR_AT(a, i) a[i]

void *__arr_new(size_t n, size_t size);

#endif
