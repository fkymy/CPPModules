#!/bin/bash

make

echo "TEST EMPTY"
./replace test1 hello world
diff <(cat -e test1) <(cat -e test1.replace)
echo "DIFF: "

echo "TEST WHITE SPACES AND NEWLINE"
./replace test2 $'\t' $'\n'
echo "DIFF: "
diff <(cat -e test2) <(cat -e test2.replace)

echo "TEST CASE SINSITIVITY"
./replace test3 A B
echo "DIFF: "
diff <(cat -e test3) <(cat -e test3.replace)

echo "TEST SINGLE"
./replace test3 a b
echo "DIFF: "
diff <(cat -e test3) <(cat -e test3.replace)


echo "TEST SAME WORD"
./replace test4 program program
echo "DIFF: "
diff <(cat -e test4) <(cat -e test4.replace)


echo "TEST NO MATCH"
./replace test4 programx programy
echo "DIFF: "
diff <(cat -e test4) <(cat -e test4.replace)

echo "TEST s1 > s2"
./replace Makefile replace rp
echo "DIFF: "
diff <(cat -e Makefile) <(cat -e Makefile.replace)

# - s1 < s2 `./replace test4 progra prograaaaaaaa`
echo "TEST s1 < s2"
./replace test5 progra prograaaaaaaaaaaaaaaaaaa
echo "DIFF: "
diff <(cat -e test5) <(cat -e test5.replace)

echo "TEST s2 PASSED NPOS"
./replace test6 works. works...!
echo "DIFF: "
diff <(cat -e test6) <(cat -e test6.replace)

# - big file
echo "TEST LARGE FILE"
./replace test_alice asdfhasdasdfafasdfasga WHAT
echo "DIFF: "
diff <(cat -e test_alice) <(cat -e test_alice.replace)
