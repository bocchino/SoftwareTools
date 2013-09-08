#!/opt/local/bin/fish

. params.fish

redo-ifchange all

echoerr 'testing lib'
redo lib/test
echoerr 'testing tools'
redo tools/test
