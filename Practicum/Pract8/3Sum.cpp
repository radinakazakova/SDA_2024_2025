class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //nums[i] + nums[j] + nums[k] = 0
        //target = - nums[i] = nums[j] + nums[k]
        sort(nums.begin(), nums.end());
        int size = nums.size();
        set<vector<int>> s; //set от тройките, които изпълняват условието (сет, за да са уникални)

        for(int i = 0; i < size; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) //скипваме повтарящите се
            {
                continue;
            }
            int k = size - 1;
            int j = i +1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};
