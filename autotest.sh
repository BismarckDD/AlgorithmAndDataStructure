#!/bin/bash

# all_test=(Heap Sort Search Unique Graph)
all_test=(Heap Sort Search Unique Perf List)

ROOT=(`pwd`)

args="--std=c++11 \
      -I$ROOT \
      -I$ROOT/Algorithm \
      -I$ROOT/Algorithm/sort \
      -I$ROOT/Algorithm/search \
      -I$ROOT/Algorithm/dedup \
      -I$ROOT/DataStructure/Collection \
      -I$ROOT/DataStructure/List"

# echo $args

if [ $# -eq 0 ]; then
    for i in ${all_test[@]}; do
        g++ -o Unittest_$i ./Unittest/Unittest_$i.cpp $args
        time ./Unittest_$i
        rm Unittest_$i
    done
    exit
else
    for i in $@; do
        g++ -o Unittest_$i ./Unittest/Unittest_$i.cpp $args
        time ./Unittest_$i
        rm Unittest_$i
    done
    exit
fi

