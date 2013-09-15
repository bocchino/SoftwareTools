// ---------------------------------------------------------------------- 
// compress: compress standard input
// ---------------------------------------------------------------------- 

#include "compress.h"

size_t nsave = 0;
char buf[MAXCHUNK];

// ----------------------------------------------------------------------
// putbuf: output buf[1]...buf[nsave], clear nsave
// ----------------------------------------------------------------------
void putbuf() {
  if (nsave > 0) {
    PUTC(nsave);
    for (size_t i = 1; i <= nsave; ++i) {
      PUTC(STR_AT(buf, i));
    }
  }
  nsave = 0;
}

MAIN (
  int c;
  int lastc;
  size_t nrep;

  for (GETC(lastc); lastc != EOF; lastc = c) {
    for (nrep = 1; GETC(c) == lastc; ++nrep)
      if (nrep >= MAXCHUNK) 
        // count repetitions
        break;
    if (nrep < THRESH)
      for ( ; nrep > 0; --nrep) {
        ++nsave;
        STR_AT(buf, nsave) = lastc;
        if (nsave >= MAXCHUNK)
          putbuf();
      }
    else {
      putbuf();
      PUTC(RCODE);
      PUTC(lastc);
      PUTC(nrep);
    }
  }
  // last chunk  
  putbuf(); 

  return 0;
)
