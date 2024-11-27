class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            int compliment = target - nums[i];
            if(m.find(compliment) != m.end())
            {
                return {i, m[compliment]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
