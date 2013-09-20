#!/usr/bin/env fish

# ----------------------------------------------------------------------
# all.do: build everything
# ----------------------------------------------------------------------

. defs.fish

mkdir -p $BUILD
mkdir -p $DEPEND
redo-ifchange $BUILD/libst.a
