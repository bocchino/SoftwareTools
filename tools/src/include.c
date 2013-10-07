// ---------------------------------------------------------------------- 
// include: replace 'include file' by contents of file
// ---------------------------------------------------------------------- 

#include "st.h"

#define NFILES 10

char line[MAXLINE], str[MAXLINE];
FILE *infile[NFILES];
STR incl = "include";

MAIN(
  ARR_AT(infile, 1) = stdin;

  for (size_t level = 1; level > 0; --level) {
    while (io_getlin(line, ARR_AT(infile, level), MAXLINE) < MAXLINE) {
      size_t loc = 1;
      str_getwrd(line, &loc, str);
      if (str_equal(str, incl) == NO)
        io_putlin(line, stdout);
      else {
        ++level;
        if (level > NFILES)
          error("includes nested too deeply.");
        str_getwrd(line, &loc, str);
        ARR_AT(infile, level) = io_open(str, READ);
        if (ARR_AT(infile, level) == NULL)
          io_cant(str);
      }
    } 
    if (level > 1)
      fclose(ARR_AT(infile, level));
  }

  return 0;
)
