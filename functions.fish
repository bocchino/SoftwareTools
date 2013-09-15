function echoerr -d 'Echo args to stderr'
  echo $argv 1>&2
end

function evald -d 'Eval with echo to stderr if DEBUG set'
  if set -q DEBUG
    echoerr $argv
  end
  eval $argv
end 

function debug -d 'Turn build debugging on'
  set -gx DEBUG 1
end

function nodebug -d 'Turn build debugging off'
  set -e DEBUG
end
