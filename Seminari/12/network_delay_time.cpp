struct Edge{
   int to, weight; 
 };
 
 struct Node {
    int index, distance;
    
    bool operator<(const Node& other)const {
        return distance > other.distance;
    }
 };

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<Edge>> graph;
        
        for(int i = 0; i < times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> distances(n, INT_MAX);
        distances[k - 1] = 0;
        priority_queue<Node> nextToProcess;
        nextToProcess.push({k, 0});

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

        for(size_t i = 0; i < distances.size(); i++) {
            if(distances[i] == INT_MAX) {
                return -1;
            }
        }

        return *max_element(distances.begin(), distances.end());
    }
};
