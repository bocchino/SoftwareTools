set out (echo 'line1
line2
line3' | eval ../build/linecount)
test $out = 3
