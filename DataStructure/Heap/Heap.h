/*************************************************************************
 > File Name: Heap.h
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月20日 星期六 02时02分41秒
 ************************************************************************/

#ifndef _HEAP_H_
#define _HEAP_H_

#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

template<typename TYPE>
class Heap
{
    private:
        TYPE *m_heap;
        size_t m_size;
        size_t m_capacity;

        static const size_t s_root = 1;

        bool (* func)(const TYPE &v1, const TYPE &v2);

        static bool _cmp_(const TYPE &v1, const TYPE &v2)
        {
            return v1 < v2;
        }

        void _double_size_()
        {
            m_capacity <<= 1;
            m_heap = (TYPE *)realloc(m_heap, sizeof(TYPE)*(m_capacity+1));
        }
        
        void _swap_(TYPE &v1, TYPE &v2)
        {
            if(v1 == v2) return;
            v1 = v1^v2;
            v2 = v1^v2;
            v1 = v1^v2;
        }

        void _adjust_down_(size_t s)
        {
            size_t t = s<<1;
            TYPE tmp = m_heap[s];
            while(t <= m_size)
            {
                if(t+1 <= m_size && func(m_heap[t+1], m_heap[t])) ++t;
                if(!func(tmp, m_heap[t]))
                    m_heap[s] = m_heap[t];
                else
                    break;
                s = t;
                t = s<<1;
            }
            m_heap[s] = tmp;
         
        }
        void _adjust_up_(size_t s)
        {
            size_t t = s>>1;
            TYPE tmp = m_heap[s];
            while(t >= s_root)
            {
                if(func(tmp, m_heap[t]))
                    m_heap[s] = m_heap[t]; 
                else
                    break;
                s = t;
                t = s>>1;
            }
            m_heap[s] = tmp;
        }
    public:
        Heap(size_t capacity = 128, bool (* func)(const TYPE &v1,const TYPE &v2) = &Heap<TYPE>::_cmp_) 
        {
            m_capacity = capacity;
            m_size = 0;
            m_heap = (TYPE *)malloc(sizeof(TYPE)*(m_capacity+1));
            if(m_heap == NULL) printf("Error\n");
            this->func = func;
            //this "this" can not be omitted
        }

        //Heap(){new (this)Heap(100);} 
        ~Heap()
        {
            if(m_heap != NULL) 
            {
                free(m_heap);
                m_heap = NULL;
            }
            m_size = 0;
            m_capacity = 0;
        }
        
        TYPE& Top()
        {
            if (!isEmpty())
                return m_heap[s_root];
            else
                return m_heap[0];
        }

        void Push(TYPE &key)
        {
            ++m_size;
            if(m_size == m_capacity) 
                _double_size_();
            m_heap[m_size] = key;
            _adjust_up_(m_size);
        }
        
        TYPE Pop()
        {
            _swap_(m_heap[s_root], m_heap[m_size]);
            --m_size;
            _adjust_down_(s_root);
            return m_heap[m_size+1];
        }
        
        bool isEmpty()
        {
            return m_size == 0;
        }

        size_t size()
        {
            return m_size;
        }

        size_t capacity()
        {
            return m_capacity;
        }
};

#endif


