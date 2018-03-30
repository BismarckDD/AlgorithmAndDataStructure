#include<iostream>
#include<cstdio>
using namespace std;

int func(int n)
{
    //From the highest pos 1 in m, write low pos to 1 by or operation, then plus 1
    int m = n-1;
    m |= m >> 1;  cout << m << endl;
    m |= m >> 2;  cout << m << endl;
    m |= m >> 4;  cout << m << endl;
    m |= m >> 8;  cout << m << endl;
    m |= m >> 16; cout << m << endl;
    return m<0 ? 1 : m+1;
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        printf("%d\n", func(n));
    }
    return 0;
}
