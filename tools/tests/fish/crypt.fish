set string 'This is a Burger King town.'
set key frumious
set crypt ../$BUILD/crypt frumious
test (echo $string | eval $crypt | eval $crypt) = $string
