#!/usr/bin/env fish

. params.fish

if not test -e $BUILD
  evald mkdir $BUILD
end

set lib ../$BUILD

for file in $CFILES
  set base (basename -s '.c' $file)
  set ofile $BUILD/$base
  evald $CC -I../include $CCFLAGS -L$lib -lst $file -o $ofile
end
