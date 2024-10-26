// Binary on the last column
// Then binary on the row

#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;

        int possibleRow = -1;

        while (left <= right) //binary на последната колона, за да разберем на кой ред трябва да е числото
        {
            int mid = left + (right - left) / 2; //mid в случая е индекс на някой ред

            if (target <= matrix[mid].back())
            {
                right = mid - 1;
                possibleRow = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (possibleRow == -1)
        {
            return false;
        }

        left = 0;
        right = matrix[possibleRow].size() - 1;

        int possibleCol = -1;

        while (left <= right) //binary на реда, на който трябва да се намира
        {
            int mid = left + (right - left) / 2;

            if (target <= matrix[possibleRow][mid])
            {
                right = mid - 1;
                possibleCol = mid; //приближаваме се до индекса на колоната, на който трябва да се намира, това му е макса всеки път
            }
            else
            {
                left = mid + 1; //ако не намерим нищо вдясно, колоната остава с макса си
            }
        }

        return matrix[possibleRow][possibleCol] == target;
    }
};
