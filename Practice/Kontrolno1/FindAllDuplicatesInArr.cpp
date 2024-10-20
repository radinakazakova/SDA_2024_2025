//O(n*logn) reshenie
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> output;

        sort(nums.begin(), nums.end());

        int prev = nums[0];

        for(int i = 1; i<nums.size(); i++)
        {
            if(prev == nums[i])
            {
                output.push_back(prev);
            }
            else
            {
                prev = nums[i];
            }
        }
        return output;
    }
};
