/*************************************************************************
 > File Name: DeLinkedList.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月02日 星期四 14时00分54秒
 ************************************************************************/

#ifndef _delinked_list_h_
#define _delinked_list_h_

#include <List.h>

template<class _Ty, class _Node = ListNode<_Ty>>
class DeLinkedList : public List<_Ty>
{
public:
    typedef typename List<_Ty>::value_type value_type;
    typedef typename List<_Ty>::const_value_type const_value_type;
    typedef typename List<_Ty>::reference reference;
    typedef typename List<_Ty>::const_reference const_reference;
    typedef typename List<_Ty>::pointer ponter;
    typedef typename List<_Ty>::const_pointer const_ponter;

    DeLinkedList<_Ty, _Node>() 
        : m_size(0), m_head(NULL), m_tail(NULL) {}

    virtual ~DeLinkedList<_Ty, _Node>()
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
    _Node* m_head;
    _Node* m_tail;
    size_t m_size;
};

template<class _Ty, class _Node>
void DeLinkedList<_Ty, _Node>::clear()
{
    if (m_head == NULL) return ;
    _Node *curr = m_head;
    _Node *prev = NULL;
    while (curr -> next != m_head)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    delete curr;
    curr = NULL;
    prev = NULL;
}

template<class _Ty, class _Node>
bool DeLinkedList<_Ty, _Node>::add(const_reference p_key)
{
    _Node *head = m_head, *prev, *curr = head, *next;
    next = new _Node();
    next->data = p_key;
    next->prev = NULL;
    next->next = NULL;
    if (head == NULL)
    {
        head = next;
        m_head = head;
        ++m_size;
        return true;
    }
    while (next->data > curr->data && curr->next != NULL)
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
            curr->prev = next;
        }
        else
        {
            prev->next = next;
            next->prev = prev;
            next->next = curr;
            curr->prev = next;
        }

    }
    else
    {
        curr->next = next;
        next->prev = curr;
    }
    m_head = head;
    ++m_size;
    return true;
}

template<class _Ty, class _Node>
bool DeLinkedList<_Ty, _Node>::remove(const_reference p_key)
{
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
            if (head)
                head->prev = NULL;
            m_head = head;
        }
        else
        {
            prev->next = curr->next;
            if (curr->next)
                curr->next->prev = prev;
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
_Node* DeLinkedList<_Ty, _Node>::find(const_reference p_key)
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
_Node* DeLinkedList<_Ty, _Node>::reverse()
{
    _Node *head = m_head;
    if (head == NULL || head->next == NULL)
        return head;
    _Node *prev, *curr, *next;
    prev = head;
    curr = head->next;
    head->prev = curr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head->next = NULL;
    head = prev;
    m_head = head;
    return head;
}

template<class _Ty, class _Node>
void DeLinkedList<_Ty, _Node>::show() const
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
