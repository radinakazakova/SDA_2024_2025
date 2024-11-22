class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { //директно мажем върху матрицата
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++ )
            {
                if(i == 0 && j == 0) //начално квадратче
                    continue;
                
                if(i == 0) //първа редица зависи само отлявото квадратче
                {
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }
                else if(j == 0) //първа колона зависи само от горното квадратче
                {
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }
                else
                {
                    grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
                }
            }
        }
        return grid[rows - 1][cols-1];
    }
};
