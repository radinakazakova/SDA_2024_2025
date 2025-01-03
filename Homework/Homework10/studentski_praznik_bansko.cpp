#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    int index;
    int minTime;
    
    bool operator<(const Node& other)const
    {
        return minTime > other.minTime;
    }
};
struct Edge
{
    int to, time;
};

int findClosestGreaterOrEqualDivisible(int n, int d) 
{
    int remainder = n % d;
    return (remainder == 0) ? n : n + (d - remainder);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int stopsCount, roadsCount, start, end;
    cin >> stopsCount >> roadsCount >> start >> end;
    vector<int> intervals(stopsCount);
    for(int i = 0; i < stopsCount; i++)
    {
        cin >> intervals[i];
    }
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0; i < roadsCount; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        
        graph[from].push_back({to, dist});
    }
    
    vector<int> distances(stopsCount, INT_MAX);
    distances[start] = 0;
    priority_queue<Node> nextToProcess;
    nextToProcess.push({start,0});
    
    while(!nextToProcess.empty())
    {
        auto curr = nextToProcess.top();
        nextToProcess.pop();
        
        if(curr.minTime > distances[curr.index])
        {
            continue;
        }
        
        for(const auto& edge: graph[curr.index])
        {
            int newTime = findClosestGreaterOrEqualDivisible(curr.minTime, intervals[curr.index])+ edge.time;
            
            if(newTime < distances[edge.to])
            {
                distances[edge.to] = newTime;
                nextToProcess.push({ edge.to, newTime});
            }
        }
    }
    
    if(distances[end] == INT_MAX)
    {
        cout << -1;
    }
    else
        cout << distances[end];
    return 0;
}
