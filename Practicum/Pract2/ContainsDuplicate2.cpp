class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      vector<pair<int,int>> numsIdx;
      for(int i = 0; i < nums.size(); i++)
      {
        //[1,0], [0,1], [1,2], [1,3]
        numsIdx.push_back(pair<int,int>(nums[i],i));
      }

      sort(numsIdx.begin(), numsIdx.end());
        //[0,1],[1,0],[1,2],[1,3]!
       
        for(int i= 1; i < nums.size(); i++)
        {
            if(numsIdx[i].first == numsIdx[i - 1].first){
                if(abs(numsIdx[i].second - numsIdx[i-1].second) <= k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
