#!/opt/local/bin/fish

set -gx BUILD dist
redo build
redo run

set -gx BUILD debug
redo build
redo run
