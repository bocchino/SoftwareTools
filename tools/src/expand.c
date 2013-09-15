// ---------------------------------------------------------------------- 
// expand: uncompress standard input
// ---------------------------------------------------------------------- 

#include "compress.h"

MAIN (
  int c;
  int code;

  while (GETC(code) != EOF) {
    if (code == RCODE) { 
      // expand repetition
      if (GETC(c) == EOF)
        break;
      if (GETC(code) == EOF)
        break;
      for ( ; code > 0; --code)
        PUTC(c);
    }
    else {
      // expand chunk
      for ( ; code > 0; --code) {
        if (GETC(c) == EOF)
          break;
        PUTC(c);
      }
      if (c == EOF)
        break;
    }
  }

  return 0;
)
