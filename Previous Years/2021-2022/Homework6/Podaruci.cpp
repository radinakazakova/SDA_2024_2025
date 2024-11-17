#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    //int value;
    vector<int> employees;
    int presents = 0;
};

Node tree[1000000];

int dfs(int index)
{    
    int size = tree[index].employees.size();
    if(size == 0)
        return 1;
    
    for(int i = 0; i < size; i++)
    {
        tree[index].presents += dfs(tree[index].employees[i]);
    }
    
    return tree[index].presents + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int boss, worker;
        cin >> boss >> worker;
        tree[boss].employees.push_back(worker);
    }
    
    dfs(0);
    
    for(int i = 0; i < N; i++)
    {
        cout << tree[i].presents << " ";
    }

    return 0;
}
