//моето първо решение
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, -1);

        //monotonic stack
        bool loop = false; //za da zavurtim oshte vednuj za posledniq element
        stack<int> monotonic, indexes;
        for(int i = 0; i < size; i++)
        {
            while(!monotonic.empty() && nums[i] > monotonic.top())
            {
                res[indexes.top()] = nums[i];
                indexes.pop();
                monotonic.pop();
            }
            indexes.push(i);
            monotonic.push(nums[i]);

            if(i == size - 1)
            {
                if(loop)
                    break;
                i = -1;
                loop = true;
            }
        }


        return res;
    }
};
