# ----------------------------------------------------------------------
# compress.fish: test compress
# ----------------------------------------------------------------------

test (echo -n 'abcaaaaabbbbbabc' | eval ../build/compress) = \x03abc\x00a\x05\x00b\x05\x03abc
