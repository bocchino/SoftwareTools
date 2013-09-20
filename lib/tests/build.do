#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/build.do: build everything
# ----------------------------------------------------------------------

. defs.fish

mkdir -p $BUILD

set lib ../$BUILD

for file in $CFILES
  set base (basename -s '.c' $file)
  set ofile $BUILD/$base
  evald $CC -I../include $CCFLAGS -L$lib -lst $file -o $ofile
end
