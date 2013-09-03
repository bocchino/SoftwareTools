#include "str.h"

int main(int argc, char** argv) {
  STR s = STR_CONST("abcd");
  if (str_length(s) != 4)
    return 1;
  return 0;
}
