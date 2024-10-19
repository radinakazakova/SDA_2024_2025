//по-кратко решение, същата логика
//заделя памет за всички ascii до 'z'
//така не смятаме offset

class Solution {
public:
    
    string frequencySort(string s) {
        vector<pair<int,char>> count(123); //ascii values 0=48 z=122
        string ans = "";

        for(char& ch: s) //iterate through s
        {
            int frequency = count[ch].first;
            count[ch] = {frequency+1, ch}; //тук инициализираме всички, защото вектора ни е празен, count[ch].first++; count[ch].second = ch; е по-бавно
        }

        sort(count.begin(), count.end(), [&](const pair<int,char>& f, const pair<int,char>& s){ //[&] is faster
            return f.first > s.first;
        });
        
        for(auto& iter: count) //iterate through count, iter will be equal to count[i]
        {
            char ch = iter.second;
            int frequency = iter.first;
            string temp = string(frequency, ch); //създава стринг с 'ch' 'frequency' пъти
            ans += temp;
        }
        return ans;
    }
};
