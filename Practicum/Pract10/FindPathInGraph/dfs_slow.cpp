class Solution {
public:
    bool findPath(int start, int target, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited)
    {
        visited.insert(start);

        for(auto neighbor: graph[start])
        {
            if(neighbor == target)
                return true;
            if(!visited.count(neighbor))
                if(findPath(neighbor, target, graph, visited))
                    return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination || n == 0)
            return true;

        unordered_map<int, unordered_set<int>> graph;

        for(int i = 0; i < n; i++)
        {
            graph[i] = {};
        }

        for(auto edge: edges)
        {
            int v = edge[0];
            int w = edge[1];
            graph[v].insert(w);
            graph[w].insert(v);        
        }
        unordered_set<int> visited;
        return findPath(source, destination, graph, visited);
    }
};
