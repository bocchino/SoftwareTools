#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish

set base (basename -s '.o' $argv[1])
set cfile $SRC/$base.c
set dfile $DEPEND/$base.d

redo-ifchange $cfile
evald $CC -MD -MF $dfile $CCFLAGS -I$INCLUDE $cfile -c -o $argv[3]
tr '\n' ' ' < $dfile | read deps
set deps (echo $deps | sed -e 's/^.*: *//' -e 's/\\\\//g')
echo $deps | xargs redo-ifchange
