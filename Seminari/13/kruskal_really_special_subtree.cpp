class UnionFind
{
    vector<size_t> parentsContainer;
    vector<size_t> sizes;
    
    size_t getParent(size_t vertex)
    {
        if(parentsContainer[vertex] == vertex)
        {
            return vertex;
        }
        
        return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
    }
    public:
    UnionFind(size_t vertices): parentsContainer(vertices), sizes(vertices)
    {
        for(size_t i = 0; i < vertices; i++)
        {
            parentsContainer[i] = i;
            sizes[i] = 1;
        }
    }
    
    bool areInOneSet(size_t f, size_t s)
    {
        return getParent(f) == getParent(s);
    }
    
    void unionSets(size_t f, size_t s)
    {
        size_t parentOfFirst = getParent(f);
        size_t parentOfSecond = getParent(s);
        
        if(parentOfSecond == parentOfFirst)
            return;
            
        if(sizes[parentOfFirst] < sizes[parentOfSecond])
            std::swap(parentOfFirst, parentOfSecond);
            
        parentsContainer[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};

struct Edge {
    int from, to, weight;
};

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    
    vector<Edge> edges;
    for(int i = 0; i < g_from.size(); i++)
    {
        edges.push_back({g_from[i], g_to[i], g_weight[i]});
    }
    sort(edges.begin(), edges.end(), [](const Edge& f, const Edge& s)
    {
        if(f.weight == s.weight)
            return (f.from + f.to + f.weight) < (s.from + s.to + s.weight);
            
        return f.weight < s.weight;
    });
    
    UnionFind uf(g_nodes);
    vector<Edge> mstEdges;
    
    for(size_t i = 0; i < edges.size(); i++)
    {
        if(uf.areInOneSet(edges[i].to, edges[i].from))
            continue;
            
        uf.unionSets(edges[i].to, edges[i].from);
        mstEdges.push_back(edges[i]);
        
        if(mstEdges.size() == g_nodes - 1)
            break;
    }
    
    int totalWeight = 0;
    
    for(int i = 0; i < mstEdges.size(); i++)
    {
        totalWeight += mstEdges[i].weight;
    }
    
    return totalWeight;
}
