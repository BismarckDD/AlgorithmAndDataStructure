#ifndef _list_h_
#define _list_h_

template<class _Ty>
class ListNode
{
public:
    _Ty data;
    ListNode<_Ty> *next;
    ListNode<_Ty> *prev;
    ListNode<_Ty>(): next(NULL), prev(NULL) {}
    ~ListNode<_Ty>() { next = NULL, prev = NULL; }
};

template<class _Ty, class _Node = ListNode<_Ty>>
class List
{
public:
    typedef _Ty value_type;
    typedef const _Ty const_value_type;
    typedef _Ty& reference;
    typedef const _Ty& const_reference;
    typedef _Ty* pointer;
    typedef const _Ty* const_pointer;

    virtual bool remove(const_reference) = 0;
    virtual bool add(const_reference) = 0;
    virtual _Node* find(const_reference) = 0;
    virtual _Node* reverse() = 0;
    virtual void clear() = 0;
    virtual void show() const = 0;
    virtual size_t size() const = 0;
};

#endif
