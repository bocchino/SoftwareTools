// ---------------------------------------------------------------------- 
// copy: copy input characters to output
// ---------------------------------------------------------------------- 

#include "st.h"

int main(int argc, char **argv) {
  int c;
  while (GETC(c) != EOF) {
    PUTC(c);
  }
  return 0;
}
