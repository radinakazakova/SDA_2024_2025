//моето решение
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string S;
    std::getline(std::cin, S);
    int len = S.size();
    
    //vector<pair<char, int>> word(len);
    vector<int> count(256, 0); //ASCII
    
    for(char& i: S)
    {
        count[i]++;
    }
    
    vector<int> indexes;
    for(int i = 0; i < len; i++)
    {
        if(count[S[i]] == 1)
            indexes.push_back(i);
    }
    
    for(int i = 0; i < indexes.size(); i++)
    {
        cout << indexes[i] << ' ';
    }
    
    return 0;
}
