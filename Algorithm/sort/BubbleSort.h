/*************************************************************************
 > File Name: BubbleSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#ifndef _bubble_sort_h_
#define _bubble_sort_h_

#include "../../Common.hpp"

namespace stdcs
{

template<class _RanIt, class _Comp>
void BubbleSort(_RanIt p_begin, _RanIt p_end, const _Comp& p_comp)
{
    bool flag;
    for(_RanIt it = p_begin; it <= p_end - 2; ++it)
    {
        flag = false;
        for(_RanIt jt = p_end - 1; jt >= it + 1; --jt)
        {
            if (p_comp(*jt, *(jt-1)))
            {
                *jt = (*jt) ^ *(jt-1);
                *(jt-1) = (*jt) ^ *(jt-1);
                *jt = (*jt) ^ *(jt-1);
                flag = true;
            }
        }
        if(!flag) return ;
    }
}

template<class _RanIt>
void BubbleSort(_RanIt p_begin, _RanIt p_end)
{
    BubbleSort(p_begin, p_end, Less());
}

template<class _RanIt>
void BubbleSort(_RanIt p_begin, size_t p_cnt)
{
    BubbleSort(p_begin, p_begin + p_cnt);
}

}

#endif

