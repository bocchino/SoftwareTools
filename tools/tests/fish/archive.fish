# ----------------------------------------------------------------------
# archive.fish: test archive
# ----------------------------------------------------------------------

set n 3
set is (seq 1 $n)

for i in $is
  cp fish/f$i.in fish/f$i
end

set -e fs
for i in $is
  set fs $fs fish/f$i
end

rm -f fish/arch

# test update
../build/archive u fish/arch $fs
diff fish/arch fish/arch.ref
if test $status -ne 0; exit 1; end

# test table
../build/archive t fish/arch > fish/table
diff fish/table fish/table.ref
if test $status -ne 0; exit 2; end

# test extract
../build/archive t fish/arch fish/f1
diff fish/f1 fish/f1.in
if test $status -ne 0; exit 3; end 

# test delete
../build/archive d fish/arch fish/f1
diff fish/arch fish/arch-f1.ref
if test $status -ne 0; exit 4; end

exit 0
