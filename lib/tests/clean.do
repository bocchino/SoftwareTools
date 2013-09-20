#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/clean.do: remove generated files
# ---------------------------------------------------------------------- 

. defs.fish

evald rm -Rf $BUILD
evald rm-tmp
