// ---------------------------------------------------------------------- 
// copy: copy input characters to output
// ---------------------------------------------------------------------- 

#include "st.h"

MAIN (
  int c;
  while (GETC(c) != EOF) {
    PUTC(c);
  }
  return 0;
)
