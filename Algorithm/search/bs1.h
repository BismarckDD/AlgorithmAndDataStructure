/*************************************************************************
 > File Name: bs1.h 普通二分查找
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs1_h_
#define _bs1_h_

int bSearch1(int *arr, int l,int r,int key)
{
    while(l<=r)
    {
        int m = (l+r)>>1;
        if(arr[m]==key) return m;
        else if(arr[m]<key) l=m+1;
        else if(arr[m]>key) r=m-1;
    }
    return -1;
}

#endif
