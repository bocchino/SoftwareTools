#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

doecho rm -Rf $BUILD

redo tests/clean
