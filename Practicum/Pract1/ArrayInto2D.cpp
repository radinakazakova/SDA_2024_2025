class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
       int len = nums.size();
       vector<vector<int>> matrix;
       vector<bool> seen(len, false);


       for(int i = 0; i < len; i++)
       {    
            int indexRows = 0;
            if(seen[nums[i] - 1])
            {
                continue;
            }

            for(int j = 0; j < len; j++)
            {
                if(nums[j] == nums[i])
                {
                    if (indexRows >= matrix.size()) 
                    {
                        matrix.push_back(vector<int>());
                    }
                    matrix[indexRows++].push_back(nums[j]);
                }
            }
            seen[nums[i] - 1] = true;
       }
        return matrix;
    }
};
