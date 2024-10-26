class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = cols - 1;

        while(row < rows && col >= 0) //вървим от последна колона, първи ред - най-малкото най-голямо число
        {
            if(matrix[row][col] < target)
            {
                row++;
                continue;
            }
            
            if (matrix[row][col] > target)
            {
                col--;
                continue;
            }

            return true;
        }
        return false;
    }
};
