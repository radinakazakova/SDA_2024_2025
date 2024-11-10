//2 pointer solution

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = -1, right = -1;
        
        // Traverse from left to right to determine the right boundary
        int max_seen = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] < max_seen) {
                right = i;  // Update right boundary if current element is less than max_seen
            } else {
                max_seen = nums[i];  // Update max_seen if current element is greater or equal
            }
        }

        // Traverse from right to left to determine the left boundary
        int min_seen = nums[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            if (nums[i] > min_seen) {
                left = i;  // Update left boundary if current element is greater than min_seen
            } else {
                min_seen = nums[i];  // Update min_seen if current element is smaller or equal
            }
        }

        // If left and right boundaries are found, return the length of the subarray
        return (right == -1) ? 0 : right - left + 1;
    }
};
