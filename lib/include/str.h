// str.h
// ----------------------------------------------------------------------
// String functions
// ----------------------------------------------------------------------
#ifndef STR_H
#define STR_H

#include "arr.h"

#define STR ARR(char)
#define STR_NEW(n) ARR_NEW(char,n+1)
#define STR_CONST(s) __str_const(s)
#define STR_AT(s,i) ARR_AT(s,i,char)
#define STR_C(s) (&(STR_AT(s,1)))

#define EOS 0

STR __str_const(const char *s);

// ---------------------------------------------------------------------- 
// index: find character c in string str
// ---------------------------------------------------------------------- 
size_t str_index(STR str, char c);

// ---------------------------------------------------------------------- 
// length: compute length of string 
// ---------------------------------------------------------------------- 
size_t str_length(STR str);

#endif
