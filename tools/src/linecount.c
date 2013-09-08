// ---------------------------------------------------------------------- 
// linecount: count lines in standard output
// ---------------------------------------------------------------------- 

#include "io.h"

int main(int argc, char **argv) {
  char c;
  int nl = 0;

  while ((c = getchar()) != EOF)
    if (c == NEWLINE) ++nl;
  io_putdec(nl, 1);
  putchar(NEWLINE);

  return 0;
}
