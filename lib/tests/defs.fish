# ---------------------------------------------------------------------- 
# lib/tests/defs.fish
# ---------------------------------------------------------------------- 

redo-ifchange defs.fish

set -gx LEVEL ../..
. $LEVEL/defs.fish

set -gx SRC src
set -gx BUILD build
set -gx CFILES $SRC/*.c
