COUNT=0

run_test () {
    echo ====== TEST ${COUNT} =====
    echo input: $@
    ./convert $@
    let COUNT++
}

run_test '0'
run_test 'nan'
run_test '42.0f'

exit

run_test '0.0'
run_test '00000'
run_test '-0'
run_test '++++0'
run_test '++----0'

run_test ' '
run_test 'abc'
run_test '0 1 2 3'

run_test '42f'
run_test '42.424242'

run_test '1'
run_test '-1'
run_test '1.1.1'
run_test '1000.0'
run_test '10001.01'
run_test '0.0001'
run_test '-0.0001'

run_test '127'
run_test '-128'
run_test '128'
run_test '-129'
run_test '2147483647'
run_test '-2147483648'
run_test '2147483648'
run_test '-2147483649'
