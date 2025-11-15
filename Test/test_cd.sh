#!/bin/bash

# Define colors
dark='\033[1;39m'
green='\033[0;32m'
red='\033[0;31m'
end='\033[0m'

# Name of the test
echo -e "$dark\nTest cd$end"

# Test
test=("cd ; cd ..; ls")
output=$(echo $test | ./42sh)
outputtcsh=$(echo $test | tcsh)
if [ "$output" == "$outputtcsh" ]; then
    echo -e "$green[ OK ]$end: command: $test"
else
    echo -e "$red[ KO ]$end: command: $test"
fi

test=("cd /root; ls")
output=$(echo $test | ./42sh)
outputtcsh=$(echo $test | tcsh)
if [ "$output" == "$outputtcsh" ]; then
    echo -e "$green[ OK ]$end: command: $test"
else
    echo -e "$red[ KO ]$end: command: $test"
fi

test=("cd ; env | grep PWD")
output=$(echo $test | ./42sh)
outputtcsh=$(echo $test | tcsh)
if [ "$output" == "$outputtcsh" ]; then
    echo -e "$green[ OK ]$end: command: $test"
else
    echo -e "$red[ KO ]$end: command: $test"
fi

test=("cd ..; cd -; ls")
output=$(echo $test | ./42sh)
outputtcsh=$(echo $test | tcsh)
if [ "$output" == "$outputtcsh" ]; then
    echo -e "$green[ OK ]$end: command: $test"
else
    echo -e "$red[ KO ]$end: command: $test"
fi

test=("cd ..")
output=$(echo $test | ./42sh)
outputtcsh=$(echo $test | tcsh)
if [ "$output" == "$outputtcsh" ]; then
    echo -e "$green[ OK ]$end: command: $test"
else
    echo -e "$red[ KO ]$end: command: $test"
fi
