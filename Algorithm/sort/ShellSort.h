/*************************************************************************
 > File Name: ShellSort.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时00分12秒
 ************************************************************************/

#ifndef _shell_sort_h_
#define _shell_sort_h_

namespace stdcs
{

template<class _RanIt, class _Comp>
void ShellPass(_RanIt p_begin, _RanIt p_end, const _Comp& comp, size_t p_diff)
{
    for (_RanIt j, i = p_begin + p_diff; i <= p_end - 1; ++i)
    {
        auto key = *i;
        for (j = i; p_begin + p_diff <= j  && comp(key , *(j - p_diff)); j = j - p_diff)
            *j = *(j - p_diff);
        *j = key;
    }
}

template<class _RanIt, class _Comp>
void ShellSort(_RanIt p_begin, _RanIt p_end, const _Comp& comp, size_t diff = 5)
{
    size_t increment = diff;
    do {
        increment = increment / 3 + 1;
        ShellPass(p_begin, p_end, comp, increment);
    } while (increment > 1);
}

template<class _RanIt>
void ShellSort(_RanIt p_begin, _RanIt p_end)
{
    ShellSort(p_begin, p_end, Less());
}

template<class _RanIt>
void ShellSort(_RanIt p_begin, size_t p_cnt)
{
    ShellSort(p_begin, p_begin + p_cnt);
}

}

#endif
