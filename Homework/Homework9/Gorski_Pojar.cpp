#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int, int>> coords = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int size, int row, int col)
{
    return row < size && row >= 0 && col < size && col >=0;
}

void dfs(int N, int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& visited, int& minRow, int& minCol, int& maxRow, int& maxCol)
{
    visited[row][col] = 1;
    
    minRow = min(minRow, row);
    minCol = min(minCol, col);
    maxRow = max(maxRow, row);
    maxCol = max(maxCol, col);
    
    for(int j = 0; j < 4; j++)
    {
        int newRow = row + coords[j].first;
        int newCol = col + coords[j].second;
            
        if(isValid(N, newRow, newCol) && !visited[newRow][newCol] && matrix[newRow][newCol] == 1)
            dfs(N, newRow, newCol, matrix, visited, minRow, minCol, maxRow, maxCol);
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> areas;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visited[i][j] && matrix[i][j] == 1)
            {
                int minRow = i;
                int minCol = j;
                int maxRow = i;
                int maxCol = j;
                dfs(N, i, j, matrix, visited, minRow, minCol, maxRow, maxCol);
                    
                areas.push_back((maxRow - minRow + 1)* (maxCol - minCol +1));
            }
        }
    }
    
    sort(areas.begin(), areas.end(), [](const int& a1,const int& a2)
         {
             return a1 > a2;
         });
    
    size_t areasCount = areas.size();
    for(size_t i = 0; i < areasCount; i++)
    {
        cout << areas[i] << " ";
    }
    return 0;
}
