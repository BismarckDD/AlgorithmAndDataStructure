/*************************************************************************
 > File Name: HeapSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _heap_sort_h_
#define _heap_sort_h_

#include"../../DataStructure/Heap/Heap.h"

template<typename TYPE>
void HeapSort(TYPE *arr, size_t n)
{
    Heap<int> heap(n+10);
    for(size_t i=0;i<n;++i) heap.Push(arr[i]);
    for(size_t i=0;i<n;++i) arr[i] = heap.Pop();
}

#endif

