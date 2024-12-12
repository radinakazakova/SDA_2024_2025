class Solution {
    vector<vector<int>> result;
    //за всеки node ще обхождаме неговите съседи рекурсивно, backtracking - ако стигнем до target добавяме, ако не стигнем се връщаме назад
    void dfs(int current, vector<int>& path, vector<vector<int>>& graph)
    {
        path.push_back(current);
        if(current == graph.size() - 1)
        {
            result.push_back(path);
            path.pop_back();
            return;
        }

        for(auto& neighbour: graph[current]) 
        {
            dfs(neighbour, path, graph);
        }
        
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, path, graph);
        return result;
    }
};
