#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<string> input;
    unordered_map<string, int> count;
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        input.push_back(word);
        count[word]++;
    }
    
    for(auto word: input)
    {
        cout << count[word] << " ";
    }
    return 0;
}
