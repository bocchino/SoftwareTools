# ----------------------------------------------------------------------
# concat.fish: test concat
# ----------------------------------------------------------------------

../build/concat fish/*.fish > fish/concat.out
cat fish/*.fish > fish/concat.ref
diff fish/concat.out fish/concat.ref 1>&2
