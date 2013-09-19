redo-ifchange params.fish

if not set -q LEVEL
  set LEVEL .
end

. $LEVEL/functions.fish

set -gx CC clang
set -gx CCFLAGS -std=c99
