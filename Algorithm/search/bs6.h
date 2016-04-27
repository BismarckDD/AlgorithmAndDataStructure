/*************************************************************************
 > File Name: bs6.h 返回小于等于key的最大值的下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs6_h_
#define _bs6_h_

int bSearch6(int *arr, int l,int r,int key)
{
    while(l<=r)
    {
        if(arr[r]<=key) return r;
        int m = (l+r)>>1;
        if(arr[m]<=key) 
            if(m>l&&arr[m-1]<=key)
                l=m+1;
            else
                r=m;
        else if(arr[m]>key)
            r=m-1;
    }
    return -1;
}

#endif
