#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        unordered_map<char, int> count;
        unordered_map<int, int> freq;
        
        for(auto w: word)
        {
            count[w]++;
        }
        
        for(auto [l, c]: count)
        {
            freq[c]++;
        }
        
        if(freq.size() >= 3)
        {
            cout << 0 << '\n'; //imame 3 ili poveche razlichni razmera - nqma kak da gi svedem do 1 samo s 1 premahvane
            continue;
        }
        if(freq.size() == 1)
        {
            for(auto f: freq)
            {
                if(f.first != 1 &&f.second!= 1)
                    cout << 0 <<  '\n';
                else 
                    cout << 1 << '\n';
            }
        }
        else if(freq.size() == 2)
        {
            auto it = freq.begin();
            int freq1 = it->first, count1 = it->second;
            ++it;
            int freq2 = it->first, count2 = it->second;

            //imame 1 chislo 1 put, ako freq2 go ima 1 put sushto mahame freq1
            if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
                cout << 1 << '\n';
                continue;
            }
        
            //razlikata v dvete freq e 1 => ako mahnem po-golqmoto shte se svede do po-malkoto
            if (abs(freq1 - freq2) == 1) {
                if ((freq1 > freq2 && count1 == 1) || (freq2 > freq1 && count2 == 1)) {
                    cout << 1 << '\n';
                    continue;
                }
            }
            cout << 0 << '\n';
        }
        
    }
    return 0;
}
