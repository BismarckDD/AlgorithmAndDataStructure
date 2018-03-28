/*************************************************************************
 > File Name: BinarySearch7.h 返回所有值大于等于key的元素的最小下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _binary_search7_h_
#define _binary_search7_h_

namespace stdcs
{

template<class _RanIt, class _Ty>
_RanIt BinarySearch7(_RanIt p_begin, _RanIt p_end, const _Ty& p_key)
{
    _RanIt mid;
    while (p_begin < p_end)
    {
        mid = p_begin + ((p_end - p_begin) >> 1);
        if (*mid < p_key)
            p_begin = mid + 1;
        else
            p_end = mid;
    }
    return p_begin;
}

}

#endif
