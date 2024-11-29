//моето решение от контролно 2 от 2023-2024

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

pair<int,int> findWeightSum(vector<pair<int,int>>& weights, int sum)
{
    int left = 0;
    int right = weights.size() - 1;
    
    while(left < right)
    {
        int currSum = weights[left].second + weights[right].second;
        if(currSum == sum){
            int pos1 = weights[left].first;
            int pos2 = weights[right].first;
            if(pos1 > pos2) 
                return {pos2,pos1};
            return {pos1, pos2};
        }
        else if(currSum > sum)
            right--;
        else
            left++;
    }
    return {-1,-1};
}

using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int queries;
    cin >> queries;
    
    int kgSum;
    int count;
    for(int i = 0; i < queries; i++)
    {
        cin >> kgSum;
        cin >> count;
        vector<pair<int,int>> weights(count);
        for(int j = 0; j < count; j++)
        {
            cin >> weights[j].second;
            weights[j].first = j+1;
        }
        sort(weights.begin(), weights.end(), [](const pair<int,int>& f, const pair<int,int>& s)
             {
                return f.second < s.second; 
             });
        auto positions = findWeightSum(weights, kgSum);
        cout << positions.first << " " << positions.second << '\n';
    }
    return 0;
}
