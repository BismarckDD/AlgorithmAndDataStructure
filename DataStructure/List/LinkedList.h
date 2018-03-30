/*************************************************************************
 > File Name: LinkedList.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月02日 星期四 14时00分54秒
 ************************************************************************/

#ifndef _linked_list_h_
#define _linked_list_h_

#include <List.h>

template<class _Ty, class _Node = ListNode<_Ty>>
class LinkedList : public List<_Ty>
{ 
public:

    typedef typename List<_Ty>::value_type value_type;
    typedef typename List<_Ty>::const_value_type const_value_type;
    typedef typename List<_Ty>::reference reference;
    typedef typename List<_Ty>::const_reference const_reference;
    typedef typename List<_Ty>::pointer ponter;
    typedef typename List<_Ty>::const_pointer const_ponter;

    LinkedList<_Ty, _Node>()
        : m_size(0), m_head(NULL), m_tail(NULL) {}

    LinkedList<_Ty, _Node>(const _Ty* p_begin, const _Ty* p_end)
        : m_size(0), m_head(NULL), m_tail(NULL)
    {
        init(p_begin, p_end);
    }

    virtual ~LinkedList<_Ty, _Node>()
    {
        clear();
    }

    virtual size_t size() const { return m_size; }
    virtual bool remove(const_reference);
    virtual bool add(const_reference);
    virtual _Node* find(const_reference);
    virtual _Node* reverse();
    virtual void clear();
    virtual void show() const;
protected:
    void  init(const _Ty* p_begin, const _Ty* p_end);
    _Node* m_head;
    _Node* m_tail;
    size_t m_size;
};

template<class _Ty, class _Node>
void LinkedList<_Ty, _Node>::clear()
{
    if (m_head == NULL) return ;
    _Node *curr = m_head;
    _Node *prev = NULL;
    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    prev = NULL;
    curr = NULL;
    m_head = NULL;
    m_size = 0;
}

template<class _Ty, class _Node>
void LinkedList<_Ty, _Node>::init(const _Ty* p_begin, const _Ty* p_end)
{
    assert(m_head == NULL);

    if (p_begin >= p_end) return;
    _Node *prev, *curr;
    _Ty data;

    m_head = new _Node();
    m_head->data = *p_begin++;
    prev = m_head;
    ++m_size;

    while (p_begin != p_end)
    {
        curr = new _Node();
        curr->data = *p_begin++;
        prev->next = curr;
        prev = curr;
        ++m_size;
    }
    prev->next = NULL;
}

template<class _Ty, class _Node>
bool LinkedList<_Ty, _Node>::add(const_reference p_key)
{
    //cout << "add" << endl;
    _Node *head = m_head, *prev, *curr = m_head, *next;
    next = new _Node();
    next->data = p_key;
    if (head == NULL)
    {
        head = next;
        head->next = NULL;
        ++m_size;
        m_head = head;
        return true;
    }
    while ((next->data > curr->data) && (curr->next != NULL))
    {
        prev = curr;
        curr = curr->next;
    }

    if (next->data <= curr->data)
    {
        if (curr == head)
        {
            head = next;
            next->next = curr;
        }
        else
        {
            prev->next = next;
            next->next = curr;
        }
    }
    else
    {
        curr->next = next;
        next->next = NULL;
    }
    ++m_size;
    m_head = head;
    return true;
}
template<class _Ty, class _Node>
bool LinkedList<_Ty, _Node>::remove(const_reference p_key)
{
    if (NULL == m_head) return true;
    _Node *head = m_head, *prev, *curr = m_head;
    while (p_key != curr->data && curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (p_key == curr->data)
    {
        if (curr == head)
        {
            head = head->next;
            m_head = head;
        }
        else
        {
            prev->next = curr->next;
        }
        --m_size;
        delete curr;
        return true;
    }
    else
    {
        return false;
    }
}

template<class _Ty, class _Node>
_Node* LinkedList<_Ty, _Node>::find(const_reference p_key)
{
    _Node *head = m_head;
    while (head)
    {
        if (head->data == p_key)
        {
            break;
        }
        head = head->next;
    }
    return head;
}

template<class _Ty, class _Node>
_Node* LinkedList<_Ty, _Node>::reverse()
{
    _Node *head = m_head;
    if (head == NULL || head->next == NULL)
        return head;
    _Node *prev, *curr, *next;
    prev = head;
    curr = head->next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = NULL;
    head = prev;
    m_head = head;
    return head;
}

template<class _Ty, class _Node>
void LinkedList<_Ty, _Node>::show() const
{
    _Node *p = m_head;
    while (p != NULL)
    {
        std::cout << p->data << ", ";
        p = p->next;
    }
    std::cout << std::endl;
}


#endif
