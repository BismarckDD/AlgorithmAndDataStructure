/*************************************************************************
 > File Name: Heap.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月20日 星期六 02时02分41秒
 ************************************************************************/

#ifndef _HEAP_H_
#define _HEAP_H_

#include <HeapSort.h>

namespace stdcs
{

template<class _Ty, class _Comp = Less>
class Heap
{
public:
    using value_type = _Ty;
    using const_value_type = const value_type;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;

    Heap(size_t p_capacity = 256)
    {
        m_capacity = p_capacity;
        m_first = (iterator)malloc(sizeof(_Ty) * m_capacity);
        m_last = m_first;
        if (m_first == NULL)
            exit(-1);
    }

    ~Heap()
    {
        if(m_first != NULL)
        {
            free(m_first);
            m_first = NULL;
            m_last = NULL;
        }
        m_capacity = 0;
    }

    reference top()
    {
        return *m_first;
    }

    /* void push(value_type p_key)
    {
        if(m_first + m_capacity == m_last) 
            _extend_size_();
        m_last++;
        *(m_last - 1) = p_key;
        AdjustUpFromTarget(m_first, m_last - 1, m_last, m_comp);
    } */

    void push(const_reference p_key)
    {
        if(m_first + m_capacity == m_last) 
            _extend_size_();
        m_last++;
        *(m_last - 1) = p_key;
        AdjustUpFromTarget(m_first, m_last - 1, m_last, m_comp);
    }

    /* reference pop()
    {
        swap(*m_first, *(m_last - 1));
        m_last--;
        AdjustDownFromTarget(m_first, m_first, m_last, m_comp);
        return *m_last;
    } */

    const_reference pop()
    {
        swap(*m_first, *(m_last - 1));
        m_last--;
        AdjustDownFromTarget(m_first, m_first, m_last, m_comp);
        return *m_last;
    }

    bool empty()
    {
        return m_last == m_first;
    }

    size_t size()
    {
        return m_last - m_first;
    }

    size_t capacity()
    {
        return m_capacity;
    }

private:
    iterator m_first;
    iterator m_last;
    size_t m_capacity;
    _Comp m_comp;

    void _extend_size_()
    {
        m_first = (iterator)realloc(m_first, sizeof(_Ty) * (m_capacity << 1));
        m_last = m_first + m_capacity;
        m_capacity <<= 1;
    }
};

}

#endif


