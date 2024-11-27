class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int qCount = queries.size();
        int numsSize = nums.size();
        int counter = 0;
        unordered_map<int,int> m; //first = occurence in array, second = index in array
        vector<int> res;
        for(int i = 0; i < numsSize; i++)
        {
            if(nums[i] == x) //ignore other
            {
                counter++;
                m[counter] = i;
            }
        }

        for(int i = 0; i < qCount; i++)
        {
            if(m.find(queries[i]) != m.end())
                res.push_back(m[queries[i]]);

            else
                res.push_back(-1);
        }
        return res;
    }
};
