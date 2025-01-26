#include <bits/stdc++.h>
using namespace std;

int bfs(int start, int target, unordered_map<int, vector<int>>& graph, unordered_set<int>& dontVisit)
{
    queue<int> q;
    q.push(start);
    
    unordered_set<int> visited;
    int res = -1;
    int currLen = 0;
    while(!q.empty())
    {
        size_t levelSize = q.size();
        
        while(levelSize--)
        {
            auto curr = q.front();
            q.pop();
            
            if(curr == target)
            {
                res = currLen;
                break;
            }
            
            visited.insert(curr);
            for(auto n: graph[curr])
            {
                if(!visited.count(n) && !dontVisit.count(n))
                {
                    q.push(n);
                }
            }
        }
        currLen++;
        if(res != -1)
            break;
    }
    
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<int, vector<int>> graph;
    for(int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        
        graph[from].push_back(to);
    }
    
    int K;
    cin>>K;
    vector<int> order(K);
    for(int i = 0; i < K; i++)
    {
        cin >> order[i];
    }
    
    unordered_set<int> dontVisit(order.begin(), order.end());
    int start = order[0];
    dontVisit.erase(start);
    
    bool hasPath = false;
    size_t resLen = 0;
    for(int i = 1; i < K; i++)
    {
        dontVisit.erase(order[i]);
        int pathLen = bfs(start, order[i], graph, dontVisit);
        
        if(pathLen == -1)
        {
            hasPath = false;
            break;
        }
        hasPath = true;
        resLen += pathLen;
        start = order[i];
    }
    
    if(!hasPath)
    {
        cout << -1;
    }
    else
        cout << resLen;
    return 0;
}
