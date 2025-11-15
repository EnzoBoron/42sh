#!/bin/bash

make
make clean
clear

./Test/test_simple.sh
./Test/test_echo.sh
./Test/test_cd.sh
./Test/test_env.sh
./Test/test_redirection.sh
./Test/test_complexe.sh

