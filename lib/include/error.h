// error.h
// ----------------------------------------------------------------------
// Error reporting
// ----------------------------------------------------------------------
#ifndef ERROR_H
#define ERROR_H

#include "str_type.h"

// ---------------------------------------------------------------------- 
// error_code: report an error and stop with specified code
// ---------------------------------------------------------------------- 
void error_code(const STR str, const int code);

// ---------------------------------------------------------------------- 
// error: report an error and stop with code 1
// ---------------------------------------------------------------------- 
void error(const STR str);

#endif
