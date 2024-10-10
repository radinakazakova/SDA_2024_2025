class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
            int sumSingle = 0;
            int sumDouble = 0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<10 and nums[i]>0){
                    sumSingle = sumSingle + nums[i];
                }
                else if(nums[i]>=10 and nums[i]<100){
                sumDouble = sumDouble + nums[i];
                }
                else 
                return false;
            }
            if(sumSingle>sumDouble or sumSingle<sumDouble)
            return true;
            else 
            return false;
        
    }
};
