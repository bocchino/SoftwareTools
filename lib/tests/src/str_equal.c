// ----------------------------------------------------------------------
// str_equal.c: test str_equal
// ----------------------------------------------------------------------

#include "str.h"

int main(int argc, char** argv) {
  STR s1 = "abcd";
  STR s2 = "1234";
  if (str_equal(s1,s1) == NO)
    return 1;
  if (str_equal(s1,s2) == YES)
    return 2;
  return 0;
}
