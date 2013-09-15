#!/opt/local/bin/fish

redo-ifchange params.fish
. params.fish

set -g passed 0
set -g failed 0

function run
  set base (basename -s .fish $argv[1])
  if fish $argv[1]
    set passed (math $passed '+ 1')
  else
    echoerr $base': FAILED with status '$status
    set failed (math $failed '+ 1')
  end 
end

for file in fish/*
  if not echo $file | grep -q '~$'
    run $file
  end
end

echoerr $passed' passed, '$failed' failed'
