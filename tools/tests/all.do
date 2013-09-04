#!/opt/local/bin/fish

set -gx BUILD ../dist
redo run

set -gx BUILD ../debug
redo run
