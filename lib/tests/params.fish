redo-ifchange params.fish

set -gx LEVEL ../..
redo-ifchange $LEVEL/params.fish
. $LEVEL/params.fish

set -gx SRC src
set -gx BUILD build
set -gx CFILES $SRC/*.c
