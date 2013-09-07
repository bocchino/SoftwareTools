// str.h
// ----------------------------------------------------------------------
// String functions
// ----------------------------------------------------------------------
#ifndef STR_H
#define STR_H

#include "arr.h"

#define STR ARR(char)
#define STR_HEAP(s,n) ARR_HEAP(s,char,n+1)
#define STR_STACK(s,n) ARR_STACK(s,char,n+1)
#define STR_AT(s,i) ARR_AT(s,i) 

#define BLANK ' '
#define EOS 0
#define MINUS '-'
#define TAB '\t'

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
