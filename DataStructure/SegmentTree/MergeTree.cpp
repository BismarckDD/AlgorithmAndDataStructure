#ifndef _merge_Tree_h_
#define _merge_Tree_h_

#include "StaticIntervalSearchTree.h"
#include "../../Algorithm/Algorithm.h"
#include "../../Common.hpp"

namespace stdcs
{

template<class _Ty, size_t Tree_SIZE = 100010, size_t Tree_DEEP = 18>
class MergeTree : public StaticIntervalSearchTree<_Ty>
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

    MergeTree()
    {
        Seg = new pointer[Tree_DEEP];
        for (size_t i = 0; i < Tree_DEEP; ++i)
            Seg[i] = new value_type[Tree_SIZE];
        Sorted = new value_type[Tree_SIZE];
        Tree = new Node[Tree_SIZE << 2];
    }

    ~MergeTree()
    {
        for (size_t i = 0; i < Tree_DEEP; ++i)
            delete[] Seg[i], Seg[i] = NULL;
        delete[] Seg, Seg = NULL;
        delete[] Sorted, Sorted = NULL;
        delete[] Tree, Tree = NULL;
    }

    void build_helper(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_deep)
    {
        m_sorted = p_deep;
        build(p_root, p_ll, p_rr, p_deep);
    }

    void build(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_deep)
    {
        Tree[p_root].lr(p_ll, p_rr);

        if (Tree[p_root].isLeaf())
        {
            Seg[p_deep][p_ll] = Sorted[p_ll];
            return ;
        }

        size_t mid = MID(p_ll, p_rr);
        build(L(p_root), p_ll, mid, p_deep + 1);
        build(R(p_root), mid + 1, p_rr, p_deep + 1);

        size_t i = p_ll, j = mid + 1, k = p_ll;
        while (i <= mid && j <= p_rr)
        {
            if (Seg[p_deep + 1][i] < Seg[p_deep + 1][j])
                Seg[p_deep][k++] = Seg[p_deep + 1][i++];
            else
                Seg[p_deep][k++] = Seg[p_deep + 1][j++];
        }

        while (i <= mid)  Seg[p_deep][k++] = Seg[p_deep + 1][i++];
        while (j <= p_rr) Seg[p_deep][k++] = Seg[p_deep + 1][j++];
    }

    size_t query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_reference p_key, const size_t& p_deep)
    {
        if (Tree[p_root].out(p_ll, p_rr))
            return 0;

        // Under this circumstance, Seg[p_deep] is in order.
        if (Tree[p_root].in(p_ll, p_rr))
        {
            return lower_bound(Seg[p_deep] + Tree[p_root].ll, Seg[p_deep] + Tree[p_root].rr + 1, p_key) - (Seg[p_deep] + Tree[p_root].ll); 
        }

        return query(L(p_root), p_ll, p_rr, p_key, p_deep + 1) + query(R(p_root), p_ll, p_rr, p_key, p_deep + 1);
    }

    size_t query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_reference p_key)
    {
        return query(p_root, p_ll, p_rr, p_key, m_sorted) + 1;
    }

    value_type query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_rank)
    {
        size_t ll = Tree[p_root].ll, rr = Tree[p_root].rr, mid, rank;
        while (ll < rr)
        {
            mid = MID(ll, rr + 1);
            // We need find the largest key to satisfy the rank.
            // E.g. [1, 2, 3, 7],  4, 5, 6, 7 are all satisfying rank 4
            // // but only 7 is the right answer.
            rank = query(p_root, p_ll, p_rr, Seg[m_sorted][mid]);
            // std::cout << "expeced rank: " << p_rank << " value: " << Seg[m_sorted][mid] << " real rank: " << rank << std::endl;
            // Tips!!! If the Seg[0][mid] is not in the range[p_ll, p_rr]
            // The rank of the Seg[0][mid] will either too small or too large for the rank.
            // Due to the order property, it satisfy binary search.
            if (rank <= p_rank)
                ll = mid;
            else
                rr = mid - 1;
        }
        return Seg[m_sorted][ll];
    }

protected:
    NodePtr  Tree;
    size_t m_sorted;
public:
    pointer* Seg;
    pointer  Sorted;
};

}

stdcs::MergeTree<int> mt;
int store[100010];

int main()
{
    size_t n = 100000, m = 1, st, ed, rank, ans;

    for (size_t i = 1; i <= n; ++i)
        mt.Sorted[i] = i;
    for (size_t i = 1; i < n; ++i)
    {
        stdcs::swap(mt.Sorted[i], mt.Sorted[i + rand() % (n - i)]);
    }
    mt.build_helper(1, 1, n, 0);

    while (m <= 200)
    {
        st = rand() % n + 1;
        ed = rand() % n + 1;
        if (st > ed) stdcs::swap(st, ed);
        rank = rand() % (ed - st) + 1;
        ans = mt.query(1, st, ed, rank);
        for (size_t i = st; i <= ed; ++i)
            store[i - st] = mt.Sorted[i];
        stdcs::sort(store, store + ed - st + 1);
        // std::cout << "st: " << st << " ed: " << ed << " rank: " << rank << " num: " << ans << ", " << store[rank-1] << std::endl;
        if (ans != store[rank - 1])
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
