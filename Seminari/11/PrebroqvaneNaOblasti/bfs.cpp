#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void bfs(const int start, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        // No need for levels
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        {
            if (!visited.count(neighbor))
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int startFromEveryVertex(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    int count = 0;
    
    for(auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        if(visited.count(it->first) != 0)
            continue;
        
        bfs(it->first, graph, visited);
        count++;
    }
    
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int cities, paths;
        cin >> cities >> paths;
        unordered_map<int, unordered_set<int>> graph;

        for(int j = 0; j < cities; j++)
        {
            graph[j];
        }
        
        for(int i = 0; i < paths; i++)
        {
            int city1, city2;
            cin>>city1>>city2;
            graph[city1].insert(city2);
            graph[city2].insert(city1);
        }
        
        int ans = startFromEveryVertex(graph);
        cout << ans << " ";
    }
    return 0;
}
