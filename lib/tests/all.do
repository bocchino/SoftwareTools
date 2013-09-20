#!/usr/bin/env fish

# ----------------------------------------------------------------------
# all.do: build and run everything
# ----------------------------------------------------------------------

. defs.fish

redo-ifchange build
redo run
