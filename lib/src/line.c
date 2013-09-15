// ----------------------------------------------------------------------
// line.c: line implementation
// ----------------------------------------------------------------------

#include "line.h"

bool_t line_tabpos(const size_t col, const ARR(bool_t) tabs) {
  if (col > MAXLINE)
    return YES;
  return ARR_AT(tabs, col);
}

void line_settab(ARR(bool_t) tabs) {
  for (size_t i = 1; i <= MAXLINE; ++i)
    if (i % 8 == 1)
      ARR_AT(tabs, i) = YES;
    else
      ARR_AT(tabs, i) = NO;
}
