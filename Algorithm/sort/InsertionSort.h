/*************************************************************************
 > File Name: InsertionSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _insertion_sort_h_
#define _insertion_sort_h_

template<typename TYPE>
void InsertionSort(TYPE *arr, size_t n)
{
    TYPE key;
    for(size_t i = 1, j; i <= n-1; ++i)
    {
        key = arr[i];
        for(j = i; j >= 1 && key < arr[j-1]; --j)
            arr[j] = arr[j-1];
        arr[j] = key;
    }
}

#endif
