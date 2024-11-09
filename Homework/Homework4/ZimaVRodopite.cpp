#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool validCoords(int rows, int cols, int row, int col)
{
    return row > 0 && row <= rows && col > 0 && col <= cols;
}

int getRottenCount(queue<pair<int,int>>& rotten, int days, int rows, int cols, vector<bool>& seen)
{
    if(cols == 0 || rows == 0)
        return 0;
    vector<pair<int,int>> coords = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<pair<int,int>> previousRotten;
    while(days /*&& rotten.size() != rows*cols*/)
    {
        int size = rotten.size();
        while(size){
            int row = rotten.front().first;
            int col = rotten.front().second;
            for(int i = 0; i < 4; i++)
            {
                int newRow = row + coords[i].first;
                int newCol = col + coords[i].second;

                if(validCoords(rows,cols,newRow,newCol) && seen[(newRow-1)*cols + (newCol - 1)] == false)
                {
                    rotten.push({newRow,newCol});
                    seen[(newRow-1)*cols + (newCol - 1)] = true;

                }
            }
            auto prev = rotten.front();
            previousRotten.push_back(prev);
            rotten.pop();
            size--;
        }
        days--;
    }
    
    return rotten.size() + previousRotten.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    int M;
    int T;
    cin >> N >> M >> T;
    
    vector<bool> seen(N*M, 0);
    queue<pair<int,int>> rotten;
    
     for (int i = 0; i < 2; ++i) {
        int row, col;
        if (cin >> row >> col){
            rotten.push({row, col});
            seen[(row-1)*M + (col-1)] = true;
        }
        else 
            break;
    }
    
    int allApplesCount = N*M;
    int rottenCount = getRottenCount(rotten, T, N, M, seen);
    cout << (allApplesCount - rottenCount);
    return 0;
}
