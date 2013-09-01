#!/opt/local/bin/fish

. params.fish

if not test -e $BUILD
  doecho mkdir $BUILD
end

set -gx DEPEND {$BUILD}/depend

if not test -e $DEPEND
  doecho mkdir $DEPEND
end

for file in $CFILES
  set base (basename -s '.c' $file)
  set ofile {$BUILD}/{$base}.o
  redo-ifchange $ofile
end
