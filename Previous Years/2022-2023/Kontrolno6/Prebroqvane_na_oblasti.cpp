#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

void dfs(int curr, unordered_set<int>& visited)
{
    visited.insert(curr);
    
    for(auto& neighbor: graph[curr])
    {
        if(!visited.count(neighbor))
            dfs(neighbor, visited);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        int cities, roads;
        cin >> cities >> roads;
        for(int r = 0; r < roads; r++)
        {
            int v, w;
            cin >> v >> w;
            graph[v].insert(w);
            graph[w].insert(v);
        }
        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i < cities; i++)
        {
            if(!visited.count(i))
            {
                count++;
                dfs(i, visited);
            }
        }
        
        cout << count << " ";
        graph.clear();
    }
    return 0;
}
