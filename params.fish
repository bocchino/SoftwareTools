if not set -q LEVEL
  set LEVEL .
end

. $LEVEL/functions.fish

set -gx CC clang
set -gx BUILD build
set -gx CCFLAGS -std=c99
