#!/usr/bin/env fish

# ----------------------------------------------------------------------
# tools/default.do: build an executable
# ---------------------------------------------------------------------- 

. defs.fish

set base (basename $argv[1])
set cfile $SRC/$base.c
set dfile $DEPEND/$base.d
set ofile $BUILD/$base
set lib ../lib/$BUILD
set include -Iinclude -I../lib/include

redo-ifchange $cfile $lib/libst.a
evald $CC -MD -MF $dfile $CCFLAGS $include -L$lib -lst $cfile -o $argv[3]
redo-ifchange-d $dfile
