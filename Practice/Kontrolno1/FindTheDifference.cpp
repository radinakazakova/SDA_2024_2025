class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0)
        {
            return t[0];
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int iter = 0;
        while(s[iter] == t[iter])
        {
            iter++;
        }
        return t[iter];
    }
};
