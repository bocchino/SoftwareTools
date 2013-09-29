#!/usr/bin/env fish

# ----------------------------------------------------------------------
# tools/tests/clean.do: remove generated files
# ----------------------------------------------------------------------

set -gx LEVEL ../../
. $LEVEL/defs.fish

evald rm-tmp
