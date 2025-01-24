#include <bits/stdc++.h>
using namespace std;
//не ни е нужно inProgress в проверка за цикъл в ненасочен граф
//тук е изпълнено visited + parent = inProgress
bool dfs(int curr, int parent, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited)
{
    visited.insert(curr);
    
    for(auto n: graph[curr])
    {
        if(n == parent)
            continue;

        if(visited.count(n))
            return true;
        
        if(dfs(n, curr, graph, visited))
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        size_t count = 0;
        int V, E;
        cin >> V >> E;
        unordered_map<int, vector<int>> graph;
        for(int j = 0; j < E; j++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        unordered_set<int> visited;
        for(int j = 0; j < V; j++) //важно, за да обходим и възли, които нямат никакви ребра
        {
            bool hasCycle = false;
            if(!visited.count(j))
            {
                hasCycle = dfs(j, j, graph, visited);
            }
            if(hasCycle)
                count++;
        }    
        cout << count << '\n';
    }
    

    return 0;
}
