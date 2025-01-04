#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

struct Edge
{
    int to, kg, time;
};

struct Node
{
    int index,time;
    
    bool operator<(const Node& other)const
    {
        return time > other.time;
    }
};

int startNode = 1;
int endNode;
int maxTime;
int maxWeight = INT_MIN;

bool pathExistsForWeightInTime(unordered_map<int, vector<Edge>>& graph, int intersectionsCount, int weight)
{
    vector<int> distances(intersectionsCount + 1, INT_MAX);
    priority_queue<Node> nextToProcess;
    distances[startNode] = 0;
    nextToProcess.push({startNode, 0});
    
    while(!nextToProcess.empty())
    {
        auto curr = nextToProcess.top();
        nextToProcess.pop();
        
        if(curr.time > distances[curr.index])
        {
            continue;
        }
        
        for(const auto& edge: graph[curr.index])
        {
            if(edge.kg > weight)
                continue;
            int newTime = curr.time + edge.time;
            if(newTime < distances[edge.to])
            {
                distances[edge.to] = newTime;
                nextToProcess.push({edge.to, newTime});
            }
        }
    }
    return distances[endNode] <= maxTime;
}

int binarySearchMinKg(unordered_map<int, vector<Edge>>& graph, int intersectionsCount, int tunnelsCount)
{
    int left = 0;
    int right = maxWeight;
    int res = -1;
    
    while(left <= right)
    {
        int mid = left +(right - left)/2;
        if (pathExistsForWeightInTime(graph, intersectionsCount, mid)) 
        {
            res = mid;
            right = mid - 1;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M >> maxTime;
    endNode = N;
    
    unordered_map<int, vector<Edge>> graph(N);
    for(int i = 0; i < M; i++)
    {
        int from, to, kg, time;
        cin >> from >> to >> kg >> time;
        maxWeight = max(maxWeight, kg);
        graph[from].push_back({to, kg, time});
    }
    
    cout << binarySearchMinKg(graph, N, M);
    return 0;
}
