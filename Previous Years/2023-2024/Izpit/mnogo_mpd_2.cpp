#include <bits/stdc++.h>
using namespace std;

//опростено решение на задачата
//union find ни следи както броя върхове в компонента - чрез root (sizes)
//така и колко тежи дадено мпд на даден компонент (weights)
struct Edge
{
    size_t from, to;
        
    long long weight;
    
    bool operator<(const Edge& other)const
    {
        return weight < other.weight;
    }
};

class UnionFind {

    vector<size_t> parents;
    vector<size_t> sizes;
    vector<long long> weights;
    
public:
    size_t getParent(size_t vertex) {
        if (parents[vertex] == vertex) {
            return vertex;
        }

        return parents[vertex] = getParent(parents[vertex]);
    }


    UnionFind(size_t vertices) : parents(vertices), sizes(vertices), weights(vertices, 0) {
        for (size_t i = 0; i < vertices; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    bool areInOneSet(size_t first, size_t second) {
        return getParent(first) == getParent(second);
    }
    bool unite(Edge& edge) {
        size_t rootX = getParent(edge.to);
        size_t rootY = getParent(edge.from);
        if (rootX == rootY) 
            return false;
        
        if(sizes[rootX] < sizes[rootY])
        {
            swap(rootX, rootY);
        }
        
        parents[rootY] = rootX;
        sizes[rootX] += sizes[rootY];
        weights[rootX] += weights[rootY] + edge.weight;
        
        return true;
    }
    
    size_t componentSize(size_t x) {
        return sizes[getParent(x)];
    }
    
    long long getWeight(size_t x)
    {
        return weights[x];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;
    

    for(int i = 0; i < T; i++)  
    {
        long long resSum = 0;
        size_t V,E, K;
        cin >> V >> E >> K;
 
        vector<Edge> edges(E);
        for (int i = 0; i < E; i++) 
        {
            cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        }

        sort(edges.begin(), edges.end());
        
        UnionFind uf(V);
        
         for (auto& edge : edges) {
            uf.unite(edge)
        }
        
        unordered_set<size_t> visited;
        for (size_t j = 0; j < V; j++) 
        {
            size_t root = uf.getParent(j);
            if (visited.count(root))
                continue;
            visited.insert(root);

            size_t componentSize = uf.componentSize(root);
            if (componentSize % K == 0) {
                resSum += uf.getWeight(root);
            }
        }

        cout << resSum << '\n';
    }
    

    return 0;
}
