#!/bin/bash

# Define colors
dark='\033[1;39m'
green='\033[0;32m'
red='\033[0;31m'
end='\033[0m'

# Name of the test
echo -e "$dark\nTest redirection$end"

# Test
declare -a test=(
"ls > a; cat a; rm -f a"
"ls >> a; cat a; rm -f a"
"touche a ; ls < a ; rm -f a"
"touch a ; ls << a ; rm -f a"
"touch a ; ls <<< a ; rm -f a"
)

touch test
touch test1

for i in "${test[@]}"
do
    echo "$i" | ./42sh &> test
    echo "$i" | tcsh &> test1
    output=$(cat test)
    output2=$(cat test1)
    if [ "$output" == "$output2" ]; then
        echo -e "$green[ OK ]$end: command: $i"
    else
        echo -e "$red[ KO ]$end: command: $i"
    fi

done
rm test
rm test1
