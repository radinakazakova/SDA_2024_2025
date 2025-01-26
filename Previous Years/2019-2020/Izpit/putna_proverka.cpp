#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, weight;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int V, E;
    cin >> V >> E;
    
    unordered_map<int, vector<Edge>> graph;
    
    for(int i = 0; i < E; i++)
    {
        int from, to, weight;
        
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    
    int K;
    cin >> K;
    
    vector<int> order(K);
    
    for(int i =0; i < K; i++)
    {
        cin >> order[i];
    }
    
    int curr = order[0];
    bool hasPath = false;
    int res = 0;
    
    for(int i = 1; i < K; i++)
    {
        for(auto n: graph[curr])
        {
            if(n.to == order[i])
            {
                hasPath = true;
                res += n.weight;
                break;
            }
        }
        
        curr = order[i];
        if(!hasPath)
           break; 
    }
    
    if(!hasPath)
        cout << -1;
    else
        cout << res;
    return 0;
}
