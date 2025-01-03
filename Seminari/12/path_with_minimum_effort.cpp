struct Node
{
    int x, y;
    int difference;

    bool operator<(const Node& other) const
    {
        return difference > other.difference;
    }
};

vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
    bool isValid(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> differences(m, vector<int>(n, INT_MAX));
        priority_queue<Node> nextToProcess;
        nextToProcess.push({0,0,0});
        differences[0][0] = 0;

        while(!nextToProcess.empty())
        {
            auto current = nextToProcess.top();
            nextToProcess.pop();

            if(differences[current.x][current.y] < current.difference){
                continue;
            }

            if(current.x == m - 1 && current.y == n - 1){
                return current.difference;
            }

            for(int i = 0; i < 4; i++) 
            {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];
                if(isValid(newX, newY, m, n)) 
                {
                    int newDiff = max(current.difference, abs(heights[current.x][current.y] - heights[newX][newY]));

                    if(newDiff < differences[newX][newY])
                    {
                        differences[newX][newY] =  newDiff;
                        nextToProcess.push({newX, newY, newDiff});
                    }
                }
            }
        }
        return 0;
    }
};
