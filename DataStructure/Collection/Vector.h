#include <Collection.h>

namespace stdc
{

template<class _Ty, class _Alloc=allocator>
class Vector : public Collection<_Ty, _Alloc>
{
public:

    reference front();
    const_reference front() = 0; 

    reference back();
    const_reference back();

    void push_front(const_reference p_elem);
    void push_back(const_reference p_elem);

    reference pop_front();
    const_reference pop_front();

    reference pop_back();
    const_reference pop_back();

private:

};


template<class _Ty, class _Alloc>
reference Vector<_Ty, _Alloc>::front()
{
    return _array[0];
}


template<class _Ty, class _Alloc>
const_reference Vector<_Ty, _Alloc>::front()
{
    return _array[0];

}


template<class _Ty, class _Alloc>
reference Vector<_Ty, _Alloc>::back()
{
    return _array[0];
}


template<class _Ty, class _Alloc>
const_reference Vector<_Ty, _Alloc>::back()
{
    return _array[0];

}


template<class _Ty, class _Alloc>
reference front()
template<class _Ty, class _Alloc>
reference front()
{
    return _array[0];
}
