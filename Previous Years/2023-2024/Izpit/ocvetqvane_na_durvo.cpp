#include <bits/stdc++.h>
using namespace std;

bool colored[1000001];
size_t parent[1000001];
vector<long long> tree[1000001];

void dfs(size_t node, size_t& count)
{
    for(auto n: tree[node])
    {
        dfs(n, count); //otivame kolkoto mojem po-dulbochina
    }
    
    if(!colored[node])
    {
        colored[node] = true;
        colored[parent[node]] = true; //mqstoto, na koeto shte pusnem kofata
        count++;
        
        for(auto n: tree[parent[node]]) //ocvetqvame decata
        {
            colored[n] = true;
        }
        
        colored[parent[parent[node]]] = true; //roditelq
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        
        if(l != -1)
        {
            parent[l] = i;
            tree[i].push_back(l);
        }
        if(r != -1)
        {
            parent[r] = i;
            tree[i].push_back(r);
        }
    }
    
    size_t count = 0;
    dfs(0, count);
    cout << count;
    return 0;
}
