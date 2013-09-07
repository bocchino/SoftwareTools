#include <stdio.h>
#include "str.h"

int main(int argc, char **argv) {
  const int i = str_ctoi("***42***", 4);
  if (i != 42) return 1;
  return 0;
}
