# ---------------------------------------------------------------------- 
# lib/defs.fish
# ---------------------------------------------------------------------- 

redo-ifchange defs.fish

set -gx LEVEL ..
. $LEVEL/defs.fish

set -gx INCLUDE include
set -gx SRC src
set -gx CFILES $SRC/*.c
set -gx HFILES $INCLUDE/*.h
set -gx BUILD build
set -gx DEPEND $BUILD/depend
