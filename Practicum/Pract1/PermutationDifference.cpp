class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int len = s.size();
        int sum = 0;
        for(int i = 0; i < len;i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(s[i] == t[j])
                {
                    sum += abs(i-j);
                }
            }
        }
        return sum;
    }
};
