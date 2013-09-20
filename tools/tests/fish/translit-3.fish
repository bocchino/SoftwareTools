# ----------------------------------------------------------------------
# translit-3.fish: test translit-3
# ----------------------------------------------------------------------

set out (echo abcABC | ../build/translit a-zA-Z A-Za-z)
test $out = ABCabc 

