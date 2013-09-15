// args.h
// ----------------------------------------------------------------------
// Command-line arguments
// ----------------------------------------------------------------------
#ifndef ARGS_H
#define ARGS_H

#include <stdlib.h>

#include "str_type.h"

// ---------------------------------------------------------------------- 
// setargs: set arguments
// ---------------------------------------------------------------------- 
void args_setargs(const size_t argc, const STR const *const argv);

// ---------------------------------------------------------------------- 
// getarg: get an argument
// ---------------------------------------------------------------------- 
size_t args_getarg(const size_t n, STR const arg, const size_t max_size);

#define MAIN(X) \
  int main(const int argc, const STR const *const argv) { \
    args_setargs(argc, argv); \
    X \
  }

#endif
