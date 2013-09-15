// ---------------------------------------------------------------------- 
// wordcount: count words in standard input
// ---------------------------------------------------------------------- 

#include "st.h"

int main(int argc, char **argv) {
  int c;
  int wc = 0;
  bool_t inword = NO;

  while (GETC(c) != EOF) {
    if (c == BLANK || c == NEWLINE || c == TAB)
      inword = NO;
    else if (inword == NO) {
      inword = YES;
      ++wc;
    }
  }
  io_putdec(wc, 1);
  PUTC(NEWLINE);

  return 0;
}
