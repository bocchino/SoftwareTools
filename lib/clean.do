#!/opt/local/bin/fish

. params.fish

doecho rm -Rf dist debug

redo tests/clean
