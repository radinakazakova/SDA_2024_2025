struct Edge
{
    int to;
    double prob;
};

struct Node
{
    int index;
    double prob;

    bool operator<(const Node& other) const
    {
        return prob < other.prob;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<Edge>> graph;
        for(size_t i = 0; i < edges.size(); i++) 
        {
            graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }
        
        vector<double> probability(n, 0);
        probability[start_node] = 1;
        priority_queue<Node> nextToProcess;
        nextToProcess.push({start_node, 1});

        while(!nextToProcess.empty())
        {
            auto curr = nextToProcess.top();
            nextToProcess.pop();

            if(curr.prob < probability[curr.index])
                continue;

            for(const auto& edge: graph[curr.index])
            {
                double newProb = curr.prob * edge.prob;
                if(newProb > probability[edge.to])
                {
                    probability[edge.to] = newProb;
                    nextToProcess.push({edge.to, newProb});
                }
            }
        }

        return probability[end_node];
    }
};
