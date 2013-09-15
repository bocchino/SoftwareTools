#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

set OFILES $BUILD/*.o

for file in $OFILES
  echo $file
end | xargs redo-ifchange

evald libtool -static -o $argv[3] $OFILES
