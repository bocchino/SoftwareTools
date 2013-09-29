#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/all.do: build and run everything
# ----------------------------------------------------------------------

redo-ifchange build
redo run
