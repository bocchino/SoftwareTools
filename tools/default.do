#!/usr/bin/env fish

# ----------------------------------------------------------------------
# tools/default.do: build an executable
# ---------------------------------------------------------------------- 

set -gx LEVEL ..
. $LEVEL/defs.fish

make-exec $argv
