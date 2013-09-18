// ----------------------------------------------------------------------
// error.c: error implementation
// ----------------------------------------------------------------------

#include <stdio.h>
#include "error.h"
#include "str.h"

void error_code(const STR const str, const int code) {
  remark(str);
  exit(code);
}

void error(const STR const str) {
  error_code(str, 1);
}

void remark(const STR const str) {
  fprintf(stderr, "%s\n", str);
}
