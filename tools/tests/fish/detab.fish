set out (echo 1\t2\t3 | eval ../$BUILD/detab)
test $out = '1       2       3'
