test (echo -n 'abcaaaaabbbbbabc' | eval ../$BUILD/compress) = \x03abc\x00a\x05\x00b\x05\x03abc
