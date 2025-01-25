#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to, weight;
};

struct Node
{
    int index, dist;
    
    bool operator<(const Node& other)const
    {
        return dist > other.dist;
    }
};

vector<int> dijkstra(int start, unordered_map<int,vector<Edge>>& graph, int v)
{
    vector<int> distances(v+1, INT_MAX);
    distances[start] = 0;
    priority_queue<Node> pq;
    pq.push({start, 0});
    
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        
        if(curr.dist > distances[curr.index])
            continue;
        
        for(const auto& edge: graph[curr.index])
        {
            int newDist = edge.weight + curr.dist;
            if(newDist < distances[edge.to])
            {
                distances[edge.to] = newDist;
                pq.push({edge.to, newDist});
            }
        }
    }
    
    return distances;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++)
    {
        int N, M; //ot 1 do N vkluchitelno
        cin >> N >> M;
        unordered_map<int, vector<Edge>> graph;
        
        for(int j = 0; j < M; j++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back({to, 6});
            graph[to].push_back({from, 6});
        }
        int ivan;
        cin >> ivan;
        vector<int> distances = dijkstra(ivan, graph, N);
        
        for(int i = 1; i <= N; i++)
        {
            if(i == ivan)
                continue;
            if(distances[i] == INT_MAX)
                cout << -1 << " ";
            else
                cout << distances[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
