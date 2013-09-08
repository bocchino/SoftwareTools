// ---------------------------------------------------------------------- 
// charcount: count characters in standard output
// ---------------------------------------------------------------------- 

#include "io.h"

int main(int argc, char **argv) {
  char c;
  int nc = 0;

  while (GETC(c) != EOF)
    ++nc;
  io_putdec(nc, 1);
  PUTC(NEWLINE);

  return 0;
}
