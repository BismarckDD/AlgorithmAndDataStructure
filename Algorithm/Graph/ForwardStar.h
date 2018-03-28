#ifndef _forward_star_h_
#define _forward_star_h_


template<size_t Nodes = 100001, size_t Edges = 1000000, class weight_type = int>
class ForwardStar
{

private:

    typedef int NODE;
    template<class weight_type = int>
    struct EDGE
    {
        size_t u, v;
        weight_type w;
    };

    NODE *m_head;
    EDGE *m_Edge;
    size_t m_cnt;

public:

    ForwardStar()
    {
        m_head = new int[Nodes];
        m_Edge = new EDGE<weight_type>[Edges];
        for(size_t i = 0; i < Nodes; ++i) 
            m_head[i] = -1;
        m_cnt = 0;
    }

    ~ForwardStar()
    {
        if (m_head != NULL)
            delete[] m_head, m_head = NULL;

        if (m_Edge != NULL)
            delete [] m_Edge, m_Edge = NULL;
    }

    void Reset()
    {
        for(size_t i = 0; i < Nodes; ++i) 
            m_head[i] = -1;
        m_cnt = 0;
    }

    void AddEdge(const size_t& u, cosnt size_t& v, const weight_type& w)
    {
        m_Edge[u].u = u;
        m_Edge[u].v = v;
        m_Edge[u].w = w;
        m_head[u] = m_Edge[m_cnt++];
    }

    void AddEdge(const size_t& u, cosnt size_t& v)
    {
        m_Edge[u].u = u;
        m_Edge[u].v = v;
        m_head[u] = m_Edge[m_cnt++];
    }

    void Dijstra(const size_t& u)
    {
        
    }

    void Floyd()
    {

    }

    void TopSort()
    {

    }

    void DFS(const size_t& u)
    {
        
    }

    void BFS(const size_t& u)
    {
        
    }

private:
    bool vis[Nodes];

};

#endif
