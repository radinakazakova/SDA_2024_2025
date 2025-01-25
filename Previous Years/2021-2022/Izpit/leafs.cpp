#include <bits/stdc++.h>
using namespace std;

size_t sumOfChildren[200001];

void dfs(int curr, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph)
{
    visited.insert(curr);
    
    for(const auto n: graph[curr])
    {
        if(!visited.count(n))
            dfs(n, visited, graph);        
        
        sumOfChildren[curr] += n + sumOfChildren[n];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int edges, queries;
    cin >> edges >> queries;
    
    unordered_map<int, vector<int>> graph;
    for(int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    
    unordered_set<int> visited;

    for(int i = 0; i < queries; i++)
    {
        int vertex;
        cin >> vertex;
        
        if(!visited.count(vertex))
        {
            dfs(vertex, visited, graph);
        }
        
        cout << sumOfChildren[vertex] << '\n';
    }
    return 0;
}
