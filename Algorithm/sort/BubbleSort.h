/*************************************************************************
 > File Name: BubbleSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _bubble_sort_h_
#define _bubble_sort_h_

template<typename TYPE>
void BubbleSort(TYPE *arr, size_t n)
{
    bool flag;
    for(size_t i = 0;i <= n-2; ++i)
    {
        flag = false;
        for(size_t j = n-1; j >= i+1; --j)
        {
            if(arr[j] < arr[j-1])
            {
            //  int temp = arr[j];
            //  arr[j] = arr[j-1];
            //  arr[j-1] = temp;
                arr[j]   = arr[j]^arr[j-1];
                arr[j-1] = arr[j]^arr[j-1];
                arr[j]   = arr[j]^arr[j-1];
                flag = true;
            }
        }
        if(!flag) return ;
    }
}

#endif

