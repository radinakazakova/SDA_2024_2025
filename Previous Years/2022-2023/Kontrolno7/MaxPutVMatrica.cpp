#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long grid[1000][1000]={};
bool special[1000][1000]={};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    int K;
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int x,y;
        cin >> x >> y;
        special[x][y] = true;
    }
    
    for(int i = 1; i < N; i++)
    {
        grid[0][i] += grid[0][i-1]; //do vsqko na purvi red se stiga samo nadqsno
        grid[i][0] += grid[i-1][0]; //do vsqko na purva kolona se stiga samo nadolu
    }
    
    for(int x = 1; x < N; x++)
    {
        for(int y = 1; y < N; y++)
        {
            long long curr = grid[x][y];
            
            grid[x][y] = max(grid[x-1][y] + curr, grid[x][y-1] + curr);
            if(special[x][y])
            {
                grid[x][y] = max(grid[x][y], grid[x-1][y-1] + curr);
            }
        }
    }
    
    cout << grid[N - 1][N - 1];
    return 0;
}
