class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int size = nums.size();
        int low = 0;
        int currSum = 0;
        int maxSum = 0;
        for(int high = 0; high < size; high++)
        {
            if(s.find(nums[high]) != s.end())
            {
                while(s.count(nums[high]))
                {
                    currSum -= nums[low];
                    s.erase(nums[low]);
                    low++;
                }
            }
            s.insert(nums[high]);
            currSum += nums[high];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
