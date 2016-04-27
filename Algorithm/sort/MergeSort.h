/*************************************************************************
 > File Name: MergeSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _merge_sort_h_
#define _merge_sort_h_

template<typename TYPE>
void Merge(TYPE *arr, TYPE *temp, size_t l, size_t r)
{
    size_t m = (l+r)>>1;
    size_t i = l, j = m+1,k = l;
    while(i <= m && j <= r)
    {
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= m) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    for(size_t i = l;i <= r;++i) arr[i] = temp[i];
}

template<typename TYPE>
void MergeSort(TYPE *arr, TYPE *temp, size_t l, size_t r)
{
    if(l < r)
    {
        size_t m = (l+r)>>1;
        MergeSort(arr, temp, l, m);
        MergeSort(arr, temp, m+1, r);
        Merge(arr, temp, l, r);
    }
}

template<typename TYPE>
void MergeSort(TYPE *arr, size_t n)
{
    TYPE *temp = new TYPE[n];
    MergeSort(arr, temp, 0, n-1);
    delete temp;
}

#endif
