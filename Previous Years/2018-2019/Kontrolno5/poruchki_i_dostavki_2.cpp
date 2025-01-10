#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to;
};

long long sumOfPaths = 0;
unordered_set<int> visited;

void bfs(int start, unordered_map<int, vector<Edge>>& graph)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);
    int len = 0;
        
    while(!q.empty())
    {
        size_t levelSize = q.size();
        
        for(int i = 0; i < levelSize; i++)
        {
            auto curr = q.front();
            q.pop();
            
            sumOfPaths += len;
            
            for(auto& edge: graph[curr])
            {
                if(!visited.count(edge.to))
                {
                    q.push(edge.to);
                    visited.insert(edge.to);
                }
            }
        }
        len++;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int K;
    cin >> K;
    
    unordered_map<int, vector<Edge>> graph;
    int from,to;
    for(int i = 0; i < K; i++)
    {
        cin >> from >> to;
        graph[from].push_back({from, to});
        graph[to].push_back({to, from});
    }
    
    bfs(0, graph); //за най-кратък път, тегло 1 и не знаем колко на брой nodes имаме
    cout << sumOfPaths;
    
    return 0;
}
