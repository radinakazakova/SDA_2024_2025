#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    unordered_map<int, int> numIdx;    
    vector<int> numbers;
    int num;
    int startIdx = 0;
    int currLen = INT_MIN;
    int maxLen = INT_MIN;
    for(int currIdx = 0; currIdx < N; currIdx++)
    {
        cin >> num;
        numbers.push_back(num);
        
        if(numIdx.count(num))
        {
            for(int i = startIdx; i < numIdx[num]/* index of the previous encounter of the number*/; i++)
            {
                numIdx.erase(numbers[i]);
            }
            startIdx = numIdx[num] + 1; //new start after previous encounter
            numIdx[num] = currIdx; //new encounter update
        }
        else 
        {
            numIdx[num] = currIdx;
            currLen = currIdx - startIdx + 1;
            if(currLen > maxLen)
                maxLen = currLen;
        }
    }

    cout << maxLen;
    return 0;
}
