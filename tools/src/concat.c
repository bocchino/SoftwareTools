// ---------------------------------------------------------------------- 
// concat: concatenate named files onto standard output
// ---------------------------------------------------------------------- 

#include "st.h"

char name[NAMESIZE];

MAIN(
  for (size_t i = 1; args_getarg(i, name, NAMESIZE) <= NAMESIZE; ++i) {
    FILE *fin = fopen(name, "r");
    if (fin == NULL)
      io_cant(name);
    io_fcopy(fin, stdout);
    fclose(fin);
  }

  return 0;
)
