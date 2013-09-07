#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

redo build
redo run
