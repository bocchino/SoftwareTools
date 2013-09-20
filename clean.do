#!/usr/bin/env fish

# ----------------------------------------------------------------------
# clean.do: remove generated files
# ----------------------------------------------------------------------

set -gx LEVEL .
. $LEVEL/defs.fish

redo lib/clean
redo tools/clean
evald rm-tmp
evald rm-redo
