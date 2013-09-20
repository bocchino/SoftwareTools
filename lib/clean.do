#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/clean.do: remove generated files
# ---------------------------------------------------------------------- 

. defs.fish

evald rm -Rf $BUILD
evald rm-tmp

redo tests/clean
