#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish


set base (basename $argv[1])
set cfile src/$base.c
set dfile $DEPEND/$base.d
set ofile $BUILD/$base
set lib ../lib/$BUILD
set include -Iinclude -I../lib/include

redo-ifchange $cfile $lib/libst.a

evald $CC -MD -MF $dfile $CCFLAGS $include -L$lib -lst $cfile -o $argv[3]
read deps < $dfile
set deps (echo $deps | tr '\n' ' ')
set deps (echo $deps | sed -e 's/^.*: *//' -e 's/\\\\//g')
echo $deps | xargs redo-ifchange
