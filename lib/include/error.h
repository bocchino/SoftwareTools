// error.h
// ----------------------------------------------------------------------
// Error reporting
// ----------------------------------------------------------------------
#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include "str.h"

// ---------------------------------------------------------------------- 
// error_code -- report an error and stop with specified code
// ---------------------------------------------------------------------- 
void error_code(STR str, int code);

// ---------------------------------------------------------------------- 
// error -- report an error and stop with code 1
// ---------------------------------------------------------------------- 
void error(STR str);

#endif
