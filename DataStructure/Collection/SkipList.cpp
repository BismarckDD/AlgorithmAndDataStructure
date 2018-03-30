#ifndef _skip_list_h_
#define _skip_list_h_

#include <iostream>

namespace stdcs
{

template<class _KeyType, class _ValueType, size_t MAX_LEVEL = 12>
class SkipList
{
public:
    typedef _KeyType key_type;
    typedef const _KeyType const_key_type;
    typedef _KeyType* iterator;
    typedef const _KeyType* const_key_iterator;
    typedef _KeyType& key_reference;
    typedef const _KeyType& const_key_reference;

    typedef _ValueType value_type;
    typedef const _ValueType const_value_type;
    typedef _ValueType* value_iterator;
    typedef const _ValueType* const_value_iterator;
    typedef _ValueType& value_reference;
    typedef const _ValueType& const_value_reference;

    struct SkipListNode
    {
        _KeyType key;
        _ValueType value;

        SkipListNode *forward[MAX_LEVEL];

        SkipListNode()
        {
            for(size_t i = 0; i < MAX_LEVEL; ++i)
                forward[i] = NULL;
        }

        ~SkipListNode()
        {
            // for(size_t i = 0; i < MAX_LEVEL; ++i)
            //    if(forward[i] != NULL)
            //        delete forward[i];
        }
    };

    typedef SkipListNode Node;
    typedef Node* NodePtr;

    SkipList():m_null_node(), m_level(0), m_root(NULL) { }

    ~SkipList() 
    {
        NodePtr p = m_root;
        NodePtr q = NULL;
        while ((q = p) != NULL)
        {
            p = p->forward[0];
            delete q;
            q = NULL;
        }
    }

    bool containKeys(const_key_reference p_key)
    {
        if (m_root == NULL)
            return false;
        return false;
    }

    value_reference get(const_key_reference p_key)
    {
        NodePtr p = m_root;
        NodePtr q = NULL;

        for (int i = m_level - 1; i >= 0; --i)
        {
            while ((q = p->forward[i]) && (q->key <= p_key))
            {
                if (q->key == p_key) return q->value;
                p = q;
            }
        }
        return m_null_node.value;
    }

    void put(const_key_reference p_key, const_value_reference p_value)
    {
        NodePtr update[MAX_LEVEL];
        NodePtr p = m_root;
        NodePtr q = NULL;

        if (m_root == NULL)
        {
            m_root = createNode(p_key, p_value);
            return ;
        }

        for (int i = m_level - 1; i >= 0; --i)
        {
            while((q = p->forward[i]) && (q->key < p_key)) p = q;
            update[i] = p;
        }

        if (q && q->key == p_key)
        {
            q->value = p_value;
            return ;
        }

        int k = randomLevel();

        if (k > m_level)
        {
            for (int i = m_level; i < k; ++i)
                update[i] = m_root;
            m_level = k;
        }

        q = createNode(p_key, p_value);

        for (int i = 0; i < k; ++i)
        {
            q->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = q;
        }
    }

    void show()
    {
        NodePtr p;
        NodePtr q = NULL;

        for(int i = m_level - 1; i >= 0; --i)
        {
            p = m_root;
            while((q = p->forward[i]) != NULL)
            {
                std::cout << p->value << " -> ";
                p = q;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void remove(const_key_reference p_key)
    {
        NodePtr update[MAX_LEVEL];
        NodePtr p = m_root;
        NodePtr q = NULL;

        for (int i = m_level - 1; i >= 0; --i)
        {
            while ((q = p->forward[i]) && (q->key < p_key)) p = q;
            update[i] = p;
        }

        if (q && q->key == p_key)
        {
            for (int i = 0; i < m_level; ++i)
            {
                if (update[i]->forward[i] == q)
                    update[i]->forward[i] = q->forward[i];
            }

            delete q;
            q = NULL;

            for (int i = m_level - 1; i >= 0; --i)
            {
                if (m_root->forward[i] == NULL)
                    --m_level;
            }
        }
    }
private:

    size_t randomLevel()
    {
        size_t k = 1;
        while (rand() & 0x1) ++k;
        k = (k < MAX_LEVEL) ? k : MAX_LEVEL;
        return k;
    }

    NodePtr createNode(const_key_reference p_key, const_value_reference p_value)
    {
        NodePtr nodePtr = new Node();
        nodePtr->key = p_key;
        nodePtr->value = p_value;
        return nodePtr;
    }

    size_t m_level;
    NodePtr m_root;
    Node m_null_node;
};

}

int main()
{
    stdcs::SkipList<int, int> sl;

    for(int i = 1; i <= 20; ++i)
        sl.put(i, i << 1);

    sl.show();
    std::cout << "data = " << sl.get(4) << std::endl;

    sl.remove(4);
    sl.show();

    return 0;
}


#endif
