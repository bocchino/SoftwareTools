#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

echoerr 'building tests'

if not test -e $BUILD
  eval mkdir $BUILD
end

set LIB ../$BUILD

for file in $CFILES
  set base (basename -s '.c' $file)
  set ofile $BUILD/$base
  evald $CC -I../include $CCFLAGS -L$LIB -lst $file -o $ofile
end
