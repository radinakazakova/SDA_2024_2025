class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std:sort(nums.begin(), nums.end());

        int len = nums.size();
        for(int i = 0; i < len - 1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }

        return false;
    }
};
