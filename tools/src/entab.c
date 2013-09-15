// ---------------------------------------------------------------------- 
// entab: replace blanks by tabs and blanks
// ---------------------------------------------------------------------- 

#include "st.h"

MAIN (
  int c;
  size_t col = 1;
  size_t newcol;
  ARR_STACK(tabs,bool_t,MAXLINE);

  line_settab(tabs);
  REPEAT {
    newcol = col;
    while (GETC(c) == BLANK) { 
      // collect blanks
      ++newcol;
      if (line_tabpos(newcol, tabs) == YES) {
        PUTC(TAB);
        col = newcol;
      }
    }
    for ( ; col < newcol; ++col)
      // output leftover blanks 
      PUTC(BLANK);
    if (c == EOF)
      break;
    PUTC(c);
    if (c == NEWLINE)
      col = 1;
    else
      ++col;
  }

  return 0;
)
