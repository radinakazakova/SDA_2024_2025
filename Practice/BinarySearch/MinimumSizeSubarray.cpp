//binary prez sizes i sliding window, za da namerim dali size-a go ima
class Solution {
public:
    bool foundSum(vector<int>& nums, int size, int target) //sliding window с фиксирана дължина
    {
        int sum = 0;
        for(int i=0;i<size;i++)sum+=nums[i]; //макс сума от 0 до мид сайз на прозореца
        int l=0;
        int r=size;
        int maxi=sum; //временната макс сума
        while(r<nums.size()){
            sum-=nums[l++]; //плъзгам прозореца с 1 позиция на всяка итерация
            sum+=nums[r++];
            maxi=max(sum,maxi); //ако има по-голяма сума, я взимаме
        }
        return maxi>=target;//сумата да е по-голяма или равна на търсената  
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize =1;
        int maxSize = nums.size();
        int minLen = INT_MAX;

        while(minSize <= maxSize)
        {
            int mid = minSize + (maxSize - minSize)/2;

            if(foundSum(nums, mid, target))
            {
                maxSize = mid - 1;
                minLen = mid;
            }
            else
                minSize = mid + 1;
        }
        return (minLen == INT_MAX) ? 0:minLen;
    }
};
