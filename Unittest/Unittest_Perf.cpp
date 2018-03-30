#include <iostream>
#include <algorithm>
#include <Algorithm.h>
#include "Timer.h"
#include <cstdlib>

const int MAXN = 1000000;
int arr[MAXN], brr[MAXN];
int main()
{
    for (int i = 0; i < MAXN; ++i)
    {
        arr[i] = rand();
        brr[i] = arr[i];
    }

    stdcs::tools::Timer timer;
    timer.count();
    std::sort(arr, arr + MAXN);
    timer.count();
    std::cout << "STL sort: " << timer.getElapse() << std::endl;

    timer.count();
    stdcs::sort(arr, arr + MAXN);
    timer.count();
    std::cout << "Custom Sort: " << timer.getElapse() << std::endl;

    timer.count();
    stdcs::HeapSort(arr, arr + MAXN);
    timer.count();
    std::cout << "Heap Sort: " << timer.getElapse() << std::endl;

    return 0;
}
