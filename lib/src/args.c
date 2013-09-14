// args.c
// ----------------------------------------------------------------------
// Args implementation
// ----------------------------------------------------------------------

#include <string.h>
#include "args.h"
#include "str.h"

static size_t argc;
static const STR const *argv; 

void args_setargs(const size_t _argc, const STR const *const _argv) {
  argc = _argc;
  argv = _argv; 
}

size_t args_getarg(const size_t n, STR const arg, 
                   const size_t max_size) {
  // argv[0] is the program name
  size_t index = n + 1;
  if (index < 1 || index > argc)
    return max_size + 1;
  strncpy(arg, ARR_AT(argv, index), max_size);
  return strnlen(arg, max_size);
}
