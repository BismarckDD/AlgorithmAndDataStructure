#ifndef _radix_sort_h_
#define _radix_sort_h_

#include <Common.hpp>

namespace stdcs
{

size_t internal_pow(size_t p_base, size_t p_pow)
{
    size_t re = 1;
    while (p_pow)
    {
        if (p_pow & 0x1) re *= p_base;
        p_pow >>= 1;
        p_base = p_base * p_base;
    }
    return re;
}

template<class _RanIt>
void RadixSort(_RanIt p_begin, size_t p_cnt, size_t radix = 16, size_t digit = 8)
{
    typedef typename iterator_traits<_RanIt>::value_type value_type;
    _RanIt res = new value_type[p_cnt];
    _RanIt con = new value_type[radix];
    size_t temp;
    size_t pow, radix1 = radix - 1; // accelerate mod operation.
    for (size_t i = 0; i < digit; ++i)
    {
        pow = internal_pow(radix, i);
        for(int j = 0; j < radix; ++j) *(con + j) = 0;
        for(int j = 0; j < p_cnt; ++j) ++con[(p_begin[j] / pow) & radix1];
        for(int j = 1; j < radix; ++j) con[j] += con[j - 1];
        for(int j = p_cnt - 1; j >= 0; --j) 
        {
            temp = (p_begin[j] / pow) & radix1;
            res[con[temp]-1] = p_begin[j];
            --con[temp];
        }
        for(int j = 0; j < p_cnt; ++j) *(p_begin + j) = res[j];
    }
    delete[] res;
    res = NULL;
    delete[] con;
    con = NULL;
}


template<class _RanIt>
void RadixSort(_RanIt p_begin, size_t p_cnt)
{
    RadixSort(p_begin, p_cnt, 32, 7);
}

}

#endif
