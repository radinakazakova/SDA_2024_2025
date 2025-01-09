#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class UnionFind
{
    vector<size_t> parentsContainer;
    vector<size_t> sizes;
    
    size_t getParent(size_t vertex)
    {
        if(parentsContainer[vertex] == vertex)
            return vertex;
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
    
    bool areInSameSet(size_t first, size_t second)
    {
        return getParent(first) == getParent(second);
    }
    
    void unionNodes(size_t first, size_t second)
    {
        size_t parentOfFirst = getParent(first);
        size_t parentOfSecond = getParent(second);
        
        if(parentOfFirst == parentOfSecond)
            return;
        
        if(sizes[parentOfFirst] < sizes[parentOfSecond])
        {
            std::swap(parentOfFirst, parentOfSecond);
        }
        
        parentsContainer[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};


struct Edge
{
    size_t from, to, effort;
    long long pay;
    int index;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    size_t nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;
    vector<Edge> edges;
    for(size_t i = 0; i< edgesCount; i++)
    {
        size_t from, to, effort;
        long long pay;
        cin >> from >> to >> effort >> pay;
        
        edges.push_back({from - 1, to - 1, effort, pay, i + 1});
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& f, const Edge& s)
         {
            if(f.effort == s.effort)
                return f.pay > s.pay;
             
             return f.effort < s.effort;
         });
    
    vector<Edge> mstEdges;
    UnionFind uf(nodesCount);
    
    for(auto& edge: edges)
    {
        if(uf.areInSameSet(edge.from, edge.to))
            continue;
        
        uf.unionNodes(edge.to, edge.from);
        mstEdges.push_back(edge);
        
        if(mstEdges.size() == nodesCount - 1)
            break;
    }
    
    for(size_t i = 0; i < mstEdges.size(); i++)   
    {
        cout << mstEdges[i].index << '\n';
    }
    
    return 0;
}
