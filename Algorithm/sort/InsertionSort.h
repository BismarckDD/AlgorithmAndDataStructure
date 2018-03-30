/*************************************************************************
 > File Name: InsertionSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _insertion_sort_h_
#define _insertion_sort_h_

#include <Common.hpp>

namespace stdcs
{

template<class _RanIt, class _Comp>
void InsertionSort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    for(_RanIt i = p_begin + 1, j; i <= p_end - 1; ++i)
    {
        auto key = *i;
        for(j = i; j != p_begin && p_comp(key, *(j - 1)); --j)
            *j = *(j - 1);
        *j = key;
    }
}

template<class _RanIt>
void InsertionSort(_RanIt p_begin, _RanIt p_end)
{
    InsertionSort(p_begin, p_end, Less());
}

template<class _RanIt>
void InsertionSort(_RanIt p_begin, size_t p_cnt)
{
    InsertionSort(p_begin, p_begin + p_cnt);
}

}

#endif
