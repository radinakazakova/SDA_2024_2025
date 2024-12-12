#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

std::unordered_map<int, std::unordered_set<int>> graph;

bool dfs(int current, std::unordered_set<int> &inProgress, std::unordered_set<int> &visited, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    visited.insert(current);
    inProgress.insert(current); //ako node koito obrabotvame sega, ima cikul
    
    for (int neighbor : graph[current])
    {
        if (inProgress.count(neighbor))
        {
            return true; //ne erase-vame, zashtoto shte generirame nov set za 'inProgress' v 'hasCycle'
        }

        if (visited.count(neighbor))
        {
            continue;
        }

        if (dfs(neighbor, inProgress, visited, graph))
        {
            return true;
        }
    }
    inProgress.erase(current); //obrabotili sme current node-a, trqbva da go mahnem

    return false;
}

bool hasCycle(std::unordered_map<int, std::unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    
    for(auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        unordered_set<int> inProgress;
        if(visited.count(it->first) != 0)
            continue;
        
        if(dfs(it->first, inProgress, visited, graph))
            return true;
    }
    return false;
}

bool solve()
{
    int V, E;
    cin >> V >> E;
    
    for(int i = 0; i < V; i++)
    {
        graph[i];
    }
    
    int x, y, w;
    for(int i = 0; i < E; i++)
    {
        std::cin >> x >> y >> w; //ne se interesuvame ot tegloto
        
        graph[x].insert(y); //nasochen
    }
    
    bool ans = hasCycle(graph);
    graph.clear();
    return ans;
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        bool ans = solve();
        if(ans)
            cout << "true" << " ";
        else
            cout << "false" << " ";
    }
    return 0;
}
