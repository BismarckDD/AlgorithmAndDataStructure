/*************************************************************************
 > File Name: ShellSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时00分12秒
 ************************************************************************/

#ifndef _shell_sort_h_
#define _shell_sort_h_

template<typename TYPE>
void ShellPass(TYPE *arr,int n, int d)
{
    for(int j,i = d,tmp;i <= n-1;++i)
    {
        tmp = arr[i];
        for(j = i;j >= d && tmp < arr[j-d];j = j-d)
            arr[j] = arr[j-d];
        arr[j] = tmp;
    }
}
template<typename TYPE>
void ShellSort(TYPE *arr,int n, int d)
{
    int increment = d;
    do{
        increment = increment/3+1;
        ShellPass(arr,n,increment);
    }while(increment>1);
}

#endif
