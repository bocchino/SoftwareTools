set out (echo -n abcd | eval ../build/charcount)
test $out = 4
