/*************************************************************************
 > File Name: BinarySearch1.h 普通二分查找
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _binary_search1_h_
#define _binary_search1_h_

namespace stdcs
{

template<class _RanIt, class _Ty>
_RanIt BinarySearch1(_RanIt p_begin, _RanIt p_end, const _Ty& p_key)
{
    _RanIt mid, end = p_end;
    while (p_begin < p_end)
    {
        mid = p_begin + ((p_end - p_begin) >> 1);
        if (*mid == p_key)
            return mid;
        else if (*mid < p_key)
            p_begin = mid + 1;
        else if (*mid > p_key)
            p_end = mid;
        else
            continue;
    }
    return end;
}

}

#endif
