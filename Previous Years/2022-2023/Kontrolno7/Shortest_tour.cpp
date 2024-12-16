#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
void initGraph(int& N)
{
    for(int i = 0; i < N; i++)
    {
        graph[i];
    }
}

long long bfs(int from, int to, unordered_set<int>& dontVisit)
{
    queue<int> q;
    q.push(from);
    unordered_set<int> visited;
    visited.insert(from);
    
    long long res = -1;
    long long currLen = 0;
    
    while(!q.empty())
    {
        int levelSize = q.size();
        
        for(int i = 0; i < levelSize; i++)
        {
            int curr = q.front();
            q.pop();
            visited.insert(curr);
            
            if(curr == to)
            {
                res = currLen;
                break;
            }
            
            for(auto& neighbor: graph[curr])
            {
                if(!dontVisit.count(neighbor) && !visited.count(neighbor))
                {
                    q.push(neighbor);
                }
            }
        }
        
        if (res != -1) 
        {
            break;
        }
        currLen++;
    }
    
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    initGraph(N);
    for(int e = 0; e < M; e++)
    {
        int v, w;
        cin >> v >> w;
        graph[v].insert(w);
    }
    
    int K;
    cin >> K;
    
    vector<int> order(K);
    unordered_set<int> dontVisit;
    for(int k = 0; k < K; k++)
    {
        cin >> order[k];
        dontVisit.insert(order[k]);
    }
    
    long long pathLen = 0;
    dontVisit.erase(order[0]);
    
    for(int i = 1; i < K; i++)
    {
        dontVisit.erase(order[i]);
        long long path = bfs(order[i-1], order[i], dontVisit);
        
        if(path == -1)
        {
            pathLen = -1;
            break;
        }
        else
        {
            pathLen += path;
        }
    }
    
    cout << pathLen;
    
    return 0;
}
