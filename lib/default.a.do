#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/default.a.do: build a .a file
# ----------------------------------------------------------------------

set -gx LEVEL ..
. $LEVEL/defs.fish

set cfiles src/*.c
set -e ofiles

for cfile in $cfiles
  set base (basename -s '.c' $cfile)
  set ofiles $ofiles build/$base.o
end 

redo-ifchange $ofiles
evald libtool -static -o $argv[3] $ofiles
