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
  return p-1;
}

size_t str_index(STR str, char c) {
  size_t index;
  for (index = 1; ARR_AT(str, index) != EOS; ++index)
    if (ARR_AT(str, index) == c)
      return index;
  return 0; 
}

size_t str_length(STR str) {
  size_t length;
  for (length = 0; ARR_AT(str, length + 1) != EOS; ++length) {
    // skip
  }
  return length;
}

size_t str_itoc(int in, STR str, size_t size) {
  STR digits = STR_CONST("0123456789");

  unsigned inabs = abs(in);
  ARR_AT(str, 1) = EOS;
  size_t i = 1;
  do {
    ++i;
    unsigned d = inabs % 10;
    ARR_AT(str, i) = ARR_AT(digits, d + 1);
    inabs /= 10;
  } while (!(inabs == 0 || i >= size));
  if (in < 0 & i < size) {
    ++i;
    ARR_AT(str, i) = MINUS;
  }
  size_t result = i - 1;
  for (size_t j = 1; j < i; ++j) {
    char k = ARR_AT(str, i);
    ARR_AT(str, i) = ARR_AT(str, j);
    ARR_AT(str, j) = k;
    --i;
  }
  return result;
}

int str_ctoi(STR in, size_t i) {
  STR digits = STR_CONST("0123456789");

  while (ARR_AT(in, i) == BLANK || ARR_AT(in, i) == TAB)
    ++i;
  int result = 0;
  for ( ; ARR_AT(in, i) != EOS; ++i) {
    size_t d = str_index(digits, ARR_AT(in, i));
    if (d == 0) break;
    result = 10 * result + d - 1; 
  }
  return result;
}

