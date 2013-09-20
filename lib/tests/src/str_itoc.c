// ----------------------------------------------------------------------
// str_itoc.c: test str_itoc
// ----------------------------------------------------------------------

#include <string.h>
#include "str.h"

int main(int argc, char **argv) {
  STR_STACK(str, MAXCHARS);
  size_t len = str_itoc(42, str, MAXCHARS);
  if (len != 2) return 1;
  int cmp = strncmp(str,"42",MAXCHARS);
  if (cmp) return 2;
  return 0;
}
