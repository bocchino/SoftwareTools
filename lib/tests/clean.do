#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/clean.do: remove generated files
# ---------------------------------------------------------------------- 

set -gx LEVEL ../../
. $LEVEL/defs.fish

evald rm -Rf build depend
evald rm-tmp
