#!/opt/local/bin/fish

set -gx BUILD dist
set -e CCFLAGS
redo build
redo dist/libst.a

set -gx BUILD debug
set -gx CCFLAGS -DBOUNDS_CHECK
redo build
redo debug/libst.a
