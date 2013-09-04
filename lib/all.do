#!/opt/local/bin/fish

set -gx BUILD dist
set -gx CCFLAGS -std=c99
redo build
redo dist/libst.a

set -gx BUILD debug
set -gx CCFLAGS -std=c99 -DDEBUG
redo build
redo debug/libst.a
