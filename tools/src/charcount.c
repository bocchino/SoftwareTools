// ---------------------------------------------------------------------- 
// charcount: count characters in standard output
// ---------------------------------------------------------------------- 

#include "st.h"

int main(int argc, char **argv) {
  int c;
  int nc = 0;

  while (GETC(c) != EOF)
    ++nc;
  io_putdec(nc, 1);
  PUTC(NEWLINE);

  return 0;
}
