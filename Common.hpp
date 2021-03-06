#ifndef  _COMMON_HPP_
#define  _COMMON_HPP_


#define REPORT_ERROR_AND_EXIT \
{                             \
    printf("ERROR!\n");       \
    return -1;                \
}

namespace stdcs
{

const size_t MAXN = 1000000;
size_t buckets[MAXN] = {0};

template<class Iterator>
struct iterator_traits
{
    typedef ptrdiff_t difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer_type pointer_type;
    typedef typename Iterator::reference_type reference_type;
};

template<class _Ty>
struct iterator_traits<_Ty*>
{
    typedef ptrdiff_t difference_type;
    typedef _Ty value_type;
    typedef _Ty* pointer_type;
    typedef _Ty& reference_type;
};

template <class _Ty> struct remove_reference        {typedef _Ty type;};
template <class _Ty> struct remove_reference<_Ty&>  {typedef _Ty type;};
template <class _Ty> struct remove_reference<_Ty&&> {typedef _Ty type;};

template <class _Ty>
typename remove_reference<_Ty>::type&& move(_Ty&& p_t)
{
    typedef typename remove_reference<_Ty>::type _Up;
    return static_cast<_Up&&>(p_t);
}

template <class _Ty>
_Ty&& forward(typename remove_reference<_Ty>::type& p_t)
{
    return static_cast<_Ty&&>(p_t);
}

template<class _Ty>
void swap(_Ty& p_a, _Ty& p_b)
{
    _Ty p_c(stdcs::move(p_a));
    p_a = stdcs::move(p_b);
    p_b = stdcs::move(p_c);
}

struct Equal
{
    template<class _Ty>
    bool operator() (const _Ty& x, const _Ty& y) const { return x == y; }
};

struct Less
{
    template<class _ty>
    bool operator() (const _ty& x, const _ty& y) const { return x < y; }
    // typedef _ty first_argument_type;
    // typedef _ty second_argument_type;
    // typedef bool result_type;
};

struct LessOrEqual
{
    template<class _Ty>
    bool operator() (const _Ty& x, const _Ty& y) const { return x <= y; }
    // typedef _Ty first_argument_Type;
    // typedef _Ty second_argument_Type;
    // typedef bool result_type;
};

struct Greater
{
    template<class _Ty>
    bool operator() (const _Ty& x, const _Ty& y) const { return x > y; }
    // typedef _Ty first_argument_Type;
    // typedef _Ty second_argument_Type;
    // typedef bool result_type;
};

struct GreaterOrEqual
{
    template<class _Ty>
    bool operator() (const _Ty& x, const _Ty& y) const { return x >= y; }
    // typedef _Ty first_argument_Type;
    // typedef _Ty second_argument_Type;
    // typedef bool result_type;
};

}

#endif // ! _COMMON_HPP_

