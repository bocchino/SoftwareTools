// ---------------------------------------------------------------------- 
// archive: file maintainer
// ---------------------------------------------------------------------- 

#include "st.h"

STR_BUF(aname, NAMESIZE);
STR_BUF(command, 2);

void help() {
  fprintf(stderr, "%s\n", "usage: archive {dptux} archname [files].");
  exit(1);
}

MAIN(
  if (args_getarg(1, command, 2) >= 2
    || args_getarg(2, aname, NAMESIZE) >= NAMESIZE)
    help();

  return 0;
)
