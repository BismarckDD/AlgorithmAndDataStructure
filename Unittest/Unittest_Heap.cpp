/*************************************************************************
 > File Name: Unittest_Heap.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月20日 星期六 02时02分41秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "../Algorithm/sort/HeapSort.h"
#include "../DataStructure/Collection/Heap.h"
#include "GenerateBase.h"
#include <boost/shared_array.hpp>
using namespace stdcs;

const int limit = 1000000;

int main()
{

    boost::shared_array<int> sarr;
    int *arr;

    sarr = stdcs::GenerateBaseRandom<int>(limit);
    arr = sarr.get();

    stdcs::HeapSort(arr, arr + limit);
    for (int i = 0; i < limit - 1; ++i)
        if (arr[i] > arr[i + 1])
            REPORT_ERROR_AND_EXIT

    sarr = stdcs::GenerateBaseRandom<int>(limit);
    arr = sarr.get();

    stdcs::HeapSort(arr, arr + limit, Greater());
    for (int i = 0; i < limit - 1; ++i)
        if (arr[i] < arr[i + 1])
            REPORT_ERROR_AND_EXIT

    stdcs::Heap<int> heap;
    for (int i = 0; i < limit; ++i) 
        heap.push(arr[i]);


    int temp = 10000000;
    for (int i = 0; i < limit; ++i)
    {
        if (temp < heap.top())
            REPORT_ERROR_AND_EXIT
        else
            temp = heap.pop();
    }

    printf("Heap Test Succeed!\n");
    return 0;
}
