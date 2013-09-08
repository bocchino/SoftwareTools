#!/opt/local/bin/fish

# ----------------------------------------------------------------------
# rm-redo: remove redo database files
# ----------------------------------------------------------------------

. params.fish

find . -name .redo | xargs rm -R
