// ---------------------------------------------------------------------- 
// charcount: count characters in standard output
// ---------------------------------------------------------------------- 

#include "io.h"

int main(int argc, char **argv) {
  char c;
  int nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
  }
  io_putdec(nc, 1);
  putchar(NEWLINE);
  return 0;
}
