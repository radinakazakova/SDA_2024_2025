class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(auto word: strs)
        {
            string copyWord = word;
            sort(word.begin(), word.end());

            m[word].push_back(copyWord);
        }
        
        vector<vector<string>> res;
        for (auto anagram : m)
        {
            res.push_back(anagram.second);
        }
        return res;
    }
};
