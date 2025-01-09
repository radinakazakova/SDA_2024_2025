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
    UnionFind(size_t vertices): parentsContainer(vertices + 1), sizes(vertices + 1)
    {
        for(size_t i = 1; i <= vertices; i++)
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
    int from, to;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int nodesCount, edgesCount;
    
    cin >> nodesCount >> edgesCount;
    UnionFind uf(nodesCount);

    for(int i = 0; i < edgesCount; i++)
    {
        int from, to;
        cin >> from >> to;
        if(!uf.areInSameSet(from, to))
        {
            uf.unionNodes(from, to);
        }
    }
    
    int q;
    cin >> q;
    vector<int> res;
    
    for(int i = 0; i < q; i++)
    {
        int type, city1, city2;
        cin >> type >> city1 >> city2;
        
        if(type == 1)
        {
            if(uf.areInSameSet(city1, city2))
                res.push_back(1);
        
            else
                res.push_back(0);
        }
        else if(type == 2)
        {
            if(!uf.areInSameSet(city1, city2))
            {
                uf.unionNodes(city1, city2);
            }
        }
    }
    
    for(size_t i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}
