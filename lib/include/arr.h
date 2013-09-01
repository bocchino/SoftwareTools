// arr.h
// ----------------------------------------------------------------------
// Array types
// ----------------------------------------------------------------------

#ifndef ARR_H
#define ARR_H

#include <stdlib.h>

#define ARR(t) const t*
#define ARR_NEW(t, n) ((t*) __arr_new(n, sizeof(t)))
#ifdef BOUNDS_CHECK
#define ARR_AT(a, i, t) (*((t*) __arr_at(a, i, sizeof(t))))
#define ARR_LEN(a) (*((const size_t*) a))
#else
#define ARR_AT(a, i, t) a[i]
#endif

void *__arr_new(size_t n, size_t size);

#ifdef BOUNDS_CHECK
void *__arr_at(const void *a, size_t i, size_t tsize);
#endif

#endif
