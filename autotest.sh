#!/bin/bash

cd ./Unittest

all_test=(Heap Sort Search Unique Graph)

$args="--std=c++11 -I"

if [ $# -eq 0 ]; then
    for i in ${all_test[@]}; do
        g++ -o Unittest_$i Unittest_$i.cpp --std=c++11
        time ./Unittest_$i
        rm Unittest_$i
    done
    exit
else
    for i in $@; do
        g++ -o Unittest_$i Unittest_$i.cpp --std=c++11
        time ./Unittest_$i
        rm Unittest_$i
    done
    exit
fi

