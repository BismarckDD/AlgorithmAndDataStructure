#ifndef _count_sort_h_
#define _count_sort_h_

#include <Common.hpp>

namespace stdcs
{

template<class _RanIt>
void CountSort(_RanIt p_begin, _RanIt p_end)
{

    typedef typename iterator_traits<_RanIt>::value_type _Type;
    typedef typename iterator_traits<_RanIt>::pointer_type _Ptr;
    auto bucket = *p_begin;
    _Ptr buckets = new _Type[MAXN];
    for (_RanIt it = p_begin; it != p_end; ++it)
        ++buckets[*it], bucket = bucket > *it ? bucket : *it;

    _RanIt it = p_begin;
    for (uint64_t i = 0; i <= bucket; ++i)
    {
        while (buckets[i])
        {
            *it++ = i;
            --buckets[i];
        }
    }
    delete[] buckets;
}

template<class _RanIt>
void CountSort(_RanIt p_begin, size_t p_cnt)
{
    CountSort(p_begin, p_begin + p_cnt);
}

}

#endif
