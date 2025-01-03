#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
    int x, y;
    int time;
    
    bool operator<(const Node& other) const
    {
        return time > other.time;
    }
};
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int x, int y, int n, int m) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> walls(rows, vector<int>(cols));
    
    char input;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> input;
            walls[i][j] = (input == '#' ? 1 : 0);
        }
    }
    
    vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
    priority_queue<Node> nextToProcess;
    
    //krainite pozicii se dostigat nai-burzo ot tqh samite
    for(int i = 0; i < cols; i++)
    {
        minTime[0][i] = walls[0][i];
        minTime[rows-1][i] = walls[rows-1][i];
        nextToProcess.push({0, i, walls[0][i]});
        nextToProcess.push({rows-1, i, walls[rows-1][i]});
    }
    
    for(int i = 1; i < rows - 1; i++)
    {
        minTime[i][0] = walls[i][0];
        minTime[i][cols-1] = walls[i][cols-1];
        nextToProcess.push({i, 0, walls[i][0]});
        nextToProcess.push({i,cols -1, walls[i][cols - 1]});
    }
    
    //dijkstra
    while(!nextToProcess.empty())
    {
        auto curr = nextToProcess.top();
        nextToProcess.pop();
        
        if(minTime[curr.x][curr.y] < curr.time)
        {
            continue;
        }
        for(int i = 0; i < 4; i++) {
            int newX = curr.x + directions[i][0];
            int newY = curr.y + directions[i][1];
            if(isValid(newX, newY, rows, cols)) 
            {
                int newTime = curr.time + walls[newX][newY];
                if(minTime[newX][newY] > newTime)
                {
                    minTime[newX][newY] = newTime;
                    nextToProcess.push({newX, newY, newTime});
                }
            }
        }
    }
    
    int maxTime = 0; //nachalna poziciq, kudeto time e maximalno i nqma stena
    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < cols - 1; j++)
        {
            if (!walls[i][j] && minTime[i][j] > maxTime)
            {
                maxTime = minTime[i][j];
            }
        }
    }
    
    int countPositions = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(!walls[i][j] && minTime[i][j] == maxTime)
                countPositions++;
        }
    }
    
    cout << countPositions;
    return 0;
}
