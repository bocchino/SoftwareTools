#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish


set base (basename $argv[1])
set cfile src/$base.c
set dfile $DEPEND/$base.d
set ofile $BUILD/$base
set LIB ../lib/$BUILD
set INCLUDE -Iinclude -I../lib/include

redo-ifchange $cfile $LIB/libst.a

evald $CC -MD -MF $dfile $CCFLAGS $INCLUDE -L$LIB -lst $cfile -o $argv[3]
read deps < $dfile
set deps (echo $deps | tr '\n' ' ')
set deps (echo $deps | sed -e 's/^.*: *//' -e 's/\\\\//g')
echo $deps | xargs redo-ifchange
