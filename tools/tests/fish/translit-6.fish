set out (echo -n 'a '\tb\nc | ../build/translit ' @t@n' @n | tr \n :)
test $out = a:b:c
