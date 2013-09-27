#!/usr/bin/env fish

# ----------------------------------------------------------------------
# lib/tests/run.do: run all tests
# ----------------------------------------------------------------------

. defs.fish

set -g passed 0
set -g failed 0

function run
  set base (basename $argv[1])
  echoerr -n $base:' '
  if eval $argv[1]
    echoerr PASSED
    set passed (math $passed '+ 1')
  else
    echoerr 'FAILED with status '$status
    set failed (math $failed '+ 1')
  end 
end

for file in $BUILD/*
  run $file
end

echoerr $passed' passed, '$failed' failed'
