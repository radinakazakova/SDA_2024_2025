#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

struct Edge {
    int to, weight;
};

struct Node {
    int index;
    long long dist;

    bool operator<(const Node& other) const {
        return dist > other.dist; 
    }
};

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<vector<Edge>> graph(nodesCount+1, vector<Edge>());

    for (int i = 0; i < edgesCount; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    int startNode = 1;
    int endNode = nodesCount;
    vector<long long> distances(nodesCount + 1, LLONG_MAX); 
    vector<long long> pathsCount(nodesCount + 1, 0);        

    priority_queue<Node> nextToProcess;

    distances[startNode] = 0; 
    pathsCount[startNode] = 1; 
    nextToProcess.push({startNode, 0});

    while (!nextToProcess.empty()) {
        auto curr = nextToProcess.top();
        nextToProcess.pop();

        if (curr.dist > distances[curr.index])
            continue;

        for (const auto& edge : graph[curr.index]) {
            long long newDist = curr.dist + edge.weight;

            if (newDist < distances[edge.to]) {
                distances[edge.to] = newDist; 
                pathsCount[edge.to] = pathsCount[curr.index];
                nextToProcess.push({edge.to, newDist});
            }
            else if (newDist == distances[edge.to]) {
                pathsCount[edge.to] = (pathsCount[edge.to] + pathsCount[curr.index]) % MOD;
            }
        }
    }

    if(distances[endNode] == LLONG_MAX)
    {
        cout << "-1 0";
    }
    else
    {
        cout << distances[endNode] << " " << pathsCount[endNode];
    }
    
    return 0;
}
