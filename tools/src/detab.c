// ---------------------------------------------------------------------- 
// detab: convert tabs to equivalent number of blanks
// ---------------------------------------------------------------------- 

#include "st.h"

int c;
size_t col = 1;
bool_t tabs[MAXLINE];

MAIN (
  line_settab(tabs);
  while (GETC(c) != EOF)
    if (c == TAB)
      do {
        PUTC(BLANK);
        ++col;
      } UNTIL (line_tabpos(col,tabs) == YES);
    else if (c == NEWLINE) {
      PUTC(NEWLINE);
      col = 1;
    }
    else {
      PUTC(c);
      ++col;
    }

  return 0;
)
