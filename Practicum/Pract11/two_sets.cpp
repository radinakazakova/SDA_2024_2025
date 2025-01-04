#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;
struct Edge
{
    int to;
    long long weight;
};

struct Node
{
    int index;
    long long dist;
    bool operator<(const Node& other)const
    {
        return dist > other.dist;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    unordered_map<int, vector<Edge>> graph;
    
    for(int i = 0; i < M; i++)
    {
        int from, to;
        long long weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    
    int K;
    cin >> K;
    vector<int> setT;
    
    for(int i = 0; i < K; i++)
    {
        int vertex;
        cin >> vertex;
        setT.push_back(vertex);
    }
    
    vector<long long> distances(N, LLONG_MAX);
    priority_queue<Node> nextToProcess;
    
    //bazata ni e set-a T
    //trugvaiki ot koito i da e element ot T - namirame min distance do vseki element ot set-a S
    for(const auto& t: setT)
    {
        distances[t] = 0;
        nextToProcess.push({t, 0});
    }
    
    while(!nextToProcess.empty())
    {
        auto curr = nextToProcess.top();
        nextToProcess.pop();
        
        if(curr.dist > distances[curr.index])
            continue;
        
        for(const auto& edge: graph[curr.index])
        {
            int newDist = curr.dist + edge.weight;
            
            if(newDist < distances[edge.to])
            {
                distances[edge.to] = newDist;
                nextToProcess.push({edge.to, newDist});
            }
        }
    }
    
    int Q;
    cin >> Q;
    
    for(int i = 0 ; i < Q; i++)
    {
        int node;
        cin >> node;
        cout << distances[node] << '\n';
    }
    
    return 0;
}
