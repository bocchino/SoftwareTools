set -gx LEVEL ../..
redo-ifchange $LEVEL/params.fish
. $LEVEL/params.fish

set SRC src
set CFILES $SRC/*.c
