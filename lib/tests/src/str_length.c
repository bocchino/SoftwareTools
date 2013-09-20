// ----------------------------------------------------------------------
// str_length.c: test str_length
// ----------------------------------------------------------------------

#include "str.h"

int main(int argc, char** argv) {
  STR s = "abcd";
  if (str_length(s) != 4)
    return 1;
  return 0;
}
