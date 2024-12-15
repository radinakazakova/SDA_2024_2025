#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;

int bfs(int start, unordered_map<int, unordered_set<int>>& graph, const vector<int>& groups, int myGroup) {
    queue<int> q;
    vector<int> distances(graph.size() + 1, INT_MAX);
    q.push(start);
    distances[start] = 0;

    int minDistance = INT_MAX;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distances[neighbor] == INT_MAX) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);

                if (groups[neighbor] == myGroup && neighbor != start) {
                    minDistance = min(minDistance, distances[neighbor]);
                }
            }
        }
    }

    return minDistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        graph[v].insert(w);
        graph[w].insert(v);
    }

    vector<int> groups(V + 1);
    for (int i = 1; i <= V; i++) {
        cin >> groups[i];
    }

    int myGroup;
    cin >> myGroup;

    int minDistance = INT_MAX;

    for (int i = 1; i <= V; i++) {
        if (groups[i] == myGroup) {
            int distance = bfs(i, graph, groups, myGroup);
            minDistance = min(minDistance, distance);
        }
    }

    cout << (minDistance == INT_MAX ? -1 : minDistance);

    return 0;
}
