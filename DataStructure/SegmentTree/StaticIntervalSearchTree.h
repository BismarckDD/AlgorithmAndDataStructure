#ifndef _static_interval_search_tree_h_
#define _static_interval_search_tree_h_

#include <iostream>

namespace stdcs
{

inline size_t L(size_t x) { return (x << 1); }
inline size_t R(size_t x) { return (x << 1) | 1; }
inline size_t MID(size_t x, size_t y) { return x + ((y - x) >>  1); }

template<class _Ty>
class StaticIntervalSearchTree
{
public:
    typedef _Ty value_type;
    typedef const _Ty const_value_type;
    typedef _Ty* pointer;
    typedef const _Ty* const_pointer;
    typedef _Ty& reference;
    typedef const _Ty& const_reference;

    class TreeNode
    {
    public:
        TreeNode(const size_t& p_ll, const size_t& p_rr, const_reference p_ww): ll(p_ll), rr(p_rr), ww(p_ww) { }
        TreeNode() { }
        ~TreeNode() { }

        bool isLeaf() { return ll == rr; }
        size_t mid() { return MID(ll, rr); }
        bool in(size_t p_ll, size_t p_rr) { return (p_ll <= ll && rr <= p_rr); }
        bool out(size_t p_ll, size_t p_rr) { return (ll > p_rr || rr < p_ll); }
        void lr(size_t p_ll, size_t p_rr) { ll = p_ll, rr = p_rr; }

        size_t ll, rr;
        value_type ww;
    };

    typedef TreeNode Node;
    typedef TreeNode* NodePtr;

    virtual void build(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_deep) = 0;
    // Return the key whose rank = p_rank.
    virtual value_type query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const size_t& p_rank) = 0;
    // Return the rank of the p_key.
    virtual size_t query(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_reference p_key) = 0;
    // Temporarily not support dynamic operation.
    // virtual void insert(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_value_reference& p_key) = 0;
    // virtual void remove(const size_t& p_root, const size_t& p_ll, const size_t& p_rr, const_value_reference& p_key) = 0;
};

}

#endif
