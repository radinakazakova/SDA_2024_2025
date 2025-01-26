#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    map<string, int> wordsCount;
    string word;
    
    while(cin >> word)
    {
        wordsCount[word]++;
    }
    
    for(auto& w: wordsCount)
    {
        if(w.second > 1)
            continue;
        cout << w.first << '\n';
    }
    
    return 0;
}
