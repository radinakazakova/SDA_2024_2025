
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, weight;
};

int maxToll = INT_MIN;
int maxCount = INT_MIN;
unordered_map<int, int> tollCount;
unordered_set<int> visited;

void dfs(int curr, unordered_map<int, vector<Edge>>& graph, int depth, int maxLen, int currLen = 0)
{
    if(depth == maxLen)
    {
        tollCount[currLen]++;
        return;
    }
    
    visited.insert(curr);
    
    for(auto& edge: graph[curr])
    {
        if(!visited.count(edge.to))
        {
            dfs(edge.to, graph, depth + 1, maxLen, currLen + edge.weight);
        }
    }
    
    visited.erase(curr);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int V, E;
    cin >> V >> E;
    unordered_map<int, vector<Edge>> graph;
    int from, to, weight;
    
    for(int i = 0; i < E;i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    
    int K;
    cin >> K;
    
    for(int i = 1; i <= V; i++)
    {
        visited.clear();
        dfs(i, graph, 0, K); //dfs, zashtoto iskame all paths from source
    }
    if(tollCount.empty())
    {
        cout << "-1";
        return 0;
    }
    
    for(const auto& [toll, count]: tollCount)
    {
        if(count > maxCount)
        {
            maxCount = count;
            maxToll = toll;
        }
        else if(count == maxCount && toll > maxToll)
        {
            maxToll = toll;
        }
    }
    
    cout << maxToll;
    return 0;
}
