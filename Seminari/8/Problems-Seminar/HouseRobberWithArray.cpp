//Идеята е като сме на дадена къща - можем или да я оберем (нейното value + value-то на къщата през едно преди нея) или да я пропуснем (взимаме value-то получено при къщата точно преди нея)
//По този начин за всяко число в масива пазим максимума, който можем да оберем
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> maxDP(nums.size(), 0);
        
        maxDP[0] = nums[0];
        maxDP[1] = max(nums[0], nums[1]);
        
        for(size_t i = 2; i < nums.size(); i++) {
            maxDP[i] = max(maxDP[i - 1], nums[i] + maxDP[i - 2]);
        }
        
        return maxDP[maxDP.size() - 1];
    }
};
