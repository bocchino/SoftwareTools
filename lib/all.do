#!/usr/bin/env fish

. params.fish

mkdir -p $BUILD
mkdir -p $DEPEND
redo-ifchange $BUILD/libst.a
