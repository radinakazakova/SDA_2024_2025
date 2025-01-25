#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct UF
{
    vector<size_t> parent;
    vector<size_t> size;
    
    UF(size_t v): parent(v), size(v)
    {
        for(size_t i = 0; i < v; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    size_t getParent(size_t x)
    {
        if(x==parent[x])
            return x;
        return parent[x] = getParent(parent[x]);
    }
    
    bool inSameSet(size_t x, size_t y)
    {
        return getParent(x) == getParent(y);
    }
    
    bool connect(size_t x, size_t y)
    {
        size_t rootX = getParent(x);
        size_t rootY = getParent(y);
        
        if(rootX == rootY)
            return false;
        
        if(size[rootX] < size[rootY])
            swap(rootX, rootY);
        
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        return true;
    }
};

struct Edge
{
    size_t from, to, weight;
};

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N,M;
    cin >> N >> M;
    vector<Edge> edges;
    size_t sumAllEdges = 0;
    for(int i = 0; i < M; i++)
    {
        size_t from, to, weight;
        cin >> from >> to >> weight;
        sumAllEdges += weight;
        edges.push_back({from,to,weight});
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& f, const Edge& s)
         {
             return f.weight > s.weight;
         });
    
    UF uf(N);
    
    int count = 0;
    size_t sumMax = 0;
    for(auto edge: edges)
    {
        if(uf.connect(edge.to, edge.from))
        {
            sumMax += edge.weight;
            count++;
        }
        if(count == N - 1)
            break;
    }
    
    cout << sumAllEdges - sumMax;
    return 0;
}
