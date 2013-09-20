#!/usr/bin/env fish

# ----------------------------------------------------------------------
# run.do: run all tests
# ----------------------------------------------------------------------

. defs.fish

set -g passed 0
set -g failed 0

function run
  set base (basename $argv[1])
  if eval $argv[1]
    set passed (math $passed '+ 1')
  else
    echoerr $base': FAILED with status '$status
    set failed (math $failed '+ 1')
  end 
end

for file in $BUILD/*
  run $file
end

echoerr $passed' passed, '$failed' failed'
