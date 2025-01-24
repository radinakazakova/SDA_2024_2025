#include <bits/stdc++.h>
using namespace std;


struct UF
{
    vector<size_t> parents;
    vector<size_t> sizes;
    
    UF(size_t v): parents(v), sizes(v)
    {
        for(size_t i = 0; i < v; i++)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    
    size_t getParent(size_t x)
    {
        if(parents[x] == x)
            return x;
        return parents[x] = getParent(parents[x]);
    }
    
    bool areInSameSet(size_t x, size_t y)
    {
        return getParent(x) == getParent(y);
    }
    
    bool unite(size_t x, size_t y)
    {
        size_t rootX = getParent(x);
        size_t rootY = getParent(y);
        
        if(rootX == rootY)
            return false;
        
        if(sizes[rootX] < sizes[rootY])
            swap(rootX, rootY);
        
        parents[rootY] = rootX;
        sizes[rootX] += sizes[rootY];
        return true;
    }
    
    size_t getComponentSize(size_t x)
    {
        return sizes[getParent(x)];
    }
};

struct Edge
{
    size_t from, to;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    size_t N, E , K;
    size_t res = 0;
    cin >> N >> E>>K;
    vector<Edge> edges;
    for(int i = 0; i < E; i++)
    {
        size_t from, to;
        cin >> from >> to;
        edges.push_back({from, to});
    }
    
    UF uf(N);
    size_t size = 0;
    for(auto edge: edges)
    {
        if(uf.unite(edge.from, edge.to))
            size++;
        if(size == N - 1)
            break;
    }
    
    unordered_set<size_t> visited;
    for(int i = 0; i < N; i++)
    {
        size_t root = uf.getParent(i);
        if(!visited.count(root))
        {
            visited.insert(root);
            
            if(uf.getComponentSize(root) % K == 0)
            {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
