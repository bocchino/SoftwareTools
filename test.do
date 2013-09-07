#!/opt/local/bin/fish

. params.fish

echoerr 'testing lib'
redo lib/test
echoerr 'testing tools'
redo tools/test
