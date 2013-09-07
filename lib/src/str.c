// str.c
// ----------------------------------------------------------------------
// String implementation
// ----------------------------------------------------------------------

#include "str.h"
#include <string.h>

size_t str_index(const STR str, const char c) {
  size_t index;
  for (index = 1; ARR_AT(str, index) != EOS; ++index)
    if (ARR_AT(str, index) == c)
      return index;
  return 0; 
}

size_t str_length(const STR str) {
  size_t length;
  for (length = 0; ARR_AT(str, length + 1) != EOS; ++length) {
    // skip
  }
  return length;
}

static const STR digits = "0123456789";

size_t str_itoc(const int in, STR str, const size_t size) {
  unsigned inabs = abs(in);
  ARR_AT(str, 1) = EOS;
  size_t i = 1;
  do {
    ++i;
    const unsigned d = inabs % 10;
    ARR_AT(str, i) = ARR_AT(digits, d + 1);
    inabs /= 10;
  } while (!(inabs == 0 || i >= size));
  if (in < 0 & i < size) {
    ++i;
    ARR_AT(str, i) = MINUS;
  }
  const size_t result = i - 1;
  for (size_t j = 1; j < i; ++j) {
    char k = ARR_AT(str, i);
    ARR_AT(str, i) = ARR_AT(str, j);
    ARR_AT(str, j) = k;
    --i;
  }
  return result;
}

int str_ctoi(const STR in, size_t i) {
  while (ARR_AT(in, i) == BLANK || ARR_AT(in, i) == TAB)
    ++i;
  int result = 0;
  for ( ; ARR_AT(in, i) != EOS; ++i) {
    const size_t d = str_index(digits, ARR_AT(in, i));
    if (d == 0) break;
    result = 10 * result + d - 1; 
  }
  return result;
}

