// str.h
// ----------------------------------------------------------------------
// String functions
// ----------------------------------------------------------------------
#ifndef STR_H
#define STR_H

#include "arr.h"

#define CHR char
#define STR ARR(CHR)
#define STR_NEW(n) ARR_NEW(CHR,n+1)
#define STR_CONST(s) __str_const(s)
#define STR_AT(s,i) ARR_AT(s,i,CHR)
#define STR_C(s) (&(STR_AT(s,1)))

#define EOS 0

STR __str_const(const CHR *s);

// ---------------------------------------------------------------------- 
// index -- find character c in string str
// ---------------------------------------------------------------------- 
size_t str_index(STR str, CHR c);

// ---------------------------------------------------------------------- 
// length -- compute length of string 
// ---------------------------------------------------------------------- 
size_t str_length(STR str);

#endif
