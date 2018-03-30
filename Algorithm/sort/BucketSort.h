#ifndef _bucket_sort_h_
#define _bucket_sort_h_

#include <Common.hpp>

namespace stdcs
{

template<class _RanIt>
void BucketSort(_RanIt p_begin, _RanIt p_end)
{
    uint64_t bucket = 0;
    typedef typename iterator_traits<_RanIt>::value_type _Type;
    typedef typename iterator_traits<_RanIt>::pointer_type _Ptr;

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
void BucketSort(_RanIt p_begin, size_t p_cnt)
{
    BucketSort(p_begin, p_begin + p_cnt);
}

}
#endif
