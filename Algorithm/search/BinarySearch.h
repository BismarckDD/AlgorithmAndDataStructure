#ifndef _binary_search_h_
#define _binary_search_h_

namespace stdcs
{

template<class _RanIt, class _Ty>
_RanIt bsearch(_RanIt p_begin, _RanIt p_end, const _Ty& p_key)
{
    _RanIt mid;
    while (p_begin < p_end)
    {
        mid = p_begin + ((p_end - p_begin) >> 1);
        if (*mid == p_key) {
            return mid;
        } else if (*mid < p_key) {
            p_begin = mid + 1;
        } else {
            p_end = mid;
        }
    }
    return p_end;
}

template<class _RanIt, class _Ty>
_RanIt bsearch(_RanIt p_begin, size_t p_cnt, const _Ty& p_key)
{
    return bsearch(p_begin, p_begin + p_cnt, p_key);
}

template<class _RanIt, class _Ty>
_RanIt lower_bound(_RanIt p_begin, _RanIt p_end, const _Ty& p_key)
{
    _RanIt mid;
    while (p_begin < p_end) 
    {
        mid = p_begin + ((p_end - p_begin) >> 1);
        if (*mid < p_key) {
            p_begin = mid + 1;
        } else {
            p_end = mid;
        }
    }
    return p_begin;
}

template<class _RanIt, class _Ty>
_RanIt upper_bound(_RanIt p_begin, _RanIt p_end, const _Ty& p_key)
{

    _RanIt mid;
    while (p_begin < p_end) 
    {
        mid = p_begin + ((p_end - p_begin) >> 1);
        if (*mid <= p_key) {
            p_begin = mid + 1;
        } else {
            p_end = mid;
        }
    }
    return p_begin;
}

}

#endif
