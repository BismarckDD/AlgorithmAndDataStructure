/*************************************************************************
 > File Name: Unittest_search_Search.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <Algorithm.h>
#include <Common.hpp>

const uint64_t N = 100;
int arr[N*N];
int ror[N];

template<class _RanIt, class _Ty>
void unittest_search(const char* p_str, _RanIt p_begin, _RanIt p_end, _RanIt (*search)(_RanIt, _RanIt, const _Ty&))
{
    std::cout << std::string(p_str) << " Test Started. " << std::endl;
    for (int i = 0; i <= N + 1; ++i)
        std::cout << "key: " << i << " is at index: " << search(p_begin, p_end, i) - p_begin << std::endl;
    std::cout << "Test Finish." << std::endl << std::endl;
}

void init()
{
    int i, j, k = 0;
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= i; ++j)
            arr[k++] = i;
    for (i = N + 1; i < (N << 1); ++i)
        for (j = (N << 1) - 1; j >= i; --j)
            arr[k++] = i;
    // std::cout << k << std::endl;
    // system("pause");

    k = rand() % N;
    for (i = 0; i < N; ++i)
        ror[i] = i;
    i = 0, j = k;
    while (i < j) { stdcs::swap(ror[i++], ror[j--]); }
    i = k + 1, j = N - 1;
    while (i < j) { stdcs::swap(ror[i++], ror[j--]); }
    i = 0, j = N - 1;
    while (i < j) { stdcs::swap(ror[i++], ror[j--]); }
}

int main()
{
    init();
    unittest_search<int*, int>("BinarySearch1", arr, arr + N*N, stdcs::BinarySearch1);
    unittest_search<int*, int>("BinarySearch2", arr, arr + N*N, stdcs::BinarySearch2);
    unittest_search<int*, int>("BinarySearch3", arr, arr + N*N, stdcs::BinarySearch3);
    unittest_search<int*, int>("BinarySearch4", arr, arr + N*N, stdcs::BinarySearch4);
    unittest_search<int*, int>("BinarySearch5", arr, arr + N*N, stdcs::BinarySearch5);
    unittest_search<int*, int>("BinarySearch6", arr, arr + N*N, stdcs::BinarySearch6);
    unittest_search<int*, int>("BinarySearch7", arr, arr + N*N, stdcs::BinarySearch7);
    unittest_search<int*, int>("BinarySearch8", ror, ror + N, stdcs::BinarySearch8);

    // for (int i = 0; i < N; ++i) std::cout << ror[i] << std::endl;
    return 0;
}



