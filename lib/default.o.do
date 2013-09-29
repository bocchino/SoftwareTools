#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/default.o.do: build a .o file
# ---------------------------------------------------------------------- 

set -gx LEVEL ..
. $LEVEL/defs.fish

set base (basename -s '.o' $argv[1])
set cfile src/$base.c
set dfile depend/$base.d
set include include

redo-ifchange $cfile
evald $CC -MD -MF $dfile $CCFLAGS -I$include $cfile -c -o $argv[3]
redo-ifchange-d $dfile
