#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/all.do: build and run everything
# ----------------------------------------------------------------------

. defs.fish

redo-ifchange build
redo run
