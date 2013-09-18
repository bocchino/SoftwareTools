../build/compare fish/file{1,2}.txt > fish/compare.tmp 2>&1
diff fish/compare.tmp fish/compare.out > /dev/null
