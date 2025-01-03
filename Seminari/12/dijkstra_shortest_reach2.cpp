struct Edge{
   int to, weight; 
 };
 
 struct Node {
    int index, distance;
    
    bool operator<(const Node& other)const {
        return distance > other.distance;
    }
 };

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<Edge>> graph;
    
    for(int i = 0; i < edges.size(); i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        graph[from].push_back({to, edges[i][2]});
        graph[to].push_back({from, edges[i][2]});
    }
    
    vector<int> distances(n, INT_MAX);
    distances[s - 1] = 0;
    priority_queue<Node> nextToProcess;
    nextToProcess.push({s, 0});
    
    while(!nextToProcess.empty())
    {
        auto curr = nextToProcess.top();
        nextToProcess.pop();
        
        if(curr.distance > distances[curr.index - 1])
            continue;
            
        for(const auto& edge: graph[curr.index])
        {
            int newWeight = curr.distance + edge.weight;
            if(newWeight < distances[edge.to - 1])
            {
                distances[edge.to - 1] = newWeight;
                nextToProcess.push({edge.to, newWeight});
            }
        }
    }
    distances.erase(distances.begin() + s - 1);
    for(size_t i = 0; i < distances.size(); i++) {
        if(distances[i] == INT_MAX) {
            distances[i] = -1;
        }
    }
    return distances;
    
}
