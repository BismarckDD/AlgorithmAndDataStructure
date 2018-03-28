/*************************************************************************
 > File Name: MergeSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _merge_sort_h_
#define _merge_sort_h_

#include"../../Common.hpp"

namespace stdcs
{

template<class _RanIt, class _Comp>
void Merge(_RanIt p_begin, _RanIt p_mid, _RanIt p_end, _RanIt p_temp, const _Comp& p_comp)
{
    _RanIt st1 = p_begin, ed1 = p_mid, st2 = p_mid, ed2 = p_end, t = p_temp, s;
    while (st1 < ed1 && st2 < ed2)
    {
        if (p_comp(*st1, *st2)) *t++ = *st1++;
        else *t++ = *st2++;
    }
    while (st1 < ed1) *t++ = *st1++;
    while (st2 < ed2) *t++ = *st2++;
    size_t len = p_end - p_begin;
    for (s = p_begin, t = p_temp; s < p_end;) *s++ = *t++;
}

template<class _RanIt, class _Comp>
void MergeSort(_RanIt p_begin, _RanIt p_end, _RanIt p_temp, const _Comp& p_comp)
{
    if(2 <= p_end - p_begin)
    {
        size_t len = (p_end - p_begin);
        _RanIt mid = p_begin + (len >> 1);
        MergeSort(p_begin, mid, p_temp, p_comp);
        MergeSort(mid, p_end, p_temp, p_comp);
        Merge(p_begin, mid, p_end, p_temp, p_comp);
    }
}

template<class _RanIt, class _Comp>
void MergeSort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    if (p_begin >= p_end) return;
    size_t len = p_end - p_begin;
    _RanIt temp = (_RanIt)new char[sizeof(*p_begin)*len];
    // _RanIt temp = new _RanIt::value_type[len];
    MergeSort(p_begin, p_end, temp, p_comp);
    delete[] temp;
}

template<class _RanIt>
void MergeSort(_RanIt p_begin, _RanIt p_end)
{
    MergeSort(p_begin, p_end, Less());
}

template<class _RanIt>
void MergeSort(_RanIt p_begin, size_t p_cnt)
{
    MergeSort(p_begin, p_begin + p_cnt);
}

}

#endif
