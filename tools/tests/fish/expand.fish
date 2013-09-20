# ----------------------------------------------------------------------
# expand.fish: test expand
# ----------------------------------------------------------------------

set string abcaaaaabbbbbabc
test (echo $string | eval ../build/compress | eval ../build/expand) = $string
