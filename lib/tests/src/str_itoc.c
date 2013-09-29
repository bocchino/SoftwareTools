// ----------------------------------------------------------------------
// str_itoc.c: test str_itoc
// ----------------------------------------------------------------------

#include <string.h>
#include "str.h"

char str[MAXCHARS];

int main(int argc, char **argv) {
  size_t len = str_itoc(42, str, MAXCHARS);
  if (len != 2) return 1;
  int cmp = strncmp(str,"42",MAXCHARS);
  if (cmp) return 2;
  return 0;
}
