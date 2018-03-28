#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

const size_t MAX_LEVEL = 12; 

inline size_t randomLevel()
{
    size_t level = 1;
    while (rand() & 0x1) ++level;
    level = (level < MAX_LEVEL) ? level : MAX_LEVEL;
    return level;
}

template<typename TYPE>
class SkipListNode
{  
public:

    size_t key;

    TYPE value;

    SkipListNode *forward[MAX_LEVEL];
    
    SkipListNode(size_t p_key, TYPE p_value)
    {
        key = p_key;
        value = p_value;
        clearForward();
    }

    SkipListNode()
    {
        clearForward();
    }
    
    ~SkipListNode()
    {

    }

private:

    void clearForward()
    {
        for(size_t i = 0; i < MAX_LEVEL; ++i)
            forward[i] = NULL;
    }
};

template<typename TYPE>
class SkipList 
{
public:

    SkipList<TYPE>(size_t p_maxLevel = 10):MAX_LEVEL(p_maxLevel)
    {
        m_level = 0;
        m_header = new SkipListNode<TYPE>();
        m_header->key = 0;
    }

    virtual ~SkipList<TYPE>(){ Free(); }

    virtual bool add(size_t key, TYPE value);
    virtual bool remove(size_t key );
    virtual SkipListNode<TYPE>* find(size_t key);
    virtual void claer() { Free(); }
    virtual void show() const;

private:
    const size_t MAX_LEVEL;
    size_t m_level;  
    SkipListNode<TYPE> *m_header;  
    
    void Free();
};  

template<typename TYPE>
void SkipList<TYPE>::Free()
{
}

template<typename TYPE>
bool SkipList<TYPE>::add(size_t key, TYPE value)  
{  
    SkipListNode<TYPE> *update[MAX_LEVEL];  
    SkipListNode<TYPE> *p = m_header, *q = NULL;  
    size_t k = m_level;  

    for(int i = k-1; i >= 0; --i)
    {  
        while((q = p->forward[i]) && (q->key < key))  
        {  
            p = q;  
        }  
        update[i] = p;  
    }
    
    if(q && q->key == key)  
    {
        return false;  
    }
    
    k = randomLevel();  
    
    if(k > m_level)  
    {  
        for(int i = m_level; i < k; ++i)
        {  
            update[i] = m_header;  
        }  
        m_level = k;
    }  

    q = new SkipListNode<TYPE>(key, value);  
    
    for(int i = 0; i < k; ++i)  
    {  
        q->forward[i] = update[i]->forward[i];  
        update[i]->forward[i] = q;  
    }  
    
    return true;  
}

template<typename TYPE>
bool SkipList<TYPE>::remove(size_t key)  
{
    SkipListNode<TYPE> *update[MAX_LEVEL];
    SkipListNode<TYPE> *p = m_header, *q = NULL;

    for(int i = m_level-1; i >= 0; --i)
    {
        while((q = p->forward[i]) && (q->key < key))
        {
            p = q;
        }
        update[i] = p;
    }
    if(q && q->key == key)
    {
        for(int i = 0; i < m_level; ++i)
        {
            if(update[i]->forward[i] == q)
            {
                update[i]->forward[i] = q->forward[i];
            }
        }
        delete q;
        q = NULL;
        for(int i = m_level-1; i >= 0; --i)
        {
            if(m_header->forward[i] == NULL)
            {
                --m_level;
            }    
        }    
        return true;  
    }  
    else  
        return false;  
}  

template<typename TYPE>
SkipListNode<TYPE>* SkipList<TYPE>::find(size_t key)
{  
    SkipListNode<TYPE> *p = m_header, *q = NULL;
    size_t k = m_level;
    for(int i = k-1; i >= 0; --i)
    {
        while((q = p->forward[i]) && (q->key <= key))
        {
            if(q->key == key)
            {
                return q;
            }
            p = q;
        }
        
    }
    return NULL;
}  

template<typename TYPE>
void SkipList<TYPE>::show() const
{  
    SkipListNode<TYPE> *p, *q = NULL;
    size_t k = m_level; 
    for(int i = k-1; i >= 0; --i)
    {
        p = m_header;
        while(q = p->forward[i])
        {
            cout << p->value << " -> ";
            p = q;
        }
        cout << p->value <<  endl;
    }
    cout << endl;
}

const size_t MAXN = 100000;
int arr[MAXN];
size_t tmp;

int main()
{
    bool flag = true;
    for(size_t i = 0; i < MAXN; ++i) arr[i] = i;
    for(size_t i = 0; i < MAXN; ++i) 
    {
        tmp = rand()%MAXN;
        if(tmp == i) continue;
        arr[i] ^= arr[tmp];
        arr[tmp] ^= arr[i];
        arr[i] ^= arr[tmp];
    
    }
    SkipList<int> sl;
    SkipListNode<int> *psln;

    for(size_t i = 0; i < MAXN && flag; ++i)
    {
        flag = sl.add(arr[i]+1, arr[i]);
        psln = sl.find(arr[i]+1);
        flag = psln == NULL ? false : true;
    }
    
    sl.show();
    
    for(size_t i = 0; i < MAXN && flag; ++i)
    {
        flag = sl.remove(i+1);
        psln = sl.find(i+1);
        flag = psln == NULL ? true : false; 
    }
    if(flag)
        cout << "Succeed!" << endl;
    else
        cout << "Failed!" << endl;
    return 0;  
}

