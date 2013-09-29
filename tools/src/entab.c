// ---------------------------------------------------------------------- 
// entab: replace blanks by tabs and blanks
// ---------------------------------------------------------------------- 

#include "st.h"

int c;
size_t col = 1, newcol;
bool_t tabs[MAXLINE];

MAIN (
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
