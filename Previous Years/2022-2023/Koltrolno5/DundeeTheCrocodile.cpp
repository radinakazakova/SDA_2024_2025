#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string word;
    
    unordered_set<string> seen;
    set<string> res;
    
    while(cin >> word)
    {
        if(res.count(word) && seen.count(word))
        {
            res.erase(word);
            continue;
        }
        else if(seen.count(word))
        {
            continue;
        }
        
        res.insert(word);
        seen.insert(word);
    }
    
    for(auto word: res)
    {
        cout << word << '\n';
    }
    
    return 0;
}
