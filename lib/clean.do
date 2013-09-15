#!/usr/bin/env fish

redo-ifchange params.fish
. params.fish

evald rm -Rf $BUILD

redo tests/clean
