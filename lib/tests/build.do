#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/build.do: build everything
# ----------------------------------------------------------------------

set -gx LEVEL ../../
. $LEVEL/defs.fish

mkdir -p build
mkdir -p depend

set cfiles src/*.c

for file in $cfiles
  set base (basename -s '.c' $file)
  echo build/$base
end | xargs redo-ifchange
