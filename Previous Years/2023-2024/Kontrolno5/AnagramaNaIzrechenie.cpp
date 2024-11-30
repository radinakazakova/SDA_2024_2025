#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

bool canMakeSentence(unordered_map<string, int>& sentence1, int words)
{
    vector<string> secondSentence(words);

    for (int i = 0; i < words; i++) {
        cin >> secondSentence[i];
    }
    
    for(auto word: secondSentence)
    {
        if(sentence1[word])
            sentence1[word]--;
        else
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int testCount;
    cin >> testCount;
    
    for(int t = 0; t < testCount; t++)
    {
        int words1, words2;
        cin >> words1 >> words2;
        unordered_map<string, int> sentence1;

        for(int i = 0; i < words1; i++)
        {
            string word;
            cin >> word;
            sentence1[word] += 1;
        }
        
        if (words2 > words1) {
            cout << "No\n";
            string skip; 
            for (int i = 0; i < words2; i++) 
                cin >> skip;
        } 
        else if (canMakeSentence(sentence1, words2)) {
            cout << "Yes\n";
        } 
        else {
            cout << "No\n";
        }
        
    }
    return 0;
}
