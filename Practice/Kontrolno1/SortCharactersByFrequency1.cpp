//оригиналното ми решение
class Solution {
public:
    bool isUpper(char ch)
    {
        return ch >= 'A' && ch <= 'Z';
    }
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    int getDigit(char ch)
    {
        return ch - '0';
    }
    int getUpperDigit(char ch)
    {
        return ch - 'A';
    }
    int getLowerDigit(char ch)
    {
        return ch - 'a';
    }

    string frequencySort(string s) {
        int len = s.size();
        //string copy = s;

        vector<pair<int,char>> count(26*2 + 10);
        int offsetLower = 10;
        int offsetUpper = 10 + 26;

        for(int i = 0; i < len; i++)
        {
            if(isDigit(s[i]))
            {
                int digit = getDigit(s[i]);
                count[digit].first++;
                count[digit].second = s[i];
            }
            else if(isUpper(s[i]))
            {
                int digit = getUpperDigit(s[i]) + offsetUpper;
                count[digit].first++;
                count[digit].second = s[i];
            }
            else
            {
                int digit = getLowerDigit(s[i]) + offsetLower;
                count[digit].first++;
                count[digit].second = s[i]; 
            }
        }

        sort(count.begin(), count.end(), [](const pair<int,char>& f, const pair<int,char>& s){
            return f.first > s.first;
        });

        string sorted = "";

        for(int i = 0; i < (26*2 + 10); i++)
        {
            if(count[i].first == 0)
                continue;
            sorted.append(count[i].first, count[i].second); //append 'second' times 'first'
        }
        return sorted;
    }
};
