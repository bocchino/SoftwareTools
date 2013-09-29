#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/clean.do: remove generated files
# ---------------------------------------------------------------------- 

set -gx LEVEL ..
. $LEVEL/defs.fish

evald rm -Rf build depend
evald rm-tmp

redo tests/clean
