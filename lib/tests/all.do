#!/usr/bin/env fish

. params.fish

redo-ifchange build
redo run
