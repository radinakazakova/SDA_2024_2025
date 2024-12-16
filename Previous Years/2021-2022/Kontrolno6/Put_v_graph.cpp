#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_map<int,pair<bool, int>> visited; //pair (visited, in which component can be found)
//с componentsCount отбелязваме и проследяваме всеки възел в кой по номер компонент се намира
//тъй като имаме неориентиран граф, то за всяка двойка възли в даден компонент ще има път
//накрая сравняваме само дали двойката е в един и същи компонент
int componentsCount = 0;

void initGraph(int& N)
{
    for(int i = 1; i <= N; i++)
    {
        graph[i];
    }
}

void dfs(int curr)
{
    visited[curr] = {true, componentsCount};
    for (const size_t &element: graph[curr]) {
        if (!visited[element].first) {
            dfs(element);
        }
    }
}

void traverse(int N)
{
    for(int i = 1; i <=N; i++)
    {
        if(!visited[i].first)
        {
            dfs(i);
            componentsCount++;
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N,M;
    cin >> N >> M;
    
    initGraph(N);
    for(int e = 0; e < M; e++)
    {
        int v, w;
        cin >> v >> w;
        graph[v].insert(w);
        graph[w].insert(v);
    }
    
    int K;
    cin >> K;
    traverse(N);

    for(int i = 0; i < K; i++)
    {    
        int from, to;
        cin >> from >> to;
        
        cout << (visited[from].second == visited[to].second) << " ";
    }
    return 0;
}
