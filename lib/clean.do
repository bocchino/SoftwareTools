#!/usr/bin/env fish

. params.fish

evald rm -Rf $BUILD

redo tests/clean
