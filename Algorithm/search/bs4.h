/*************************************************************************
 > File Name: bs4.h 返回小于key的最大数的下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _bs4_h_
#define _bs4_h_

int bSearch4(int *arr, int l,int r,int key)
{
	while(l<=r)
	{
		if(arr[r]<key) return r;
		int	m = (l+r)>>1;
		if(arr[m]<key) 
			if(m<r&&arr[m+1]<key)
				l=m+1;
		    else
				r=m;
		else if(arr[m]>=key) 
				r=m-1;
	}
	return -1;
}

#endif
