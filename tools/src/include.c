// ---------------------------------------------------------------------- 
// include: replace 'include file' by contents of file
// ---------------------------------------------------------------------- 

#include "st.h"

#define NFILES 10

// ---------------------------------------------------------------------- 
// getwrd: get non-blank word from in[*i] into out; increment *i
// ---------------------------------------------------------------------- 
size_t getwrd(const STR const in, size_t *i, STR const out) {
  while (STR_AT(in, *i) == BLANK || STR_AT(in, *i) == TAB)
    ++*i;
  size_t j = 1;
  while (STR_AT(in, *i) != EOS && STR_AT(in, *i) != BLANK
      && STR_AT(in, *i) != TAB && STR_AT(in, *i) != NEWLINE) {
    STR_AT(out, j) = STR_AT(in, *i);
    ++*i;
    ++j;
  }
  STR_AT(out, j) = EOS;
  return j - 1;
}

char line[MAXLINE], str[MAXLINE];
FILE *infile[NFILES];
STR incl = "include";

MAIN(
  ARR_AT(infile, 1) = stdin;

  for (size_t level = 1; level > 0; --level) {
    while (io_getlin(line, ARR_AT(infile, level), MAXLINE) <= MAXLINE) {
      size_t loc = 1;
      getwrd(line, &loc, str);
      if (str_equal(str, incl) == NO)
        io_putlin(line, stdout);
      else {
        ++level;
        if (level > NFILES)
          error("includes nested too deeply.");
        getwrd(line, &loc, str);
        ARR_AT(infile, level) = fopen(str, "r");
        if (ARR_AT(infile, level) == NULL)
          io_cant(str);
      }
    } 
    if (level > 1)
      fclose(ARR_AT(infile, level));
  }

  return 0;
)
