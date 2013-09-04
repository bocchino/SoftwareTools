// str.c
// ----------------------------------------------------------------------
// String implementation
// ----------------------------------------------------------------------

#include "str.h"
#include <string.h>

// ----------------------------------------------------------------------
// __str_const: make a string from a char ptr
// ----------------------------------------------------------------------
STR __str_const(char* const p) {
#ifdef DEBUG
  const size_t length = strlen(p);
  STR s = STR_NEW(length);
  strlcpy(STR_C(s), p, length + 1);
  return s;
#else
  return p-1;
#endif
}

size_t str_index(STR str, char c) {
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

size_t str_itoc(int in, STR str, size_t size) {
  STR digits = STR_CONST("0123456789");

  unsigned inabs = abs(in);
  STR_AT(str, 1) = EOS;
  size_t i = 1;
  do {
    ++i;
    unsigned d = inabs % 10;
    STR_AT(str, i) = STR_AT(digits, d + 1);
    inabs /= 10;
  } while (!(inabs == 0 || i >= size));
  if (in < 0 & i < size) {
    ++i;
    STR_AT(str, i) = MINUS;
  }
  size_t result = i - 1;
  for (size_t j = 1; j < i; ++j) {
    char k = STR_AT(str, i);
    STR_AT(str, i) = STR_AT(str, j);
    STR_AT(str, j) = k;
    --i;
  }
  return result;
}

int str_ctoi(STR in, size_t i) {
  STR digits = STR_CONST("0123456789");

  while (STR_AT(in, i) == BLANK || STR_AT(in, i) == TAB)
    ++i;
  int result = 0;
  for ( ; STR_AT(in, i) != EOS; ++i) {
    size_t d = str_index(digits, STR_AT(in, i));
    if (d == 0) break;
    result = 10 * result + d - 1; 
  }
  return result;
}

