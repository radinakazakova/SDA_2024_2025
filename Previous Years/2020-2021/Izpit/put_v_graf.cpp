#include <bits/stdc++.h>
using namespace std;

struct UF
{
    vector<size_t> parents;
    vector<size_t> sizes;
    
    size_t getParent(size_t x)
    {
        if(parents[x] == x)
            return x;
        return parents[x] = getParent(parents[x]);
    }
    
    UF(size_t v): parents(v), sizes(v)
    {
        for(size_t i = 1; i <= v; i++)
        {
            parents[i]= i;
            sizes[i] = 1;
        }
    }
    
    bool unionize(size_t x, size_t y)
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
    
    bool areInSameSet(size_t x, size_t y)
    {
        return getParent(x) == getParent(y);
    }
};

struct Edge
{
    size_t from, to;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<Edge> edges;
    for(int i = 0; i < M; i++)
    {
        size_t from, to;
        cin >> from >> to;
        
        edges.push_back({from,to});
    }
    
    UF uf(N);
    
    int count = 0;
    for(auto edge: edges)
    {
        if(uf.unionize(edge.from, edge.to))
            count++;
        if(count == N - 1)
            break;
            
    }
    
    int K;
    cin >> K;
    
    for(int i = 0; i < K; i++)
    {
        size_t from, to;
        cin >> from>> to;
        
        if(uf.areInSameSet(from, to))
        {
            cout << 1 << " ";
        }else
            cout << 0 << " ";
    }
    
    return 0;
}
