# ----------------------------------------------------------------------
# wordcount.fish: test wordcount
# ----------------------------------------------------------------------

set out (echo 'word1 word2 word3' | eval ../build/wordcount)
test $out = 3
