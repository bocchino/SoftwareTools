#!/opt/local/bin/fish

set -gx BUILD dist
redo build

set -gx BUILD debug
set -gx CCFLAGS -DBOUNDS_CHECK
redo build
