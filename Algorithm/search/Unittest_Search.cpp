/*************************************************************************
 > File Name: Unittest_Search.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include"bs1.h"
#include"bs2.h"
#include"bs3.h"
#include"bs4.h"
#include"bs5.h"
#include"bs6.h"
#include"bs7.h"
#include"bs8.h"
using namespace std;

int arr[16] = {1,2,2,3,3,3,4,4,4,4,5,5,5,6,6,7};

int main()
{
	cout<<bSearch1(arr,0,15,1)<<endl;
	cout<<bSearch1(arr,0,15,2)<<endl;
	cout<<bSearch1(arr,0,15,3)<<endl;
	cout<<bSearch1(arr,0,15,4)<<endl;
	cout<<bSearch1(arr,0,15,5)<<endl;
	cout<<bSearch1(arr,0,15,6)<<endl;
	cout<<bSearch1(arr,0,15,7)<<endl;
	return 0;
}



