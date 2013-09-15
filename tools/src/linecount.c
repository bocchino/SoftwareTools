// ---------------------------------------------------------------------- 
// linecount: count lines in standard output
// ---------------------------------------------------------------------- 

#include "st.h"

int main(int argc, char **argv) {
  int c;
  int nl = 0;

  while (GETC(c) != EOF)
    if (c == NEWLINE) ++nl;
  io_putdec(nl, 1);
  PUTC(NEWLINE);

  return 0;
}
