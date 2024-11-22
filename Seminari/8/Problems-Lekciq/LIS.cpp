class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()); //за всеки елемент в масива колко е дължината на LIS
        
        for(size_t i = 0; i < nums.size(); i++) {
            dp[i] = 1; //база - за всеки елемент ще е 1 първоначално
            for(size_t j = 0; j < i; j++) { //за всеки преди него проверяваме, ако е по-малък проверяваме макса между досегашния lis и lis-а на предходния + 1
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
