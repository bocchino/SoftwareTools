#include <stdlib.h>
#include <string.h>
#include "str.h"

#define MAXCHARS 10

int main(int argc, char **argv) {
  STR_STACK(str, MAXCHARS);
  size_t len = str_itoc(42, str, MAXCHARS);
  if (len != 2) return 1;
  int cmp = strncmp(str,"42",MAXCHARS);
  if (cmp) return 2;
  return 0;
}
