set out (echo abcABC | ../build/translit a-zA-Z A-Za-z)
test $out = ABCabc 

