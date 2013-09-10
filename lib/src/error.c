// error.c
// ----------------------------------------------------------------------
// Error implementation
// ----------------------------------------------------------------------

#include <stdio.h>
#include "error.h"
#include "str.h"

void error_code(const STR str, const int code) {
  fprintf(stderr, "%s\n", str);
  exit(code);
}

void error(const STR str) {
  error_code(str, 1);
}
