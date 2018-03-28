/*************************************************************************
 > File Name: LinkedList.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月02日 星期四 14时00分54秒
 ************************************************************************/

#ifndef _linked_list_h_
#define _linked_list_h_

#include"List.h"

template<typename TYPE>
class LinkedList : public List<TYPE>
{ 
    public:
        LinkedList<TYPE>()
        {
            m_size = 0;
            m_head = NULL;
        }
        
        LinkedList<TYPE>(TYPE arr[])
        {
            m_size = 0;
            m_head = Create(arr);
        }

        virtual ~LinkedList<TYPE>()
        { 
            Free(); 
        }
        
        virtual size_t size() const { return m_size; }
        virtual size_t length() const;
        virtual bool remove(TYPE key);
        virtual bool add(TYPE key);
        virtual ListNode<TYPE>* find(TYPE );
        virtual ListNode<TYPE>* reverse();
        virtual void clear() { Free(); };
        virtual void show() const;
    protected:
        virtual void Free();
        ListNode<TYPE>* Create();
        ListNode<TYPE> *m_head;
        size_t m_size;
};

template<typename TYPE>
void LinkedList<TYPE>::Free()
{
    if (m_head == NULL)
        return ;
    ListNode<TYPE> *curr = m_head;
    ListNode<TYPE> *prev = NULL;
    while(curr != NULL)
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

template<typename TYPE>
ListNode<TYPE> * LinkedList<TYPE>::Create()
{
    ListNode<TYPE> *head, *prev, *curr;
    TYPE data;
    if(cin >> data)
    {
        head = new ListNode<TYPE>();
        head->data=data;
        prev=head;
        ++m_size;
    }
    else
        return NULL;
    while(cin>>data)
    {
        curr = new ListNode<TYPE>();
        curr->data=data;
        prev->next=curr;
        prev=curr;
        ++m_size;
    }
    prev->next = NULL;
    return head;
}

template<typename TYPE>
bool LinkedList<TYPE>::add(TYPE key)
{
    //cout << "add" << endl;
    ListNode<TYPE> *head = m_head, *prev, *curr = m_head, *next;
    next = new ListNode<TYPE>();
    next->data = key;
    if(head == NULL)
    {
        head = next;
        head->next = NULL;
        ++m_size;
        m_head = head;
        return true;
    }
    while( (next->data > curr->data) && (curr->next != NULL) )
    {
        prev = curr;
        curr = curr->next;
    }

    if(next->data <= curr->data)
    {
        if(curr == head)
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
template<typename TYPE>
bool LinkedList<TYPE>::remove(TYPE key)
{
    if(NULL == m_head) return NULL;
    ListNode<TYPE> *head = m_head, *prev, *curr = m_head;
    while(key != curr->data && curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if(key == curr->data)
    {
        if(curr == head)
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


template<typename TYPE>
size_t LinkedList<TYPE>::length() const
{
    size_t len = 0;
    ListNode<TYPE> *p = m_head;
    while(p != NULL)
    {
        p = p->next;
        ++len;
    }
    return len;
}

template<typename TYPE>
ListNode<TYPE> * LinkedList<TYPE>::find(TYPE key)
{
    ListNode<TYPE> *head = m_head;
    while(head)
    {
        if(head->data == key)
        {
            break;
        }
        head = head->next;
    }
    return head;
}

template<typename TYPE>
ListNode<TYPE> *LinkedList<TYPE>::reverse()
{
    ListNode<TYPE> *head = m_head;
    if(head == NULL || head->next == NULL)
        return head;
    ListNode<TYPE> *prev, *curr, *next;
    prev = head;
    curr = head->next;
    while(curr)
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

template<typename TYPE>
void LinkedList<TYPE>::show() const
{
    ListNode<TYPE> *p = m_head;
    while(p != NULL)
    {
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
    
}


#endif
