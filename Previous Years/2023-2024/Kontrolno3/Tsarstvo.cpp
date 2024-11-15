#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    vector<int> workersIdx;
    int workersCount = 0;
};

Node tree[1000001];

int countWorkers(int index)
{
    if(tree[index].workersIdx.empty())
        return 0;
    
    int size = tree[index].workersIdx.size();
    tree[index].workersCount += size;
    for(int i = 0; i< size; i++)
    {
        tree[index].workersCount += countWorkers(tree[index].workersIdx[i]);
    }
    return tree[index].workersCount;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    for(int i= 0; i<N-1;i++)
    {
        int boss, worker;
        cin >> boss >> worker;
        tree[boss].workersIdx.push_back(worker);
    }
    
    countWorkers(0);
    
    for(int i =0; i< N;i++)
    {
        cout << tree[i].workersCount <<' ';
    }
    
    return 0;
}
