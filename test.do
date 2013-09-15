#!/usr/bin/env fish

. params.fish

redo-ifchange all

redo lib/test
redo tools/test
