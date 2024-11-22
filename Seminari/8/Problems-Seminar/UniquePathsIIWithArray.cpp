class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int size = obstacleGrid[0].size();
        int rows = obstacleGrid.size();

        vector<long long> level(size, 0);

        for(int i = 0; i < size; i++) //определяме първия ред
        {
            if(obstacleGrid[0][i] == 1) {
                break; //чрез break всички след първото препятствие ще останат нули
            }

            level[i] = 1;
        }

        for(int i = 1; i < rows; i++) 
        {
            if(obstacleGrid[i][0] == 1) //ако сме на първа колона и има препятствие
                level[0] = 0; //променя ме му стойността само ако има препятствие защото иначе ще си бъде 1 заради началното състояние на робота или последното променено състояние което може да е 0
            
            for(int j = 1; j < size; j++) 
            {
                if(obstacleGrid[i][j] == 1) 
                {
                    level[j] = 0;
                    continue;
                }
                level[j] += level[j - 1];
            }
        }
        
        return level[size - 1];
    }
};
