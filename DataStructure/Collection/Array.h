#include "Collection.h"

namespace stdc
{

template<class _ty, class _alloc=allocator>
class Array : public Collection<_ty, _alloc>
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


template<class _ty, class _alloc=allocator>
reference Array<_ty, _alloc>::front()
{
    return _array[0];
}


template<class _ty, class _alloc=allocator>
const_reference Array<_ty, _alloc>::front()
{
    return _array[0];

}


template<class _ty, class _alloc=allocator>
reference Array<_ty, _alloc>::back()
{
    return _array[0];
}


template<class _ty, class _alloc=allocator>
const_reference Array<_ty, _alloc>::back()
{
    return _array[0];

}


template<class _ty, class _alloc=allocator>
reference front()
template<class _ty, class _alloc=allocator>
reference front()
{
    return _array[0];
}
