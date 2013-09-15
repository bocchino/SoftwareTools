// ----------------------------------------------------------------------
// io.h: input and output
// ----------------------------------------------------------------------
#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "str.h"

#define GETC(c) (c = getchar())
#define PUTC(c) putchar(c)

// ---------------------------------------------------------------------- 
// putdec: put decimal integer n in field width >= w
// ---------------------------------------------------------------------- 
void io_putdec(const int n, const size_t w);

#endif
