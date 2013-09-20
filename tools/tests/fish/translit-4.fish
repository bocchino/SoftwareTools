# ----------------------------------------------------------------------
# translit-4.fish: test translit-4
# ----------------------------------------------------------------------

set out (echo abcABC123 | ../build/translit a-zA-Z a)
if not test $out = a123 
  exit 1
end

set out (echo abcABC123 | ../build/translit a-zA-Z)
if not test $out = 123
  exit 2
end

exit 0
