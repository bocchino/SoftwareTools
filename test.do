#!/usr/bin/env fish

# ----------------------------------------------------------------------
# test.do: build and run tests
# ---------------------------------------------------------------------- 

redo-ifchange all

redo lib/test
redo tools/test
