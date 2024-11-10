//моя си задача - да се намери прозореца с максимален елемент
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == k)
            return nums;
        
        vector<int> res(k);
        deque<int> window;
        int currMax = INT_MIN;
        for(int i = 0; i < k; i++)
        {
            window.push_back(nums[i]);
            if(nums[i]>currMax)
                currMax = nums[i];
        }

        int counter = 0;
        for(int i = k; i < size; i++)
        {
            if(nums[i] <= currMax)
            {
                counter++;
            }
            else
            {
                currMax = nums[i];
                while(counter + 1) //+1 за да направим място за nums[i], освен че махаме отпред с counter
                {
                    counter--;
                    window.pop_front();
                }
            }
            window.push_back(nums[i]);
        }

        for(int i = 0; i < k; i++)
        {
            res[i] = window.front();
            window.pop_front();
        }

        return res;
    }
};
