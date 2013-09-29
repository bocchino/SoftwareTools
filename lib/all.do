#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/all.do: build everything
# ----------------------------------------------------------------------

mkdir -p build
mkdir -p depend
redo-ifchange build/libst.a
