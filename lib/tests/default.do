#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/default.do: build an executable
# ---------------------------------------------------------------------- 

set -gx LEVEL ../../
. $LEVEL/defs.fish

make-exec $argv
