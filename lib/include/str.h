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
#define STR_C(s) (&(ARR_AT(s,1)))

#define BLANK ' '
#define EOS 0
#define MINUS '-'
#define TAB '\t'

STR __str_const(char * const s);

// ---------------------------------------------------------------------- 
// index: find character c in string str
// ---------------------------------------------------------------------- 
size_t str_index(STR str, char c);

// ---------------------------------------------------------------------- 
// length: compute length of string 
// ---------------------------------------------------------------------- 
size_t str_length(STR str);

// ---------------------------------------------------------------------- 
// itoc: convert integer in to string in str 
// ---------------------------------------------------------------------- 
size_t str_itoc(int in, STR str, size_t size);

// ---------------------------------------------------------------------- 
// ctoi: convert string at in[i] to integer, increment i
// ---------------------------------------------------------------------- 
int str_ctoi(STR in, size_t i);

#endif
