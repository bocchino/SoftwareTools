set string abcaaaaabbbbbabc
test (echo $string | eval ../$BUILD/compress | eval ../$BUILD/expand) = $string
