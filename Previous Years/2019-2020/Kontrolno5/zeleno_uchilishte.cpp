#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to;
};

unordered_set<int> visited;
int V,E,K;
vector<int> resNodes;

void bfs(int start, unordered_map<int, vector<Edge>>& graph, int maxLen)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);
    int len = 0;
    vector<int> distances;

    while(!q.empty())
    {
        size_t levelSize = q.size();
        
        for(int i = 0; i < levelSize; i++)
        {
            auto curr = q.front();
            q.pop();
            
            if(len == maxLen)
            {
                resNodes.push_back(curr);
            }
            
            for(auto& edge: graph[curr])
            {
                if(!visited.count(edge.to))
                {
                    visited.insert(edge.to);
                    q.push(edge.to);
                }
            }
        }
        len++;
        if(len > maxLen)
            break;
    }
}
    
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> V >> E >> K;
    unordered_map<int, vector<Edge>> graph;
    int from, to;
    
    for(int i = 0; i < E; i++)
    {
        cin >> from >> to;
        graph[from].push_back({from, to});
        graph[to].push_back({to, from});
    }
    
    int start = V;
    
    bfs(start, graph, K);
    if(resNodes.empty())
    {
        cout << "-1";
        return 0;
    }
    sort(resNodes.begin(), resNodes.end(), [](const int& f, const int& s)
         {
            return f < s;
         });
    
    for(size_t i = 0; i < resNodes.size(); i++)
    {
        cout << resNodes[i] << " ";
    }
    return 0;
}
