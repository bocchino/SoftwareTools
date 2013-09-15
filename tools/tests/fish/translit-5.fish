set out (echo abcABC123 | ../build/translit ~a-zA-Z -)
if not test $out = abcABC-
  exit 1
end

set out (echo abcABC123 | ../build/translit ~a-zA-Z)
if not test $out = abcABC
  exit 2
end

exit 0
