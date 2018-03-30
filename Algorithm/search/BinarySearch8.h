/*************************************************************************
 > File Name: BinarySearch8.h 搜索经过旋转的数组
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/

#ifndef _binary_search8_h_
#define _binary_search8_h_

namespace stdcs
{

template<class _RanIt, class _Ty>
_RanIt BinarySearch8(_RanIt p_begin, _RanIt p_end, const _Ty& p_key)
{
    _RanIt mid, end = p_end;
    while (p_begin < p_end)
    {
        mid = p_begin + ((p_end - p_begin) >> 1);
        if (*mid == p_key) {
            return mid;
        } else if (*mid < p_key) {
            if (*(p_end - 1) >= p_key || *(p_end - 1) < *mid) p_begin = mid + 1;
            else p_end = mid;
        } else if (*mid > p_key) {
            if (*p_begin <= p_key|| *p_begin > *mid) p_end = mid;
            else p_begin = mid + 1;
        } else {
            continue;
        }
    }
    return end;
}

}

#endif
