#!/usr/bin/env fish

# ----------------------------------------------------------------------
# clean.do: remove generated files
# ----------------------------------------------------------------------

. defs.fish

evald rm -Rf $BUILD
rm-tmp
rm-redo
