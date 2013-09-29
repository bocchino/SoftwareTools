// ----------------------------------------------------------------------
// str_scopy: test scopy
// ----------------------------------------------------------------------

#include <string.h>
#include "st.h"

char *from = "slartibartfast";
char to[MAXCHARS];
const int start = 10;

MAIN (
  str_scopy(from, 1, to, start);
  return strncmp(&ARR_AT(to, start), from, MAXCHARS);
)
