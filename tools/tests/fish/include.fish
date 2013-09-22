# ----------------------------------------------------------------------
# include.fish: test include
# ----------------------------------------------------------------------

../build/include < fish/include-in-1.txt > fish/include.out
diff fish/include.out fish/include.ref 1>&2
