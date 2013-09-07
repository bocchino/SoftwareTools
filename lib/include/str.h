// str.h
// ----------------------------------------------------------------------
// Operations on strings
// ----------------------------------------------------------------------
#ifndef STR_H
#define STR_H

#include "str_type.h"
#include "arr.h"

#define STR_HEAP(s,n) ARR_HEAP(s,char,n+1)
#define STR_STACK(s,n) ARR_STACK(s,char,n+1)
#define STR_AT(s,i) ARR_AT(s,i) 

#define MAXCHARS 255

#define BLANK ' '
#define EOS 0
#define MINUS '-'
#define NEWLINE '\n'
#define TAB '\t'

// ---------------------------------------------------------------------- 
// index: find character c in string str
// ---------------------------------------------------------------------- 
size_t str_index(const STR str, const char c);

// ---------------------------------------------------------------------- 
// length: compute length of string 
// ---------------------------------------------------------------------- 
size_t str_length(const STR str);

// ---------------------------------------------------------------------- 
// itoc: convert integer in to string in str 
// ---------------------------------------------------------------------- 
size_t str_itoc(const int in, STR str, const size_t size);

// ---------------------------------------------------------------------- 
// ctoi: convert string at in[i] to integer, increment i
// ---------------------------------------------------------------------- 
int str_ctoi(const STR in, size_t i);

#endif
