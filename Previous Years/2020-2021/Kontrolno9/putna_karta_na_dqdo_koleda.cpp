#include <bits/stdc++.h>
using namespace std;

unordered_set<int> visited;
size_t componentsCount = 0;

void dfs(int curr, unordered_map<int, vector<int>>& graph, int& vertexCount)
{
    visited.insert(curr);
    
    for(auto& neighbor: graph[curr])
    {
        if(!visited.count(neighbor))
        {
            vertexCount++;
            dfs(neighbor, graph, vertexCount);
        }
    }
}

int main() {
    std::ios_base:: sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int M, N;
    cin >> M >> N;
    unordered_map<int, vector<int>> graph;
    int from, to;
    for(int i = 0; i < N; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for(auto& [from, _]: graph)
    {
        int vertexCount = 1;
        if(!visited.count(from))
        {
            dfs(from, graph, vertexCount);
        }
        
        if(vertexCount == 1)
            continue;
        componentsCount++;
    }
    
    cout << componentsCount;
    return 0;
}
