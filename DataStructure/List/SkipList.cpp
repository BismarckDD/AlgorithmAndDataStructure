#ifndef _skip_list_h_
#define _skip_list_h_

#include <iostream>


template<class _KeyType, class _ValueType, size_t MAX_LEVEL = 12>
class SkipListNode
{
public:
    _KeyType key;
    _ValueType value;
    SkipListNode* forward[MAX_LEVEL];

    SkipListNode(const _KeyType& p_key, const _ValueType& p_value) 
        : key(p_key), value(p_value) { clearForward(); }
    SkipListNode() { clearForward(); }
    ~SkipListNode() { }

private:
    void clearForward()
    {
        for(size_t i = 0; i < MAX_LEVEL; ++i)
            forward[i] = NULL;
    }
};

template<class _KeyType, class _ValueType, size_t MAX_LEVEL = 12, class _Node = SkipListNode<_KeyType, _ValueType, MAX_LEVEL> >
class SkipList
{
public:

    SkipList()
    {
        m_level = 0;
        m_header = new _Node();
    }

    virtual ~SkipList(){ clear(); }

    virtual bool add(const _KeyType& p_key, const _ValueType& p_value);
    virtual bool remove(const _KeyType& p_key);
    virtual _Node* find(const _KeyType& p_key);
    virtual void clear() { }
    virtual void show() const;

private:

    inline size_t randomLevel()
    {
        size_t level = 1;
        while (rand() & 0x1) ++level;
        level = (level < MAX_LEVEL) ? level : MAX_LEVEL;
        return level;
    }

    size_t m_level;
    _Node *m_header;
};

template<class _KeyType, class _ValueType, size_t MAX_LEVEL, class _Node>
bool SkipList<_KeyType, _ValueType, MAX_LEVEL, _Node>::add(const _KeyType& p_key, const _ValueType& p_value)
{
    _Node *update[MAX_LEVEL];
    _Node *p = m_header, *q = NULL;
    size_t k = m_level;

    for (int i = k - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (q->key < p_key))
        {
            p = q;
        }
        update[i] = p;
    }

    if (q && q->key == p_key)
    {
        return false;
    }

    k = randomLevel();

    if (k > m_level)
    {
        for (size_t i = m_level; i < k; ++i)
        {
            update[i] = m_header;  
        }
        m_level = k;
    }

    q = new _Node(p_key, p_value);

    for (size_t i = 0; i < k; ++i)
    {
        q->forward[i] = update[i]->forward[i];  
        update[i]->forward[i] = q;  
    }

    return true;
}

template<class _KeyType, class _ValueType, size_t MAX_LEVEL, class _Node>
bool SkipList<_KeyType, _ValueType, MAX_LEVEL, _Node>::remove(const _KeyType& p_key)
{
    _Node *update[MAX_LEVEL];
    _Node *p = m_header, *q = NULL;

    for (int i = m_level-1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (q->key < p_key))
        {
            p = q;
        }
        update[i] = p;
    }
    if (q && q->key == p_key)
    {
        for (int i = 0; i < m_level; ++i)
        {
            if (update[i]->forward[i] == q)
            {
                update[i]->forward[i] = q->forward[i];
            }
        }
        delete q;
        q = NULL;
        for (int i = m_level-1; i >= 0; --i)
        {
            if (m_header->forward[i] == NULL)
            {
                --m_level;
            }    
        }
        return true;  
    }
    else
        return false;  
}

template<class _KeyType, class _ValueType, size_t MAX_LEVEL, class _Node>
_Node* SkipList<_KeyType, _ValueType, MAX_LEVEL, _Node>::find(const _KeyType& p_key)
{
    _Node *p = m_header, *q = NULL;
    size_t k = m_level;
    for (int i = k-1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (q->key <= p_key))
        {
            if (q->key == p_key)
            {
                return q;
            }
            p = q;
        }
    }
    return NULL;
}

template<class _KeyType, class _ValueType, size_t MAX_LEVEL, class _Node>
void SkipList<_KeyType, _ValueType, MAX_LEVEL, _Node>::show() const
{  
    _Node *p, *q = NULL;
    size_t k = m_level; 
    for (int i = k-1; i >= 0; --i)
    {
        p = m_header;
        while (q = p->forward[i])
        {
            std::cout << p->value << " -> ";
            p = q;
        }
        std::cout << p->value <<  std::endl;
    }
    std::cout << std::endl;
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
    SkipList<size_t, int> sl;
    SkipListNode<size_t, int> *psln;

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
        std::cout << "Succeed!" << std::endl;
    else
        std::cout << "Failed!" << std::endl;
    return 0;  
}

#endif
