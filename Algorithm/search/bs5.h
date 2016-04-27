/*************************************************************************
 > File Name: bs5.h 返回大于key的最小值的下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs5_h_
#define _bs5_h_

int bSearch5(int *arr, int l,int r,int key)
{
    while(l<=r)
    {
        if(arr[l]>key) return l;
        int m = (l+r)>>1;
        if(arr[m]<=key) l=m+1;
        else if(arr[m]>key) 
            if(m>l&&arr[m-1]>key)
                r=m-1;
            else 
                l=m;
    }
    return -1;
}

#endif
