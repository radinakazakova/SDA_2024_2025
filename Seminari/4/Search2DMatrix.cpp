//моето решение

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return mid;

            else if(nums[mid] > target)
                right = mid -1;
            else
                left = mid + 1;
        }
        return -1;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = cols - 1;

        int rowsIndex = 0;

        while(rowsIndex < rows)
        {
            if(matrix[rowsIndex][left] <= target && matrix[rowsIndex][right] >= target)
            {
                if(binarySearch(matrix[rowsIndex], target) != -1)
                    return true;
                else 
                    return false;
            }
            else
                rowsIndex++;
        }
        return false;
    }
};
