#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish

mkdir -p $BUILD
mkdir -p $DEPEND

for file in $CFILES
  set base (basename -s '.c' $file)
  echo $BUILD/$base
end | xargs redo-ifchange
