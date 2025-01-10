#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int root[(int)1e6];

int getParent(int x)
{
    if(root[x] == x)
        return x;
    return root[x] = getParent(root[x]);
}

void yunion(int x, int y)
{
    root[x] = root[y];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> N >> M;
    std::iota(root, root + N + 1, 0);
    int from, to;
    for(int i =0; i < M; i++)
    {
        cin >> from >> to;
        yunion(from, to);
    }
    
    cin >> K;
    
    for(int i = 0; i < K; i++)
    {
        cin >> from >> to;
        if(getParent(from) == getParent(to))
        {
            cout << 1 << " ";
        }
        else
            cout << 0 << " ";
    }
    return 0;
}
