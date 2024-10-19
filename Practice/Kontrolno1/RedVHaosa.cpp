#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<int,int>> nums;
    int input;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        nums.push_back(pair<int,int>(input,i));
    }
    
    sort(nums.begin(), nums.end(), [](const pair<int,int>& f, const pair<int,int>& s){
        if(f.first == s.first) //важна проверка, така го правим стабилен, запазва поредността на числата
        {
            return f.second < s.second;
        }
        return f.first < s.first;
    });
    
    for(int i = 0; i < n; i++)
    {
        nums[i].first = i;
    }
    
    sort(nums.begin(), nums.end(), [](const pair<int,int>& f, const pair<int,int>& s){
        return f.second < s.second;
    });
    
    for(int i = 0; i < n; i++)
    {
        cout << nums[i].first << ' ';
    }
    
    return 0;
}
