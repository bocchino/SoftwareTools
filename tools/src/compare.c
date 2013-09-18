// ---------------------------------------------------------------------- 
// compare: compare two files for equality
// ---------------------------------------------------------------------- 

#include "st.h"

char arg1[MAXLINE], arg2[MAXLINE], line1[MAXLINE], line2[MAXLINE];

// ---------------------------------------------------------------------- 
// cant: print "can't open" message to stderr
// ---------------------------------------------------------------------- 
void cant(const STR const str) {
  fprintf(stderr, "can't open %s", str);
  exit(1);
}

// ---------------------------------------------------------------------- 
// difmsg: print line numbers and differing lines
// ---------------------------------------------------------------------- 
void difmsg(size_t lineno, const STR const line1, 
    const STR const line2) {
  io_putdec(lineno, 5);
  PUTC(NEWLINE);
  putlin(line1, stdout);
  putlin(line2, stdout);
}
  
size_t m1, m2;

MAIN (
  if (args_getarg(1, arg1, MAXLINE) > MAXLINE
    || args_getarg(2, arg2, MAXLINE) > MAXLINE)
    error("usage: compare file1 file2.");
  FILE *infil1 = fopen(arg1, "r");
  if (infil1 == NULL)
    cant(arg1);
  FILE *infil2 = fopen(arg2, "r");
  if (infil2 == NULL)
    cant(arg2);
  size_t lineno = 0;
  REPEAT {
    m1 = getlin(line1, infil1, MAXLINE);
    m2 = getlin(line2, infil2, MAXLINE);
    if (m1 > MAXLINE || m2 > MAXLINE)
      break;
    ++lineno;
    if (str_equal(line1, line2) == NO)
      difmsg(lineno, line1, line2);
  }
  if (m1 > MAXLINE && m2 <= MAXLINE)
    remark("eof on file 1.");
  else if (m2 > MAXLINE && m1 <= MAXLINE)
    remark("eof on file 2.");
)
