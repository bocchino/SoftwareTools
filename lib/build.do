#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

if not test -e $BUILD
  doecho mkdir $BUILD
end

set -gx DEPEND $BUILD/depend

if not test -e $DEPEND
  doecho mkdir $DEPEND
end

for file in $CFILES
  set base (basename -s '.c' $file)
  echo $BUILD/$base.o
end | xargs redo-ifchange
