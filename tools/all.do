#!/usr/bin/env fish

# ----------------------------------------------------------------------
# tools/all.do: build everything
# ----------------------------------------------------------------------

set -gx LEVEL ..
. $LEVEL/defs.fish

mkdir -p build
mkdir -p depend

set cfiles src/*.c

for file in $cfiles
  set base (basename -s '.c' $file)
  echo build/$base
end | xargs redo-ifchange
