#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, weight;
};

struct Node
{
    int index;
    long long distance;
    
    bool operator<(const Node& other)const
    {
        return distance > other.distance;
    }
};


vector<long long> dijkstra(int start, unordered_map<int, vector<Edge>>& graph, int vertexCount)
{
    vector<long long> distances(vertexCount + 1, INT_MAX);
    distances[start] = 0;
    priority_queue<Node> nextToProcess;
    nextToProcess.push({start, 0});
    
    while(!nextToProcess.empty())
    {
        auto curr = nextToProcess.top();
        nextToProcess.pop();
        
        if(curr.distance > distances[curr.index])
            continue;
        
        for(const auto& edge: graph[curr.index])
        {
            long long newDist = curr.distance + edge.weight;
            
            if(distances[edge.to] > newDist)
            {
                distances[edge.to] = newDist;
                nextToProcess.push({edge.to, newDist});
            }
        }
    }
    return distances;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int V,E;
    cin >> V >> E;
    
    unordered_map<int, vector<Edge>> graph; //може и с вектор вместо мап
    int from,to,weight;
    for(int i =0; i < E; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    int s;
    cin >> s;
    vector<long long> res = dijkstra(s, graph, V); 
    
    for(size_t i = 1; i < res.size(); i++)
    {
        if(i == s)
            continue;
        if(res[i] == INT_MAX)
            cout << "-1" << " ";
        else
            cout << res[i] << " ";
    }
    return 0;
}
