#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

//важно за единия тест кейс
void initGraph(const size_t& N) {
    for (size_t j = 0; j < N; ++j) {
        graph[j];
    }
}

//може и без pathVisited
bool hasCycle(int curr, unordered_set<int>& visited, unordered_set<int>& pathVisited)
{
    visited.insert(curr);
    pathVisited.insert(curr);
    
    for(auto& neighbor: graph[curr])
    {
        if(pathVisited.count(neighbor))
            return true;
        
        if(!visited.count(neighbor) && hasCycle(neighbor, visited, pathVisited))
            return true;
    }
    
    pathVisited.erase(curr);
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >>N;
    
    for(int n = 0; n < N; n++)
    {
        int V, E;
        cin >> V >> E;
        initGraph(V);
        for(int e = 0; e < E; e++)
        {
            int v, w, weight;
            cin >> v >> w >> weight;
            graph[v].insert(w);
        }
        unordered_set<int> visited;
        bool cycle = false;
        for(auto it = graph.cbegin(); it != graph.cend(); it++)
        {
            if(!visited.count(it->first))
            {
                unordered_set<int> pathVisited;
                if(hasCycle(it->first, visited, pathVisited))
                {
                    cycle = true;
                    break;
                }
            }
        }
        if(cycle)
        {
            cout << "true" << " ";
        }
        else
            cout << "false" << " ";
        graph.clear();
    }
    return 0;
}
