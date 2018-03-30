#ifndef __generate_base_h_
#define __generate_base_h_

#include <cstdlib>
#include <boost/shared_array.hpp>
#include <Common.hpp>

namespace stdcs
{

template<class _ty>
boost::shared_array<_ty> GenerateBaseRandom(const size_t p_cnt)
{
    boost::shared_array<_ty> arr(new _ty[p_cnt]);
    for(size_t i = 0; i < p_cnt; ++i) arr[i] =(_ty)(i);
    for(size_t i = 0, j; i < p_cnt; ++i) 
    {
        j = i + (rand() * rand()) % (p_cnt - i); 
        stdcs::swap(arr[i], arr[j]);
    }
    return arr;

}

// Generate random numbers, all numbers between [0, 32767]
// So, if the size of array is large than 32768, it will indeed have replica 
template<class _ty>
boost::shared_array<_ty> GenerateBaseWithReplica(const size_t p_cnt)
{
    boost::shared_array<_ty> arr(new _ty[p_cnt]);
    for (size_t i = 0; i < p_cnt; ++i) arr[i] = (_ty)(rand());
    return arr;
}

// Generate all numbers are equal.
template<class _ty>
boost::shared_array<_ty> GenerateBaseEqually(const size_t p_cnt)
{
    boost::shared_array<_ty> arr(new _ty[p_cnt]);
    _ty key = (_ty)(rand());
    for (size_t i = 0; i < p_cnt; ++i) arr[i] = key;
    return arr;
}

}

#endif
