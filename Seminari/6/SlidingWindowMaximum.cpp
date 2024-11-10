class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int size = nums.size();
        if(size == 1 || size == 0)
            return nums;

        deque<pair<int,int>> maximums;
        for(int i = 0; i < size; i++)
        {
            if(!maximums.empty() && maximums.front().second < i - k + 1)
            {
                maximums.pop_front();
            }

            while(!maximums.empty() && nums[i] > maximums.back().first)
            {
                maximums.pop_back();
            }
            maximums.push_back({nums[i], i});

            if( i >= k - 1)
            {
                res.push_back(maximums.front().first);
            }
        }
        return res;
    }
};
