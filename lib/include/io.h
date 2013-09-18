// ----------------------------------------------------------------------
// io.h: input and output
// ----------------------------------------------------------------------
#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "str.h"

#define GETC(c) (c = getchar())
#define PUTC(c) putchar(c)

// ---------------------------------------------------------------------- 
// putdec: put decimal integer n in field width >= w
// ---------------------------------------------------------------------- 
void io_putdec(const int n, const size_t w);

// ---------------------------------------------------------------------- 
// getlin: get a line of text from a file
// ---------------------------------------------------------------------- 
size_t getlin(STR const line, FILE *file, const size_t maxlen); 

#define putlin(s, stream) fputs(s, stream)

#endif
