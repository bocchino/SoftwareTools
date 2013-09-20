# ----------------------------------------------------------------------
# defs.fish: definitions common to all subdirectories
# ----------------------------------------------------------------------

# Users of this file should set LEVEL first
if not set -q LEVEL
  set -gx LEVEL .
end

redo-ifchange $LEVEL/defs.fish

set -gx CC clang
set -gx CCFLAGS -std=c99

function redo-ifchange-d -d 'Redo if dependencies changed'
  for arg in $argv
    tr '\n' ' ' < $arg | read deps
    set deps (echo $deps | sed -e 's/^.*: *//' -e 's/\\\\//g')
    echo $deps
  end | xargs redo-ifchange
end

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

function rm-tmp -d 'Remove temporary files'
  find . -name '*~' | xargs rm
  find . -name '*redo*tmp' | xargs rm
end

function rm-redo -d 'Remove redo database files'
  find . -name .redo | xargs rm -R
end

