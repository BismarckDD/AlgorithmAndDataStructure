/*************************************************************************
 > File Name: Unittest_Heap.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月20日 星期六 02时02分41秒
 ************************************************************************/

#include "Heap.h"
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const size_t MAXN = 1000000;

bool cmp(const int &a, const int &b)
{
    return a < b;
}

int main()
{
    int n;
    Heap<int> pq(MAXN, cmp);
    for(int i=1;i<=MAXN;++i)
    {
        n = rand();
        pq.Push(n);
    //    cout << pq.size() << "," << pq.capacity() <<  endl;
    }
    cout << "Insert Successfully" << endl;

    int temp = 0, count = 0;
    bool flag = true;
    while(!pq.isEmpty())
    {
        ++count;
        if (temp > pq.Top())
        {
            flag = false;
            break;
        }
        else
        {
            temp = pq.Pop();
        }
    }
    cout << "Delete Successfully" << endl;

    if (flag && count == MAXN){
        cout << "Algorithm Correct!" << endl;
    } else {
        cout << "Algorithm Incorrect!" << endl;
    }
    return 0;
}
