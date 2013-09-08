set out (echo '        abc' | eval ../$BUILD/entab)
test $out = \tabc
