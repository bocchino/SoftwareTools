// ----------------------------------------------------------------------
// io_fsize.c: test io_fsize
// ----------------------------------------------------------------------

#include "st.h"

MAIN (
  size_t size = io_fsize("src/io_fsize.in");
  if (size != 5) {
    fprintf(stderr, "size=%lx\n", size);
    return 1;
  }
  return 0;
)
