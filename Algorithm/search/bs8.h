/*************************************************************************
 > File Name: bs8.h 经过旋转的数组
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs8_h_
#define _bs8_h_

int bSearch8(int *arr, int l,int r,int key)
{
    while(l<=r)
    {
        int m = (l+r)>>1;
        if(arr[m]==key) return m;
        else if(arr[m]<key) 
        {
            if(arr[r]>=key) l=m+1;
            else r=m-1;
        }
        else if(arr[m]>key) 
        {
            if(arr[l]<=key) r=m-1;
            else l=m+1;
        }
    }
    return -1;
}

#endif
