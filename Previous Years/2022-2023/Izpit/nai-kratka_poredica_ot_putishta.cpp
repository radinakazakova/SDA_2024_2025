#include <bits/stdc++.h>
using namespace std;

int bfs(int start, int target, unordered_map<int, vector<int>>& graph, unordered_set<int>& prohibited, unordered_set<int>& dontVisit)
{
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    long long path = -1;
    size_t currLen = 0;
    while(!q.empty())
    {
        size_t levelSize = q.size();
        
        while(levelSize)
        {
            auto curr = q.front();
            q.pop();
            visited.insert(curr);
            if(curr == target)
            {
                path = currLen;
                break;
            }
            
            for(auto n: graph[curr])
            {
                if(!visited.count(n) && dontVisit.count(n) == 0 && prohibited.count(n) == 0)
                {
                    q.push(n);
                }
            }
            levelSize--;
        }
        
        if(path != -1) 
        {
            break;
        }
        currLen++;
    }
    
    return path;
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
        graph[to].push_back(from);
        
    }
    
    int P;
    cin >> P;
    
    vector<int> order(P);
    
    for(int i = 0; i < P; i++)
    {
        cin >> order[i];
    }
    
    int K;
    cin >> K;
    unordered_set<int> prohibited;
    for(int i = 0; i < K; i++)
    {
        int node;
        cin >> node;
        prohibited.insert(node);
    }
    
    unordered_set<int> dontVisit(order.begin(), order.end());
    
    int start = order[0];
    
    dontVisit.erase(start);
    size_t res = 0;
    for(int i = 1; i < P; i++)
    {
        dontVisit.erase(order[i]);
        unordered_set<int> visited;
        int path = bfs(start, order[i], graph, prohibited, dontVisit);
        res += path;
        start = order[i];
    }
    
    cout << res;
    return 0;
}
