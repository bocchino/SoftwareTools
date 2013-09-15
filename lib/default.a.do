#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish

set ofiles $BUILD/*.o

for file in $ofiles
  echo $file
end | xargs redo-ifchange

evald libtool -static -o $argv[3] $ofiles
