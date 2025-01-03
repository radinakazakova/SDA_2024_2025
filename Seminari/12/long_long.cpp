#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge
{
    int from, to;
    long long weight;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n,m,s,t;
    cin >> n >> m>> s>> t;
    
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    
    vector<long long> distances(n + 1, LLONG_MIN);
    
    distances[s] = 0;
    
    for(int i = 0; i < m -1; i++)
    {
        for(const auto& edge: edges)
        {
            distances[edge.to]=max(distances[edge.from] + edge.weight, distances[edge.to]);
        }
    }
    
    if(distances[t] == LLONG_MIN)
    {
        cout << -1;
    }else
        cout << distances[t];
    return 0;
}
