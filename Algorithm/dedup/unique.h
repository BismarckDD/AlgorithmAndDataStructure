#ifndef _unique_h_
#define _unique_h_

namespace stdcs
{

template<class _RanIt>
_RanIt find_adjacent(_RanIt p_begin, _RanIt p_end)
{
    _RanIt rear = p_begin;
    _RanIt front = p_begin + 1;
    while (front != p_end)
    {
        if (*rear == *front)
            return rear;
        rear++, front++;
    }
    return p_end;
}

template<class _RanIt>
_RanIt unique(_RanIt p_begin, _RanIt p_end)
{
    _RanIt first = find_adjacent(p_begin, p_end);
    _RanIt result = first;

    if (first != p_end)
    {
        ++first;
        while (first != p_end)
        {
            if (*first != *result)
                *(++result) = std::move(*first);
            ++first;
        }
        ++result;
    }
    return result;
}

}

#endif
