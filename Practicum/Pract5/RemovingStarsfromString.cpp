class Solution {
public:
    string removeStars(string s) {
        string res;

        for(auto ch: s)
        {
            if(ch != '*')
            {
                res.push_back(ch);
            }
            else
            {
                res.pop_back();
            }
        }
        return res;
    }
};
