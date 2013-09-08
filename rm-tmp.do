#!/opt/local/bin/fish

# ----------------------------------------------------------------------
# rm-tmp: remove temporary files
# ----------------------------------------------------------------------

. params.fish

find . -name '*~' | xargs rm
find . -name '*redo*tmp' | xargs rm
