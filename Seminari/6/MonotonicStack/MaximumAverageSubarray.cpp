class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        queue<int> subarray;
        double currMax = 0;
        
        for(int i = 0; i < k; i++)
        {
            subarray.push(nums[i]);
            currMax += nums[i];
        }

        double currSum = currMax;
        for(int i = k; i < size; i++)
        {
            currSum = (currSum - subarray.front() + nums[i]);
            subarray.pop();
            subarray.push(nums[i]);

            if(currSum > currMax)
                currMax = currSum;
        }
        return currMax / k; //търсим average
    }
};
