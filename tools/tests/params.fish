redo-ifchange params.fish

set -gx LEVEL ../..
redo-ifchange $LEVEL/params.fish
. $LEVEL/params.fish
. $LEVEL/functions.fish
