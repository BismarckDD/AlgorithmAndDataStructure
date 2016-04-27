/*************************************************************************
 > File Name: bs2.h 返回key值的最小下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs2_h_
#define _bs2_h_

int bSearch2(int *arr, int l,int r,int key)
{
    while(l<=r)
    {
        int m = (l+r)>>1;
        if(arr[m]==key) 
        {
            if(m==l) return m;
            if(m>=l+1&&arr[m-1]!=key) return m;
            else r=m-1;
        }
        else if(arr[m]<key) l=m+1;
        else if(arr[m]>key) r=m-1;
    }
    return r;
}

#endif
