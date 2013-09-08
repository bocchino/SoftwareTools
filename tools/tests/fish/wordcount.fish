set out (echo 'word1 word2 word3' | eval ../$BUILD/wordcount)
test $out = 3
