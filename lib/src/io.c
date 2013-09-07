// error.c
// ----------------------------------------------------------------------
// Error implementation
// ----------------------------------------------------------------------

#include "io.h"

void putdec(const int n, const size_t w) {
  STR_STACK(chars, MAXCHARS);

  size_t nd = str_itoc(n, chars, MAXCHARS); 
  for (size_t i = nd + 1; i <= w; ++i)
    putchar(BLANK);
  for (size_t i = 1; i <= nd; ++i)
    putchar(STR_AT(chars,i));
}
