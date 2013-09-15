#!/opt/local/bin/fish

. params.fish

redo-ifchange all

redo lib/test
redo tools/test
