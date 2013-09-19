#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish

mkdir -p $BUILD
mkdir -p $DEPEND
redo-ifchange $BUILD/libst.a
