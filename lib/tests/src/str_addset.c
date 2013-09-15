#include "st.h"
#include <string.h>

char s[4] = { 'a', 'a', 'a' ,'a' };

int main(int argc, char** argv) {
  size_t i = 3;
  if (str_addset('b', s, &i, 4) == NO)
    return 1;
  if (strncmp(s, "aaba", 4))
    return 2;
  if (str_addset('b', s, &i, 2) == YES)
    return 3;
  return 0;
}
