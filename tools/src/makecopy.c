// ---------------------------------------------------------------------- 
// makecopy: copy one file to another
// ---------------------------------------------------------------------- 

#include "st.h"

char iname[NAMESIZE], oname[NAMESIZE];
FILE *fin, *fout;

MAIN(
  if (args_getarg(1, iname, NAMESIZE) > NAMESIZE
   || args_getarg(2, oname, NAMESIZE) > NAMESIZE)
    error("usage: makecopy input output.");
  fin = fopen(iname, "r");
  if (fin == NULL)
    io_cant(iname);
  fout = fopen(oname, "w");
  if (fout == NULL)
    io_cant(oname);
  io_fcopy(fin, fout);
  fclose(fin);
  fclose(fout);

  return 0;
)
