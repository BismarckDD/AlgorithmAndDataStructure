#ifndef _list_h_
#define _list_h_

template<typename TYPE>
class ListNode
{
public:
    TYPE data;
    ListNode<TYPE> *next;
    ListNode<TYPE> *prev;
    ListNode<TYPE>():
        next(NULL),
        prev(NULL){}
    ~ListNode<TYPE>()
    {
        next = NULL;
        prev = NULL;
    }
};

template<typename TYPE>
class List
{
public:
    virtual bool remove(TYPE ) = 0;
    virtual bool add(TYPE ) = 0;
    virtual ListNode<TYPE>* find(TYPE ) = 0;
    virtual ListNode<TYPE>* reverse() = 0;
    virtual void clear() = 0;
    virtual void show() const = 0;
    virtual size_t size() const = 0;
};

#endif
