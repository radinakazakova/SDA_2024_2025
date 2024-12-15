class Solution {
public:

    void dfs(unordered_map<int, unordered_set<int>>& graph, int start, unordered_set<int>& visited)
    {
        visited.insert(start);
        for(auto& neighbor: graph[start])
        {
            if(!visited.count(neighbor))
                dfs(graph, neighbor, visited);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, unordered_set<int>> graph;

        for(auto& inv: invocations)
        {
            graph[inv[0]].insert(inv[1]);
        }

        unordered_set<int> visited;
        dfs(graph, k, visited); //изпозваме, за да определим кои са suspicious чрез visited

        bool isInvoked = false;
        for(int i = 0; i < n; i++) //обхождаме всички възли, за да разберем дали някой външен invoke-ва
        {
            if(!visited.count(i)) //за възли, които не са suspicious
            {
                for(auto neighbor: graph[i]) 
                {
                    if(visited.count(neighbor)) //проверяваме дали invoke-ва suspicious възел
                    {
                        isInvoked = true;
                        break; //ако поне един invoke-ва, значи ще ги запазим в резултата
                    }
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(visited.count(i)) //добавяме suspicious само, ако имаме invoke 
            {
                if(isInvoked)
                    res.push_back(i);
            }
            else //останалите ги добавяме във всички случаи
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
