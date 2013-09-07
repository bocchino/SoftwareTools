#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

set OFILES $BUILD/*.o

for file in $OFILES
  redo-ifchange $file
end

doecho libtool -static -o $argv[3] $OFILES
