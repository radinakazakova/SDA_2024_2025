class Solution {
public:
    string removeDuplicates(string s) {
        string word; //използваме го като стак, за да го върнем по-лесно

        for(auto w: s)
        {
            if(!word.empty() && word.back() == w)
            {
                word.pop_back();
            }
            else
            {
                word.push_back(w);
            }
        }
        return word;
    }
};
