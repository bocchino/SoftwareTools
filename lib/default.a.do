#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/default.a.do: build a .a file
# ----------------------------------------------------------------------

. defs.fish

set cfiles $SRC/*.c
set -e ofiles

for cfile in $cfiles
  set base (basename -s '.c' $cfile)
  set ofiles $ofiles $BUILD/$base.o
end 

redo-ifchange $ofiles
evald libtool -static -o $argv[3] $ofiles
