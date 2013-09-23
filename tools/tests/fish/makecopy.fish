# ----------------------------------------------------------------------
# makecopy.fish: test makecopy
# ----------------------------------------------------------------------

../build/makecopy fish/makecopy.fish fish/makecopy.out
diff fish/makecopy.fish fish/makecopy.out 1>&2
