SoftwareTools
=============

*Copyright (c) 2013 by Robert L. Bocchino Jr.*

## 1. Introduction ##

This is an implementation in C of the programs in the classic text *Software
Tools* by Brian W. Kernighan and P.J. Plauger (Addison-Wesley 1976). Mostly
this is for my own edification, but it may be interesting or useful to others
as well. So far I have implemented the programs from the first two chapters.

## 2. Code Organization and Style ##

### Organization ###

The code lives in two directories:

1. `lib` contains code that is (or potentially could be) reused across
   different tools.

2. `tools` contains the tools themselves.

I used my judgment to decide which code to put where. I may change my mind as
I work through more of the book.

### Style ###

The code is not idiomatic C; instead, it attempts to mimic the style of the
programs in the book (written in a Fortran dialect called Rational Fortran, or
Ratfor) as closely as possible, while writing in C.  For example:

1. Arrays are indexed from 1, not 0.

2. Pointers are used only where necessary to mimic the behavior of global
   variables in the original code.

3. Control constructs are generally similar to C, but several (`repeat`,
   `until`, etc.) are different.

I have used C macros to assist the translation process.

Personally I am enjoying the one-indexed arrays and lack of pointers. I find
this coding style more natural for programs that don't require pointer
manipulation.

## 3. Building and Running ##

### Dependencies ###

To build and run the code, you'll need to install the following software:

1. A UNIX command line and standard UNIX tools.

2. The [fish shell](http://fishshell.com).

3. The [redo](https://github.com/apenwarr/redo) build tool.

If you are on a Mac and using [MacPorts](http://www.macports.org), you can get
both by issuing the commands

    sudo port install fish
    sudo port install redo

on the command line.

### Compiler ###

The build system assumes you have [clang](http://clang.llvm.org) installed on
your system. If you don't (or you'd rather use gcc), first edit `params.fish`
in the top-level directory to replace `clang` with `gcc`.

### Building ###

To build everything, issue the command `redo` from the top-level directory. You
can also issue `redo` in the `lib` or `tools` directory to build just the
library or the tools. However, you have to build the library before building
the tools. 

To remove the generated files, issue the command `redo clean`.

### Running ###

To run the tests, issue the command `redo test` from the top-level directory.
You can also issue `redo test` in the `lib` or `tools` directory to run just
the library or tools tests.

