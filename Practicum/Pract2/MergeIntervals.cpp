class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& f, const vector<int>& s){
            return f[0] < s[0]; //sortira intervalite po purva komponenta - po-malkoto chislo 
        });

        vector<vector<int>> merged; //vuv vectora imlementiranoto premahvane e bavno, zatova nov masiv
        vector<int> curr = intervals[0];
        for(int i = 0; i < intervals.size(); i++)
        {
            if(curr[1] >= intervals[i][0]) //sravnqvame kraq na curr s nachaloto na i-tiq. ako sa ravni syshto suvpadat
            {
                curr[1] = max(curr[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(curr);
                curr = intervals[i];
            }
        }
        merged.push_back(curr);
        return merged;
    }
};
