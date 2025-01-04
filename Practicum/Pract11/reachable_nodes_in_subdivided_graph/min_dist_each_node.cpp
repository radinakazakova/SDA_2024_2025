class Solution {
public:
    vector<vector<pair<int, int>>> createGraph(vector<vector<int>>& edges, int& n) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2] + 1});
            graph[edge[1]].push_back({edge[0], edge[2] + 1});
        }
        return graph;
    }

    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start) {
        vector<int> distance(n, INT_MAX);
        distance[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, start}); 
        
        while (!minHeap.empty()) {
            auto [currentDistance, currentNode] = minHeap.top();
            minHeap.pop();

            if (currentDistance > distance[currentNode])
                continue;

            for (auto& [neighbor, edgeWeight] : graph[currentNode]) {
                if (currentDistance + edgeWeight < distance[neighbor]) {
                    distance[neighbor] = currentDistance + edgeWeight;
                    minHeap.push({distance[neighbor], neighbor});
                }
            }
        }

        return distance;
    }
    
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph = createGraph(edges, n);
        vector<int> distance = dijkstra(n, graph, 0);
        int ans = 0;
        for (int node = 0; node < n; ++node) {
            if (distance[node] <= maxMoves)
                ++ans;
        }

        for (auto& edge : edges) {
            int source = edge[0];
            int destination = edge[1];
            int nodesInBetween = edge[2];

            int nodesFromSourceWithinMaxMoves = max(0, maxMoves - distance[source]);
            int nodesFromDestinationWithinMaxMoves = max(0, maxMoves - distance[destination]);

            ans += min(nodesInBetween, nodesFromSourceWithinMaxMoves + nodesFromDestinationWithinMaxMoves);
        }

        return ans;
    }
};
