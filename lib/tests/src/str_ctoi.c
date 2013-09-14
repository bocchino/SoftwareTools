#include <stdio.h>
#include "str.h"

int main(int argc, char **argv) {
  size_t i = 4;
  const int n = str_ctoi("***42***", &i);
  if (n != 42) {
    fprintf(stderr, "n=%d\n", n);
    return 1;
  }
  if (i != 6) {
    fprintf(stderr, "i=%ld\n", i);
    return 2;
  }
  return 0;
}
