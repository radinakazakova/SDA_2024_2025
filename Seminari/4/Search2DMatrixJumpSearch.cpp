// Jump search on last column, защото ни напомня на джъмп
// Then linear in the row

#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int idxRows = 0;
        while (idxRows < rows && target > matrix[idxRows][cols - 1])
        {
            idxRows++;
        }

        if (idxRows == rows) //превъртяли сме всички редове, не сме намерили индекс - target е по-голям от най-големия елемент
        {
            return false;
        }

        for (int j = 0; j < cols; j++) //linear
        {
            if (matrix[idxRows][j] == target)
            {
                return true;
            }
        }

        return false;
    }
};
