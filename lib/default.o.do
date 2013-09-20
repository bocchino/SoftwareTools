#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/default.o.do: build a .o file
# ---------------------------------------------------------------------- 

. defs.fish

set base (basename -s '.o' $argv[1])
set cfile $SRC/$base.c
set dfile $DEPEND/$base.d

redo-ifchange $cfile
evald $CC -MD -MF $dfile $CCFLAGS -I$INCLUDE $cfile -c -o $argv[3]
redo-ifchange-d $dfile
