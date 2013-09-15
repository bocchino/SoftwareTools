#include "str.h"

int main(int argc, char** argv) {
  STR s = "x@n@t";
  size_t i = 1;
  if (str_esc(s, &i) != 'x')
    return 1;
  ++i;
  if (str_esc(s, &i) != '\n')
    return 2;
  ++i;
  if (str_esc(s, &i) != '\t')
    return 3;
  return 0;
}
