class Solution {
public:
    string hash(string& str)
    {
         int counter[26] = {0};

        for (char c : str)
        {
            counter[c - 'a']++; //kolko puti se sreshta bukva
        }

        string myhash;
        for (int c = 0; c < 26; c++)
        {
            if (!counter[c])
            {
                continue;
            }
            //hash-a shte izglevda kato: 2a1c3b... (koeto e podhodqshto za dumi s ednakvi bukvi)
            myhash += std::to_string(counter[c]); //kolko ot bukvata ima
            myhash += (c + 'a'); //dobavqme bukvata
        }
        return myhash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(auto str: strs)
        {
            string currHash = hash(str);
            
            m[currHash].push_back(str);
        }

        vector<vector<string>> res;

        for(auto words: m)
        {
            res.push_back(words.second);
        }
        return res;
    }
