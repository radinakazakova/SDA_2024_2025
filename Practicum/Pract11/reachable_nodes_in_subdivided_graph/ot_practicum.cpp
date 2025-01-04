struct Edge
{
    int to, subs;
};

struct Node
{
    int index, dist; //dist е минимума subs, които се достигат до този Node от 0 (колко moves сме изхобили, за да стигнем до тук)

    bool operator<(const Node& other)const
    {
        return dist > other.dist;
    }
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, vector<Edge>> graph;
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> dist(n, INT32_MAX);
        vector<vector<int>> done(n, vector<int>(n, 0));

        int reached = 0;

        priority_queue<Node> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if (curr.dist > dist[curr.index]) 
                continue;

            reached++; // Count the reachable original node

            for (const auto& edge : graph[curr.index]) {
                // Calculate how many subdivided nodes can be traversed on this edge
                int remainingMoves = maxMoves - curr.dist;
                if (remainingMoves <= 0) 
                    continue; // No moves left to traverse this edge

                int used = min(edge.subs, remainingMoves);
                done[curr.index][edge.to] = max(done[curr.index][edge.to], used);

                // Distance to reach the neighbor node
                int dn = curr.dist + edge.subs + 1;
                if (dn < dist[edge.to] && dn <= maxMoves) {
                    dist[edge.to] = dn;
                    pq.push({edge.to, dn});
                }
            }            
        }  

        // Count the reachable subdivided nodes on each edge
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            reached += min(w, done[u][v] + done[v][u]);
        }

        return reached;
    }
};
