/*************************************************************************
 > File Name: SelectionSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _selection_sort_h_
#define _selection_sort_h_

#include <Common.hpp>

namespace stdcs
{

template<class _RanIt, class _Comp>
void SelectionSort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    for (_RanIt i = p_begin, j, k; i < p_end - 1; ++i)
    {
        auto key = *i;
        k = i;
        for(j = i + 1; j <= p_end - 1; ++j)
        {
            p_comp(*j, key) ? key = *j, k = j : k = k ;
        }
        if (k != i) stdcs::swap(*k, *i);
    }
}

template<class _RanIt>
void SelectionSort(_RanIt p_begin, _RanIt p_end)
{
    SelectionSort(p_begin, p_end, Less());
}

template<class _RanIt>
void SelectionSort(_RanIt p_begin, size_t p_cnt)
{
    SelectionSort(p_begin, p_begin + p_cnt);
}

}

#endif
