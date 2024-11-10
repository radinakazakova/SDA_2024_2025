//същата логика, има допълниелен външен цикъл, за да се завърти два пъти търсенето

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n,-1);
        for(int j=0;j<2;j++)
        {
            for(int i=0;i<nums.size();i++)
            {
                while(st.empty()==false && nums[st.top()]<nums[i])
                {
                    int pos = st.top();
                    st.pop();
                    ans[pos] = nums[i];
                }
                st.push(i);
                //cout<<nums[st.top()]<<endl;
            }
        }
        return ans;
    }
};
