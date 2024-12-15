class Solution {
public:
    void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int& edgesCount, int& vertexCount)
    {
      //за всяка компонента на свързаност проверява колко възли има и пресмята ребрата
        visited.insert(curr);
        vertexCount++;
        edgesCount += graph[curr].size();

        for(auto& v: graph[curr])
        {
            if(!visited.count(v))
                dfs(v, graph, visited, edgesCount, vertexCount);
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;

        for(int i = 0; i < n; i++)
        {
            graph[i] = {};
        }

        for(auto& edge: edges)
        {
            int v = edge[0];
            int w = edge[1];
            graph[v].insert(w);
            graph[w].insert(v);
        }

        unordered_set<int> visited;
        int res = 0;
        for(int i = 0; i < n; i++) //за да преминем през всяка компонента на свързаност, проверяваме чрез visited
        {
            if(!visited.count(i)){
                int edgesCount = 0;
                int vertexCount = 0;
                dfs(i, graph, visited, edgesCount, vertexCount);

                if(edgesCount / 2 == (vertexCount* (vertexCount - 1) / 2)) //формула за пресмятане на ребра спрямо броя възли
                    res++; //ако имаме всички ребра, имаме пълна компонента
            }
        }
        return res;
    }
};
