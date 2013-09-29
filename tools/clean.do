#!/usr/bin/env fish

# ----------------------------------------------------------------------
# tools/clean.do: remove generated files
# ----------------------------------------------------------------------

set -gx LEVEL ..
. $LEVEL/defs.fish

evald rm -Rf build depend
evald rm-tmp
evald rm-redo
