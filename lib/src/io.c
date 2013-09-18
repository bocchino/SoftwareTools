// ----------------------------------------------------------------------
// io.c: I/O implementation
// ----------------------------------------------------------------------

#include "io.h"

void io_putdec(const int n, const size_t w) {
  STR_STACK(chars, MAXCHARS);

  size_t nd = str_itoc(n, chars, MAXCHARS); 
  for (size_t i = nd + 1; i <= w; ++i)
    putchar(BLANK);
  for (size_t i = 1; i <= nd; ++i)
    putchar(STR_AT(chars,i));
}

size_t getlin(STR const line, FILE *file, const size_t maxlen) {
  const STR const result = fgets(line, maxlen, file);
  if (result != NULL)
    return str_length(line); 
  return maxlen + 1;
}
