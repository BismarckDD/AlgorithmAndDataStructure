/*************************************************************************
 > File Name: QuickSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _quick_sort_h_
#define _quick_sort_h_

#include"../../Common.hpp"

namespace stdcs
{

template<class _RanIt, class _Comp>
_RanIt partition(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    auto key = *p_begin;
    p_end = p_end - 1;
    while(p_begin < p_end)
    {
        while(p_begin < p_end && p_comp(key, *p_end)) p_end--;
        if (p_begin < p_end) *p_begin = *p_end;
        while(p_begin < p_end && p_comp(*p_begin, key)) p_begin++;
        if (p_begin < p_end) *p_end = *p_begin;
    }
    *p_begin = key;
    return p_begin;
}

template<class _RanIt, class _Comp>
void QuickSort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    if (2 <= p_end - p_begin)
    {
        _RanIt p_mid = partition(p_begin, p_end, p_comp);
        QuickSort(p_begin, p_mid, p_comp);
        QuickSort(p_mid + 1, p_end, p_comp);
    }
}

template<class _RanIt>
void QuickSort(_RanIt p_begin, _RanIt p_end)
{
    QuickSort(p_begin, p_end, Less());
}

template<class _RanIt>
void QuickSort(_RanIt p_arr, size_t p_cnt)
{
    QuickSort(p_arr, p_arr + p_cnt);
}

template<class _RanIt, class _Comp>
void QuickSort3Way(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    if (2 <= p_end - p_begin)
    {
        auto pivot = *(p_end - 1);
        _RanIt i = p_begin - 1, j = p_end, p = p_begin - 1, q = p_end;
        while(i < j)
        {
            while (p_comp(*(++i), pivot)) {}
            while (p_comp(pivot, *(--j))) { if(j == p_begin) break; }
            if(i < j)
            {
                swap(*i, *j);
                if (*i == pivot) {p++; swap(*p, *i);}
                if (*j == pivot) {q--; swap(*q, *j);}
            }
        }
        swap(*i, *(p_end-1)); j = i - 1; i = i + 1;
        for (_RanIt k = p_begin; k <= p; k++, j--) swap(*k, *j);
        for (_RanIt k = p_end - 1; k >= q; k--, i++) swap(*i, *k);

        QuickSort3Way(p_begin, j, p_comp);
        QuickSort3Way(i, p_end, p_comp);
    }
}

template<class _RanIt>
void QuickSort3Way(_RanIt p_begin, _RanIt p_end)
{
    QuickSort3Way(p_begin, p_end, Less());
}

}

#endif
