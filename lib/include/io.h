// ----------------------------------------------------------------------
// io.h: input and output
// ----------------------------------------------------------------------
#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "str.h"
#include "line.h"

#define GETC(c) (c = getchar())
#define GETCH(c, fd) (c = fgetc(fd))
#define PUTC(c) putchar(c)
#define PUTCH(c, fd) fputc(c, fd) 
#define NAMESIZE MAXLINE

// ---------------------------------------------------------------------- 
// putdec: put decimal integer n in field width >= w
// ---------------------------------------------------------------------- 
void io_putdec(const int n, const size_t w);

// ---------------------------------------------------------------------- 
// getlin: get a line of text from a file
// ---------------------------------------------------------------------- 
size_t io_getlin(STR const line, FILE *file, const size_t maxlen); 

#define io_putlin(s, stream) fputs(s, stream)

// ---------------------------------------------------------------------- 
// cant: print "can't open" message to stderr
// ---------------------------------------------------------------------- 
void io_cant(const STR const str);

// ---------------------------------------------------------------------- 
// fcopy: copy file in to file out
// ---------------------------------------------------------------------- 
void io_fcopy(FILE *const in, FILE *const out);

// ---------------------------------------------------------------------- 
// fsize: size of file in characters
// ---------------------------------------------------------------------- 
size_t io_fsize(const STR const name);

// ---------------------------------------------------------------------- 
// fskip: skip n characters on file fd
// ---------------------------------------------------------------------- 
void io_fskip(FILE *fd, const size_t n);

#endif
