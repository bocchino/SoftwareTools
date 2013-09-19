redo-ifchange params.fish

set -gx LEVEL ..
redo-ifchange $LEVEL/params.fish
. $LEVEL/params.fish

set -gx INCLUDE include
set -gx SRC src
set -gx CFILES $SRC/*.c
set -gx HFILES $INCLUDE/*.h
set -gx BUILD build
set -gx DEPEND $BUILD/depend
