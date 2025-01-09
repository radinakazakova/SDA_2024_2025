
 struct Edge {
    int from, to, weight;
    
    bool operator<(const Edge& other)const
    {
        return weight > other.weight;
    }
 };
        
            
 
 int _prim(int n, unordered_map<int, vector<Edge>>& graph, int start)
 {
    priority_queue<Edge> pq;
    unordered_set<int> visited;
    pq.push({start, start, 0});
    int totalWeight = 0;
    
    while(!pq.empty() && visited.size() < n)
    {
        auto curr = pq.top();
        pq.pop();
        
        if(visited.count(curr.to))
            continue;
        visited.insert(curr.to);
        totalWeight += curr.weight;
        for(auto& adj: graph[curr.to])
        {
            if(visited.count(adj.to))
            {
                continue;
            }
            
            pq.push(adj);
        }
    }
    return totalWeight;
 }

int prims(int n, vector<vector<int>> edges, int start) {
    unordered_map<int, vector<Edge>> graph;
    
    for(int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][0], edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][1], edges[i][0], edges[i][2]});
    }
    
    return _prim(n, graph, start);
}
