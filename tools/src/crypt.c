// ---------------------------------------------------------------------- 
// crypt: encrypt and decrypt
// ---------------------------------------------------------------------- 

#include "st.h"

#define MAXKEY 255

char key[MAXKEY+1];

MAIN (
  int c;

  size_t keylen = args_getarg(1, key, MAXKEY);
  if (keylen >= MAXKEY)
    error("usage: crypt key");
  for (size_t i = 1; GETC(c) != EOF; i = (i % keylen) + 1)
    PUTC(c ^ ARR_AT(key, i));

  return 0;
)
