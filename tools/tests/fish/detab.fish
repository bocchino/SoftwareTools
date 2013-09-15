set out (echo 1\t2\t3 | eval ../build/detab)
test $out = '1       2       3'
