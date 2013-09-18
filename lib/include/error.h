// ----------------------------------------------------------------------
// error.h: error reporting
// ----------------------------------------------------------------------
#ifndef ERROR_H
#define ERROR_H

#include "str_type.h"

#define ERR -1

// ---------------------------------------------------------------------- 
// error_code: report an error and stop with specified code
// ---------------------------------------------------------------------- 
void error_code(const STR const str, const int code);

// ---------------------------------------------------------------------- 
// error: report an error and stop with code 1
// ---------------------------------------------------------------------- 
void error(const STR const str);

// ---------------------------------------------------------------------- 
// remark: write a remark to stderr
// ---------------------------------------------------------------------- 
void remark(const STR const str);

#endif
