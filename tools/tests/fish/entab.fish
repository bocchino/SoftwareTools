set out (echo '        abc' | eval ../build/entab)
test $out = \tabc
