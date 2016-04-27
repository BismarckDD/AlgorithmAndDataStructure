/*************************************************************************
 > File Name: SelectionSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _selection_sort_h_
#define _selection_sort_h_

template<typename TYPE>
void SelectionSort(TYPE *arr, size_t n)
{
    TYPE key;
    for(size_t i=0, j, k; i <= n-2; ++i)
    {
        key = arr[i];
        k = i;
        for(j = i+1; j <= n-1; ++j)
            if(arr[j] < key)
            {
                key = arr[j];
                k = j;
            }
        if(k != i)
        {
            arr[i] = arr[i]^arr[k];
            arr[k] = arr[i]^arr[k];
            arr[i] = arr[i]^arr[k];
        }
    }
}

#endif
