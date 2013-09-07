// error.c
// ----------------------------------------------------------------------
// Error implementation
// ----------------------------------------------------------------------

#include <stdio.h>
#include "error.h"
#include "str.h"

void error_code(STR str, int code) {
  fprintf(stderr, "%s", str);
  exit(code);
}

void error(STR str) {
  error_code(str, 1);
}
