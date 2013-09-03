#!/opt/local/bin/fish

redo-ifchange ../params.fish ../functions.fish

. ../params.fish
. ../functions.fish

echoerr 'building tests in '$BUILD

if not test -e $BUILD
  eval mkdir $BUILD
end

set LIB ../{$BUILD}

for file in $CFILES
  set base (basename -s '.c' $file)
  set ofile {$BUILD}/{$base}
  eval $CC -I../include $CCFLAGS -L{$LIB} -lst $file -o $ofile
end
