#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int curr, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& processing)
{
    visited.insert(curr);
    processing.insert(curr);
    for(auto n: graph[curr])
    {
        if(processing.count(n))
            return true;
        
        if(visited.count(n))
            continue;
        if(hasCycle(n, graph, visited, processing))
        {
            return true;
        }
    }
    
    processing.erase(curr);
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        unordered_map<int, vector<int>> graph;
        int V, E;
        cin >> V >> E;
        
        for(int i = 0; i < E; i++)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            
            graph[from].push_back(to);
        }
        
        unordered_set<int> visited;
        bool cycle = false;
        for(int i = 1; i <= V; i++)
        {
            if(!visited.count(i))
            {
                unordered_set<int> processing;
                cycle = hasCycle(i, graph, visited, processing);
            }
            
            if(cycle)
                break;
        }
        
        if(cycle)
            cout << "true" << " ";
        else
            cout << "false" << " ";
    }
    return 0;
}
