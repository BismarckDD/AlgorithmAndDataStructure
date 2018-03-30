#ifndef _parti_tree_h_
#define _parti_tree_h_

#include "StaticIntervalSearchTree.h"
#include "../../Algorithm/Algorithm.h"
#include "../../Common.hpp"

namespace stdcs
{

template<class _Ty, size_t TREE_SIZE = 100010, size_t TREE_DEEP = 19>
class PartiTree : public StaticIntervalSearchTree<_Ty>
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

    PartiTree()
    {
        Seg = new pointer[TREE_DEEP];
        for (size_t i = 0; i < TREE_DEEP; ++i)
            Seg[i] = new value_type[TREE_SIZE];
        Sorted = new value_type[TREE_SIZE];
        Tree = new Node[TREE_SIZE << 2];
        sum = new size_t*[TREE_SIZE];
        for (size_t i = 0; i < TREE_DEEP; ++i)
            sum[i] = new size_t[TREE_SIZE];
    }

    ~PartiTree()
    {
        for (size_t i = 0; i < TREE_DEEP; ++i)
            delete[] Seg[i], Seg[i] = NULL;
        delete[] Seg, Seg = NULL;
        delete[] Sorted, Sorted = NULL;
        delete[] Tree, Tree = NULL; 
        for (size_t i = 0; i < TREE_DEEP; ++i)
            delete[] sum[i], sum[i] = NULL;
        delete[] sum, sum = NULL;
    }

    void build_helper(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_sorted)
    {
        stdcs::sort(Sorted + p_ll, Sorted + p_rr + 1);
        m_sorted = p_sorted;
        build(p_root, p_ll, p_rr, m_sorted);
    }

    void build(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_deep)
    {
        Tree[p_root].lr(p_ll, p_rr);

        if (Tree[p_root].isLeaf())
            return ;

        size_t mid = MID(p_ll, p_rr), lsame = mid - p_ll + 1;

        for (size_t i = p_ll; i <= p_rr; ++i)
            if (Seg[p_deep][i] < Sorted[mid])
                --lsame; // prevent too many same elements occupy the left position.

        size_t lpos = p_ll, rpos = mid + 1;
        for (size_t i = p_ll; i <= p_rr; ++i)
        {
            if (i == p_ll)
                sum[p_deep][i] = 0;
            else
                sum[p_deep][i] = sum[p_deep][i - 1];

            if (Seg[p_deep][i] < Sorted[mid])
            {
                ++sum[p_deep][i];
                Seg[p_deep + 1][lpos++] = Seg[p_deep][i];
            }

            if (Seg[p_deep][i] > Sorted[mid])
            {
                Seg[p_deep + 1][rpos++] = Seg[p_deep][i];
            }

            if (Seg[p_deep][i] == Sorted[mid])
            {
                if (lsame > 0)
                {
                    --lsame;
                    sum[p_deep][i]++; // in the left part, how many elements less than or equal with ith elements.
                    Seg[p_deep + 1][lpos++] = Seg[p_deep][i];
                }
                else
                {
                    Seg[p_deep + 1][rpos++] = Seg[p_deep][i];
                }
            }
        }
        build(L(p_root), p_ll, mid, p_deep + 1);
        build(R(p_root), mid + 1, p_rr, p_deep + 1);
    }

    value_type query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_rank, const size_t& p_deep)
    {
        if (Tree[p_root].isLeaf())
            return Seg[p_deep][p_ll];
        size_t totalInLeftPart, leftBefore;
        if (p_ll == Tree[p_root].ll)
            leftBefore = 0;
        else
            leftBefore = sum[p_deep][p_ll - 1];
        totalInLeftPart = sum[p_deep][p_rr] - leftBefore;
        if (p_rank <= totalInLeftPart)
            return query(L(p_root), Tree[p_root].ll + leftBefore,
                    Tree[p_root].ll + sum[p_deep][p_rr]  - 1, p_rank, p_deep + 1);
        else
        {
            size_t mid = Tree[p_root].mid();
            size_t rightBefore = p_ll - Tree[p_root].ll - leftBefore;
            size_t totalInRightPart = p_rr - p_ll + 1 - totalInLeftPart;
            return query(R(p_root), mid + rightBefore + 1, mid + rightBefore + totalInRightPart, p_rank - totalInLeftPart, p_deep + 1);
        }
    }

    value_type query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_rank)
    {
        return query(p_root, p_ll, p_rr, p_rank, 0);
    }

    size_t query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_reference p_key, const size_t& p_deep)
    {
        return 0;
    }

    size_t query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_reference p_key)
    {
        return query(p_root, p_ll, p_rr, p_key, 0);
    }

public:
    NodePtr Tree;
    size_t **sum;
    size_t m_sorted;
public:
    pointer *Seg;
    pointer Sorted;
};

}

stdcs::PartiTree<int> pt;
size_t store[100001];

int main()
{
    size_t n = 100000, m = 1, st, ed, rank, ans;

    for (size_t i = 1; i <= n; ++i)
        pt.Sorted[i] = i;
    for (size_t i = 1; i < n; ++i)
        stdcs::swap(pt.Sorted[i], pt.Sorted[i + rand() % (n - i)]);
    for (size_t i = 1; i <= n; ++i)
        pt.Seg[0][i] = pt.Sorted[i];
    
    pt.build_helper(1, 1, n, 0);

    while (m <= 200)
    {
        st = rand() % n + 1;
        ed = rand() % n + 1;
        if (st > ed) stdcs::swap(st, ed);
        rank = rand() % (ed - st + 1) + 1;
        ans = pt.query(1, st, ed, rank);
        for (size_t i = st; i <= ed; ++i)
            store[i - st] = pt.Seg[0][i];
        stdcs::sort(store, store + ed - st + 1);
        // std::cout << "st: " << st << " ed: " << ed << " rank: " << rank << " num: " << ans << " expected: " << store[rank-1] << std::endl;

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
