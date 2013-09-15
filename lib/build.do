#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

if not test -e $BUILD
  evald mkdir $BUILD
end

set -gx DEPEND $BUILD/depend

if not test -e $DEPEND
  evald mkdir $DEPEND
end

for file in $CFILES
  set base (basename -s '.c' $file)
  echo $BUILD/$base.o
end | xargs redo-ifchange
