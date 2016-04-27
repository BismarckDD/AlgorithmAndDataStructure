/*************************************************************************
 > File Name: QuickSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _quick_sort_h_
#define _quick_sort_h_

template<typename TYPE>
size_t partition(TYPE *arr, size_t l, size_t r)
{
    //size_t k = l+(rand()%(r-l));
    TYPE key = arr[l];
    size_t i = l, j = r;
    while(i < j)
    {   
        while(i < j && arr[j] >= key) --j;
        if(i < j) arr[i++] = arr[j];
        while(i < j && arr[i] <= key) ++i;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = key;
    return i;
}

template<typename TYPE>
void QuickSort(TYPE *arr, size_t l, size_t r)
{
    if(l < r)
    {
        size_t key = partition(arr, l, r);
        QuickSort(arr, l, key==0?key:key-1);
        QuickSort(arr, key+1, r);
    }
}

template<typename TYPE>
void QuickSort(TYPE *arr, size_t n)
{
    QuickSort(arr, 0, n-1);
}

#endif
