/*************************************************************************
 > File Name: HeapSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _heap_sort_h_
#define _heap_sort_h_

#include <Common.hpp>

namespace stdcs
{

template<class _RanIt, class _Comp>
void AdjustUpFromTarget(_RanIt p_begin, _RanIt p_target, _RanIt p_end, _Comp& p_comp)
{
    int s = p_target - p_begin;
    int t = (s - 1) >> 1;
    auto temp = std::move(*(p_begin + s));
    while (t >= 0)
    {
        if (p_comp(*(p_begin + t), temp))
        {
            *(p_begin + s) = *(p_begin + t);
            s = t;
            t = (s - 1) >> 1;
        }
        else
            break;
    }
    *(p_begin + s) = std::move(temp);
}

template<class _RanIt, class _Comp>
void AdjustUp(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    AdjustUpFromTarget(p_begin, p_end - 1, p_end, p_comp);
}

template<class _RanIt, class _Comp>
void AdjustDownFromTarget(_RanIt p_begin, _RanIt p_target, _RanIt p_end, const _Comp& p_comp)
{
    int diff = p_end - p_begin;
    int s = p_target - p_begin;
    int t = (s << 1) | 1;
    auto temp = std::move(*(p_begin + s));
    while (t < diff)
    {
        if (t + 1 < diff && p_comp(*(p_begin + t), *(p_begin + t + 1)))
            t = t + 1;

        if (p_comp(temp, *(p_begin + t)))
        {
            *(p_begin + s) = *(p_begin + t);
            s = t;
            t = (t << 1) | 1;
        }
        else
            break;
    }
    *(p_begin + s) = std::move(temp);
}

template<class _RanIt, class _Comp>
void AdjustDown(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    AdjustDownFromTarget(p_begin, p_begin, p_end, p_comp);
}

template<class _RanIt, class _Comp>
void Make_Heap(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    int _bottom = p_end - p_begin;
    if (_bottom >= 2)
    {
        _RanIt it = p_begin + (_bottom >> 1) - 1;
        for (; it >= p_begin; it--)
            AdjustDownFromTarget(p_begin, it, p_end, p_comp);
    }
}

template<class _RanIt>
void Make_Heap(_RanIt p_begin, _RanIt p_end)
{
    Make_Heap(p_begin, p_end, Less());
}

template<class _RanIt, class _Comp>
void Make_Heap(_RanIt p_begin, size_t p_cnt, const _Comp& p_comp)
{
    Make_Heap(p_begin, p_begin + p_cnt, p_comp);
}

template<class _RanIt>
void Make_Heap(_RanIt p_begin, size_t p_cnt)
{
    Make_Heap(p_begin, p_begin + p_cnt, Less());
}

template<class _RanIt, class _Comp>
void Push_Heap(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{

}

template<class _RanIt>
void Push_Heap(_RanIt p_begin, _RanIt p_end)
{
    Push_Heap(p_begin, p_end, Less());
}

template<class _RanIt, class _Comp>
void Pop_Heap(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{

}

template<class _RanIt>
void Pop_Heap(_RanIt p_begin, _RanIt p_end)
{
    return Pop_Heap(p_begin, p_end, Less());
}

template<class _RanIt, class _Comp>
void HeapSort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    Make_Heap(p_begin, p_end, p_comp);
    while(2 <= p_end - p_begin)
    {
        stdcs::swap(*p_begin, *(p_end - 1));
        p_end--;
        AdjustDown(p_begin, p_end, p_comp);
    }
}

template<class _RanIt>
void HeapSort(_RanIt p_begin, _RanIt p_end)
{
    HeapSort(p_begin, p_end, Less());
}

template<class _RanIt, class _Comp>
void HeapSort(_RanIt p_begin, size_t p_cnt, const _Comp& p_comp)
{
    HeapSort(p_begin, p_begin + p_cnt, p_comp);
}

template<class _RanIt>
void HeapSort(_RanIt p_begin, size_t p_cnt)
{
    HeapSort(p_begin, p_begin + p_cnt);
}

}

#endif

