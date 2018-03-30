#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
// using namespace std;
#include "Timer.h"
#include "GenerateBase.h"
#include <Common.hpp>
#include <Algorithm.h>

template<class _ty>
void unittest_sort(const char *test_name, void (*sort)(_ty* p_arr, size_t p_cnt), const size_t MAXN = 10000)
{

    boost::shared_array<_ty> vec = stdcs::GenerateBaseRandom<int>(MAXN);
    stdcs::tools::Timer timer;
    timer.count();
    sort(vec.get(), MAXN);
    timer.count();

    bool flag = true;
    std::string str(test_name);

    std::cout << str << ": ";

    auto temp = vec[0];
    for(size_t i = 1; i < MAXN; ++i) 
    {
        if(temp > vec[i]) { flag = false; break; }
        else temp = vec[i];
    }

    if (flag) {
        std::cout << "Test Succeed!" << std::endl;
        std::cout << "    Running Time:" << timer.getElapse() << " seconds!" << std::endl;
    } else {
        std::cout << "Test Failed!" << std::endl;
    }
}

struct Cmp
{
    template<class _Ty>
    bool operator() (const _Ty& i, const _Ty& j) const
    {
        return i < j;
    }
};

int main()
{
    // unittest_sort<int>("Sort", stdcs::sort);
    unittest_sort<int>("MergeSort", stdcs::MergeSort);
    unittest_sort<int>("HeapSort", stdcs::HeapSort);
    unittest_sort<int>("QuickSort", stdcs::QuickSort);
    unittest_sort<int>("SelectionSort", stdcs::SelectionSort);
    unittest_sort<int>("InsertionSort", stdcs::InsertionSort);
    unittest_sort<int>("BubbleSort", stdcs::BubbleSort);
    unittest_sort<int>("ShellSort", stdcs::ShellSort);
    unittest_sort<int>("BucketSort", stdcs::BucketSort);
    unittest_sort<int>("CountSort", stdcs::CountSort);
    unittest_sort<int>("RadixSort", stdcs::RadixSort);
    //unittest_sort<int>("3WayQuickSort" stdcs::3WayQuickSort);
    return 0;
}
