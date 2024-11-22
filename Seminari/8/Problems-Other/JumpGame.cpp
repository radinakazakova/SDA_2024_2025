class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxReach = 0;
        for(int i = 0; i < size; i++)
        {
            if(maxReach < i)
                return false;
            maxReach = max(i + nums[i], maxReach); //i + nums[i], защото търсим по индекс до къде можем да стигнем максимум
        }
        return true;
    }
};
