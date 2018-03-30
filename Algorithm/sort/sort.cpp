#include<algorithm>
#include<iostream>
#include<cstdlib>
#include"HeapSort.h"
//using namespace std;

const int limit = 4000000;
int arr[limit], base[limit];
void generateBase(const int p_limit = limit)
{
    for (int i = 0; i < p_limit; ++i)
        base[i] = i;
    for (int i = 0, j; i < p_limit; ++i)
    {
        j = (rand() * 32767 + rand()) % (p_limit - i);
        swap(base[i], base[i + j]);
    }
}

int main()
{

    generateBase();
    for (int i = 0; i < limit; ++i)
        arr[i] = base[i];
    HeapSort(arr, arr + limit);
    for (int i = 0; i < limit - 1; ++i)
        if (arr[i] > arr[i + 1])
            printf("Error\n");
    for (int i = 0; i < limit; ++i)
        arr[i] = base[i];
    HeapSort(arr, arr + limit, Greater());
    for (int i = 0; i < limit - 1; ++i)
        if (arr[i] < arr[i + 1])
            printf("Error\n");
    printf("OK\n");
    return 0;
}