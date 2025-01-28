#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    size_t from, to, weight;
    
    bool operator<(const Edge& other)const
    {
        return weight < other.weight;
    }
};

class UnionFind {
private:
    vector<size_t> parents;
    vector<size_t> sizes;
    vector<size_t> rank;
public:
    size_t getParent(size_t vertex) {
        if (parents[vertex] == vertex) {
            return vertex;
        }

        return parents[vertex] = getParent(parents[vertex]);
    }


    UnionFind(size_t vertices) : parents(vertices), sizes(vertices), rank(vertices,0) {
        for (size_t i = 0; i < vertices; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    bool areInOneSet(size_t first, size_t second) {
        return getParent(first) == getParent(second);
    }
    bool unite(size_t x, size_t y) {
        size_t rootX = getParent(x);
        size_t rootY = getParent(y);
        if (rootX == rootY) 
            return false;
        
        if (rank[rootX] > rank[rootY]) {
            parents[rootY] = rootX;
            sizes[rootX] += sizes[rootY];
        } 
        else if (rank[rootX] < rank[rootY]) {
            parents[rootX] = rootY;
            sizes[rootY] += sizes[rootX];
        } 
        else {
            parents[rootY] = rootX;
            sizes[rootX] += sizes[rootY];
            rank[rootX]++;
        }
        return true;
    }
    
    size_t componentSize(size_t x) {
        return sizes[getParent(x)];
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
        
        vector<Edge> mstEdges;
         for (const auto& edge : edges) {
            if (uf.unite(edge.from, edge.to)) {
                mstEdges.push_back(edge);
            }
        }

        // Calculate the MST weight for each connected component
        unordered_map<size_t, long long> componentWeights;
        for (const auto& edge : mstEdges) {
            size_t root = uf.getParent(edge.from);
            componentWeights[root] += edge.weight;
        }

        // Add isolated vertices as components
        for (size_t j = 0; j < V; j++) {
            if (uf.getParent(j) == j && uf.componentSize(j) == 1) {
                componentWeights[j] = 0; // No edges in the component
            }
        }
        
        unordered_set<size_t> visited;
        for (size_t j = 0; j < V; j++) {
            size_t root = uf.getParent(j);
            if (visited.count(root))
                continue;
            visited.insert(root);

            size_t componentSize = uf.componentSize(root);
            if (componentSize % K == 0) {
                resSum += componentWeights[root];
            }
        }

        cout << resSum << '\n';
    }
    

    return 0;
}
