set out (echo -n abcd | eval ../$BUILD/charcount)
test $out = 4
