// ---------------------------------------------------------------------- 
// concat: concatenate named files onto standard output
// ---------------------------------------------------------------------- 

#include "st.h"

#define NAMESIZE MAXLINE

// ---------------------------------------------------------------------- 
// fcopy: copy file in to file out
// ---------------------------------------------------------------------- 
void fcopy(FILE *const in, FILE *const out) {
  char buf[MAXLINE];
  
  while (io_getlin(buf, in, MAXLINE) <= MAXLINE)
    io_putlin(buf, out);
}

char name[NAMESIZE];

MAIN(
  for (size_t i = 1; args_getarg(i, name, NAMESIZE) <= NAMESIZE; ++i) {
    FILE *fin = fopen(name, "r");
    if (fin == NULL)
      io_cant(name);
    fcopy(fin, stdout);
    fclose(fin);
  }

  return 0;
)
