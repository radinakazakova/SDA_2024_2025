class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& f, const vector<int>& s){
            return f[0] < s[0]; //sortira intervalite
        });

        vector<vector<int>> merged; //vuv vectora premahvaneto e bavno zatova nov masiv
        vector<int> curr = intervals[0];
        for(int i = 0; i < intervals.size(); i++)
        {
            if(curr[1] >= intervals[i][0])
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
