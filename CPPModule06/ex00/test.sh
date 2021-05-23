COUNT=0

run_test () {
    echo
    echo ====== TEST ${COUNT} =====
    echo './convert' $@
    ./convert "$@"
    let COUNT++
}

run_test '0'
run_test 'nan'
run_test '42.0f'

run_test '0.0'
run_test '00000'
run_test '-0'
run_test '+0'
run_test '++++0'
run_test '++----0'

run_test '{'
run_test 'a'
run_test 'A'
run_test ' a '
run_test ' a b '
run_test '123abc'
run_test '123abc'
run_test '12a'

run_test '     42f'
run_test '  +42f  '
run_test '  -42f  '
run_test '   42f  '
run_test '   42ff '
run_test '42.424242'

run_test '1'
run_test '-1'
run_test '1.1.1'
run_test '1..1.1.1'
run_test '100 200 300'

run_test '1000.0'
run_test '10001.01'
run_test '0.0001'
run_test '-0.0001'

run_test '126'
run_test '127'
run_test '-128'
run_test '128'
run_test '-129'
run_test '2147483647'
run_test '-2147483648'
run_test '2147483648'
run_test '-2147483649'

run_test ' '
run_test '0 1 2 3'

exit
