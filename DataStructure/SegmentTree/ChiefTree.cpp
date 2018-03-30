#ifndef _chief_tree_h_
#define _chief_tree_h_

#include "StaticIntervalSearchTree.h"
#include "../../Algorithm/Algorithm.h"
#include "../../Common.hpp"

/*
 * orig : original array, needs discretialize
 * mapt : map from size to index. map[1] = 2 means in the orig, the 2th element is the smallest.
 * disc : discrete array, discrete the orig to range [1..n] and remain the original order.
 * */
size_t orig[100010], mapt[100010], disc[100010];

template<class _Ty>
bool cmp(const _Ty& i, const _Ty& j)
{
    return orig[i] < orig[j]; 
}
struct Cmp
{
    template<class _Ty>
    bool operator() (const _Ty& i, const _Ty& j) const
    {
         return orig[i] < orig[j];
    // return orig[i] < orig[j];
    }
};

namespace stdcs
{

template<class _Ty, size_t TREE_SIZE = 100010>
class ChiefTree : public StaticIntervalSearchTree<_Ty>
{
public:
    typedef typename StaticIntervalSearchTree<_Ty>::value_type value_type;
    typedef typename StaticIntervalSearchTree<_Ty>::const_value_type const_value_type;
    typedef typename StaticIntervalSearchTree<_Ty>::pointer pointer;
    typedef typename StaticIntervalSearchTree<_Ty>::const_pointer const_pointer;
    typedef typename StaticIntervalSearchTree<_Ty>::reference reference;
    typedef typename StaticIntervalSearchTree<_Ty>::const_reference const_reference;
    typedef typename StaticIntervalSearchTree<_Ty>::Node Node;
    typedef typename StaticIntervalSearchTree<_Ty>::NodePtr NodePtr;

private:
    NodePtr node;
    size_t *Tree, sz;

public:
    ChiefTree()
    {
        node = new Node[TREE_SIZE * 20];
        node[0].ww = 0;
        node[0].ll = 0;
        node[0].rr = 0;
        Tree = new size_t[TREE_SIZE]; // root represent the root of Tree[i] point to which Nodes.
        Tree[0] = 0;
        sz = 0;
    }

    ~ChiefTree()
    {
        delete[] Tree, Tree = NULL;
        delete[] node, node = NULL;
    }

    void build(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_key)
    {
        Tree[p_root] = Tree[p_root - 1];
        build_helper(Tree[p_root], p_ll, p_rr, p_key);
    }

    void build_helper(size_t& p_curr, const size_t& p_ll, const size_t& p_rr, const size_t& p_key)
    {
        // std::cout << sz << " " << p_ll << " " << p_rr << std::endl;
        node[++sz] = node[p_curr];
        p_curr = sz; // sz fetch a TreeNode from node array.
        ++node[p_curr].ww;
        if (p_ll == p_rr) return;
        size_t mid = MID(p_ll, p_rr);

        if (p_key <= mid)
            build_helper(node[p_curr].ll, p_ll, mid, p_key);
        else
            build_helper(node[p_curr].rr, mid + 1, p_rr, p_key);
    }

    size_t query(const size_t& i, const size_t& j, const size_t& p_ll, const size_t& p_rr, const_reference p_key)
    {
        return query_helper(Tree[i], Tree[j], p_ll, p_rr, p_key);
    }

    size_t query_helper(const size_t& i, const size_t& j, const size_t& p_ll, const size_t p_rr, const_reference p_key)
    {
        if (p_ll == p_rr) return p_ll;
        //cout << w(l(j)) << ", " << w(l(i)) << endl;
        size_t ww = node[node[j].ll].ww - node[node[i].ll].ww;
        size_t mid = MID(p_ll, p_rr);
        if (p_key <= ww) 
            return query_helper(node[i].ll, node[j].ll, p_ll, mid, p_key);
        else
            return query_helper(node[i].rr, node[j].rr, mid + 1, p_rr, p_key - ww);
    }

private:
    size_t query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_reference p_key) { return 0; }
    value_type query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_rank) { value_type re; return re; }
};

}

stdcs::ChiefTree<int> ct;
int store[100010];

int main()
{
    size_t n = 100000, m = 0;

    // discretion method.
    for (size_t i = 1; i <= n; ++i) orig[i] = rand(), mapt[i] = i;
    //stdcs::sort(mapt + 1, mapt + 1 + n, cmp());
    stdcs::sort(mapt + 1, mapt + 1 + n, Cmp());
    for (size_t i = 1; i <= n; ++i) disc[mapt[i]] = i;
    
    /*
           for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
           for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
           for (int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
    */

    // Build the ith sub tree.
    for (size_t i = 1; i <= n; ++i) ct.build(i, 1, n, disc[i]);

    std::cout << "Hello World" << std::endl;
    while (m <= 200)
    {
        size_t st = rand() % n + 1;
        size_t ed = rand() % n + 1;
        if (st > ed) stdcs::swap(st, ed);
        size_t rank = rand() % (ed - st) + 1;
        size_t ans = ct.query(st - 1, ed, 1, n, rank);
        for (size_t i = st; i <= ed; ++i)
            store[i - st] = orig[i];
        stdcs::sort(store, store + ed - st + 1);
        // std::cout << "st: " << st << " ed: " << ed << " rank: " << rank << " num: " << ans << ", " << store[rank-1] << std::endl;
        if (orig[mapt[ans]] != store[rank - 1])
        {
            std::cout << "Error!" << std::endl;
            std::cout << m << " rounds test failed!" << std::endl;
        }
        else
            std::cout << m << " rounds test succeed!" << std::endl;
        m++;
    }
    return 0;
}

#endif
