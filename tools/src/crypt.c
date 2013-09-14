// ---------------------------------------------------------------------- 
// crypt: encrypt and decrypt
// ---------------------------------------------------------------------- 

#include <stdlib.h>
#include "args.h"
#include "arr.h"
#include "error.h"
#include "io.h"

#define MAXKEY 255

char key[MAXKEY+1];

MAIN (
  int c;

  size_t keylen = args_getarg(1, key, MAXKEY);
  if (keylen > MAXKEY)
    error("usage: crypt key");
  for (size_t i = 1; GETC(c) != EOF; i = (i % keylen) + 1)
    PUTC(c ^ ARR_AT(key, i));

  return 0;
)
