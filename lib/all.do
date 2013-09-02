#!/opt/local/bin/fish

set -gx BUILD dist
redo build
redo dist/libstools.a

set -gx BUILD debug
set -gx CCFLAGS -DBOUNDS_CHECK
redo build
redo debug/libstools.a
