// str.c
// ----------------------------------------------------------------------
// String implementation
// ----------------------------------------------------------------------

#include "str.h"
#include <string.h>

STR __str_const(const CHR* p) {
#ifdef BOUNDS_CHECK
  const size_t length = strlen(p);
  STR s = STR_NEW(length);
  strlcpy(STR_C(s), p, length + 1);
  return s;
#else
  return p-1;
#endif
}

size_t str_index(STR str, CHR c) {
  size_t index;
  for (index = 1; STR_AT(str, index) != EOS; ++index)
    if (STR_AT(str, index) == c)
      return index;
  return 0; 
}

size_t str_length(STR str) {
  size_t length;
  for (length = 0; STR_AT(str, length + 1) != EOS; ++length) {
    // skip
  }
  return length;
}

