# using bash to run a c++ file and take input in line by lien from a txt file
# and compare the output with the expected output

# run the program and pass each line of the input file as input
# and compare the output with the expected output

g++ -std=c++11 -o test ../main.cpp

# Don't show the output of the program when running the test

# run the program and pass each line of the input file as input

# shellcheck disable=SC2065
./test < input.txt > temp.txt

# compare the output with the expected output

diff output.txt expected_output.txt

# if the output is same as expected output then the test case is passed

if [ $? -eq 0 ]; then
    echo "✅ Test case passed"
    rm temp.txt
    rm test
    exit 0
#    Tell GitHub CI/CD the test failed
else
    echo "Test case failed"
    rm temp.txt
    rm test
    exit 1
fi








