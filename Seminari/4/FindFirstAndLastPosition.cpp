class Solution {
public:
    int lowerBound(vector<int>& nums, int target)
    {
        int res = -1;
        int left = 0; 
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
            {
                res = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return res;
    }

    int upperBound(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;

        while(left <= right)
        {
            int mid = left +(right - left)/2;
            if(nums[mid] == target)
            {
                res = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid -1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = lowerBound(nums, target);
        if(result[0] == -1)
            return vector<int> {-1,-1};
        result[1] = upperBound(nums, target);
        return result;
    }
};
