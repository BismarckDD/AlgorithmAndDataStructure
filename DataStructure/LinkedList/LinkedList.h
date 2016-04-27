/*************************************************************************
 > File Name: LinkedList.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月02日 星期四 14时00分54秒
 ************************************************************************/

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_


template<typename TYPE>
class LinkedList
{
    template<typename TYPE>
    struct LinkedNode
    {
        TYPE data;
        LinkedNode *next;
    };
    
    public:
        LinkedList()
        {
            m_size = 0;
            m_head = NULL;
        }
        
        LinkedList(TYPE& arr[])
        {
            m_size = 0;
            m_head = Create(arr);
        }

        ~LinkedList()
        { 
            Free(); 
        }
        
        int size(){ return m_size; }
        int length();
        LinkedNode<TYPE>* Delete(TYPE& key);
        LinkedNode<TYPE>* Insert(TYPE& key);
        LinkedNode<TYPE>* Reverse();
        void print() const;
    private:
        void Free();
        LinkedNode<TYPE>* Create();
        LinkedNode<TYPE>* m_head;
        int m_size;
};

template<typename TYPE>
void LinkedList<TYPE>::Free()
{
    LinkedNode<TYPE> *curr = m_head;
    LinkedNode<TYPE> *prev = NULL;
    while(curr!=NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    m_head = NULL;
}

template<typename TYPE>
LinkedNode<TYPE> * LinkedList<TYPE>::Create()
{
    LinkedNode<TYPE> *head, *prev, *curr;
    TYPE data;
    if(cin >> data)
    {
        head=(LinkedNode<TYPE> *)malloc(sizeof(LinkedNode<TYPE>));
        head->data=data;
        prev=head;
        ++this->m_size;
    }
    else
        return NULL;
    while(cin>>data)
    {
        curr=(LinkedNode<TYPE> *)malloc(sizeof(LinkedNode<TYPE>));
        curr->data=data;
        prev->next=curr;
        prev=curr;
        ++this->m_size;
    }
    prev->next = NULL;
    return head;
}

template<typename TYPE>
LinkedNode<TYPE> * LinkedList<TYPE>::Insert(TYPE& key)
{
    LinkedNode<TYPE> *head = m_head, *prev, *curr=head, *next;
    next = (LinkedNode<TYPE> *)malloc(sizeof(LinkedNode<TYPE>));
    next->data = key;
    if(head = NULL)
    {
        head = next;
        head->next = NULL;
        m_head = head;
        return head;
    }
    while( (next->data > curr->data) && (curr->next!=NULL) )
    {
        prev = curr;
        curr = curr->next;
    }

    if(next->data<=curr->data)
    {
        if(curr==head)
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
    m_head=head;
    return head;
}
template<typename TYPE>
LinkedNode<TYPE> * LinkedList<TYPE>::Delete(TYPE num)
{
    LinkedNode<TYPE> *head=this->m_head, *prev, *curr=head;
    while(num!=prev->data&&curr->next!=NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if(num==curr->data)
    {
        if(curr==head)
            head = head->next;
        else
            prev->next = curr->next;
        free(curr);
    }
    else
        cout<<"没有找到"<<endl;
    this->m_head = head;
    return head;
}


template<typename TYPE>
int LinkedList<TYPE>::length()
{
    int len = 0;
    LinkedNode<TYPE> *p = this->m_head;
    while(p!=NULL)
    {
        p = p->next;
        ++len;
    }
    return len;
}

template<typename TYPE>
LinkedNode<TYPE> *LinkedList<TYPE>::Reverse()
{
    LinkedNode<TYPE> *head = this->m_head;
    if(head==NULL||head->next==NULL)
        return head;
    LinkedNode<TYPE> *prev, *curr, *next;
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
    return head;
}

template<typename TYPE>
void LinkedList<TYPE>::print() const
{
    LinkedNode<TYPE> *p = this->m_head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    
}


#endif
