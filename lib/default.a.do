#!/usr/bin/env fish

. params.fish

set cfiles $SRC/*.c
set -e ofiles

for cfile in $cfiles
  set base (basename -s '.c' $cfile)
  set ofiles $ofiles $BUILD/$base.o
end 

redo-ifchange $ofiles
evald libtool -static -o $argv[3] $ofiles
