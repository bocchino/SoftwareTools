#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish

redo-ifchange $BUILD
redo-ifchange $BUILD/libst.a
