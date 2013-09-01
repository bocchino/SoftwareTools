// error.c
// ----------------------------------------------------------------------
// Error implementation
// ----------------------------------------------------------------------

#include "error.h"
#include "str.h"

void error_code(STR str, int code) {
  fprintf(stderr, "%s", STR_C(str));
  exit(code);
}

void error(STR str) {
  error_code(str, 1);
}
