#!/opt/local/bin/fish

redo-ifchange ../params.fish params.fish

. ../params.fish
. params.fish

if not test -e $BUILD
  doecho mkdir $BUILD
end

set -gx DEPEND $BUILD/depend

if not test -e $DEPEND
  doecho mkdir $DEPEND
end

for file in $CFILES
  set -gx base (basename -s '.c' $file)
  redo-ifchange $BUILD/$base
end
