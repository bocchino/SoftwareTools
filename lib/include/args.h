// args.h
// ----------------------------------------------------------------------
// Command-line arguments
// ----------------------------------------------------------------------
#ifndef ARGS_H
#define ARGS_H

#include "str_type.h"

// ---------------------------------------------------------------------- 
// setargs: set arguments
// ---------------------------------------------------------------------- 
void args_setargs(const size_t argc, char *const *const argv);

// ---------------------------------------------------------------------- 
// getarg: get an argument
// ---------------------------------------------------------------------- 
size_t args_getarg(const size_t n, STR const arg, const size_t max_size);

#endif
