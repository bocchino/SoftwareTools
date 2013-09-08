// line.h
// ----------------------------------------------------------------------
// Operations on lines of text
// ----------------------------------------------------------------------
#ifndef LINE_H
#define LINE_H

#include "arr.h"
#include "bool_type.h"

#define MAXLINE 80

// ---------------------------------------------------------------------- 
// tabpos: return YES if col is a tab stop
// ---------------------------------------------------------------------- 
bool_t line_tabpos(const size_t col, const ARR(bool_t) tabs);

// ---------------------------------------------------------------------- 
// settab: set initial tab stops
// ---------------------------------------------------------------------- 
void line_settab(ARR(bool_t) tabs);

#endif
