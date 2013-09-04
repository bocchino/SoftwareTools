#!/opt/local/bin/fish

echo 'testing lib' 1>&2
redo lib/test
echo 'testing tools' 1>&2
redo tools/test
