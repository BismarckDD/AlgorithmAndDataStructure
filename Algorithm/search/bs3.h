/*************************************************************************
 > File Name: bs3.h 返回key值的最大下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs3_h_
#define _bs3_h_

int bSearch3(int *arr, int l,int r,int key)
{
    while(l<=r)
    {
        int m = (l+r)>>1;
        if(arr[m]==key) 
        {
            if(m==r) return m;
            if(m<=r-1&&arr[m+1]!=key) return m;
            else l=m+1;
        }
        else if(arr[m]<key) l=m+1;
        else if(arr[m]>key) r=m-1;
    }
    return -1;
}

#endif
