#!/usr/bin/env fish

# ----------------------------------------------------------------------
# clean.do: remove generated files
# ---------------------------------------------------------------------- 

. defs.fish

evald rm -Rf $BUILD
evald rm-tmp
