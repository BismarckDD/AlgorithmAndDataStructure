#ifndef _sort_h_
#define _sort_h_

#include "../../Common.hpp"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

namespace stdcs
{

template<class _RanIt, class _Comp>
void sort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp, const size_t& p_currDeep, const size_t& p_maxiDeep)
{
    if (p_end - p_begin <= 16)
        InsertionSort(p_begin, p_end, p_comp);
    else if (p_currDeep >= p_maxiDeep)
        HeapSort(p_begin, p_end, p_comp);
    else 
    {
        _RanIt mid = partition(p_begin, p_end, p_comp);
        sort(p_begin, mid, p_comp, p_currDeep + 1, p_maxiDeep);
        sort(mid + 1, p_end, p_comp, p_currDeep + 1, p_maxiDeep);
    }
}

template<class _RanIt, class _Comp>
void sort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    size_t len = p_end - p_begin;
    size_t log2 = 0;
    while ((1 << log2) < len) ++log2;
    sort(p_begin, p_end, p_comp, 0, log2);
}

template<class _RanIt>
void sort(_RanIt p_begin, _RanIt p_end)
{
    sort(p_begin, p_end, Less());
}

template<class _RanIt>
void sort(_RanIt p_begin, size_t p_cnt)
{
    sort(p_begin, p_begin + p_cnt);
}

}
#endif
