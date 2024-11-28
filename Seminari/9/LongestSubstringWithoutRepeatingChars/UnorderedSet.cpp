class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int currLen = 0;
        int left = 0;//sledim koe e nachaloto na substring-a

        for(int right = 0; right < s.size(); right++) //s right shte dobavqme nov character
        {
            if(st.find(s[right]) == st.end()) //nqma go, dobavqme go, update-vame duljinata
            {
                st.insert(s[right]);
                currLen = max(currLen, right - left + 1);
            }
            else
            {
                while(st.count(s[right])) //nameri li sme povtarqshto i dokato ne go mahnem shte iztrivame tezi, koito sa v nachaloto na tekushtiq substring
                {
                    st.erase(s[left]);
                    left++;
                }
                st.insert(s[right]);
            }
        }
        return currLen;
    }
};
