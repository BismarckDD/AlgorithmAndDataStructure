/*************************************************************************
 > File Name: DeLinkedList.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月02日 星期四 14时00分54秒
 ************************************************************************/

#ifndef _delinked_list_h_
#define _delinked_list_h_

#include"List.h"

template<typename TYPE>
class DeLinkedList : public List<TYPE>
{
    public:	
        DeLinkedList<TYPE>()
		{
			m_size = 0;
			m_head = NULL;
		}
		
        virtual ~DeLinkedList<TYPE>()
        {
            Free();
        }
		
        virtual size_t size() const { return m_size; }
		size_t length();
        virtual bool remove(TYPE );
		virtual bool add(TYPE );
        virtual ListNode<TYPE>* find(TYPE );
		virtual ListNode<TYPE>* reverse();
        virtual void clear() { Free(); }
		virtual void show() const;
	
    protected:
		
        virtual void Free();
		ListNode<TYPE> *m_head;
		size_t m_size;
};

template<typename TYPE>
void DeLinkedList<TYPE>::Free()
{
    if (m_head == NULL) 
        return ;
	ListNode<TYPE> *curr = m_head;
	ListNode<TYPE> *prev = NULL;
    ListNode<TYPE> *head = m_head;
	while(curr != NULL)
	{
		prev = curr;
		curr = curr->next;
		delete prev;
	}
    curr = NULL;
    prev = NULL;
    head = NULL;
}

template<typename TYPE>
bool DeLinkedList<TYPE>::add(TYPE key)
{
	ListNode<TYPE> *head = m_head, *prev, *curr = head, *next;
	next = new ListNode<TYPE>();
	next->data = key;
    next->prev = NULL;
    next->next = NULL;
	if(head == NULL)
	{
		head = next;
		m_head = head;
        ++m_size;
		return true;
	}
	while(next->data > curr->data && curr->next != NULL)
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

template<typename TYPE>
bool DeLinkedList<TYPE>::remove(TYPE key)
{
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
		    if(head)
                head->prev = NULL;
		    m_head = head;
        }
		else
		{
			prev->next = curr->next;
		    if(curr->next)
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


template<typename TYPE>
size_t DeLinkedList<TYPE>::length()
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
ListNode<TYPE> * DeLinkedList<TYPE>::find(TYPE key)
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
ListNode<TYPE> * DeLinkedList<TYPE>::reverse()
{
	ListNode<TYPE> *head = m_head;
	if(head == NULL || head->next == NULL)
		return head;
	ListNode<TYPE> *prev, *curr, *next;
	prev = head;
	curr = head->next;
	head->prev = curr;
	while(curr)
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

template<typename TYPE>
void DeLinkedList<TYPE>::show() const
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
