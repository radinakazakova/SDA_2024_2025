#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Counting sort - O(n) , in descending order

void countingAndPrint(vector<int>& nums, int size)
{
    int maxEl = *max_element(nums.begin(), nums.end());
    int minEl = *min_element(nums.begin(), nums.end()); //minEl e kato offset
    
    int len = maxEl - minEl + 1;
    vector<int> count(len, 0);
    
    for(int i = 0; i < size;i++)
    {
        count[nums[i] - minEl]++;
    }
    
    for(int i = len - 1; i >= 0; --i)
    {
        int numCount = count[i];
        if(numCount == 0)
            continue;
        while(numCount)
        {
            cout << i + minEl << ' ';
            numCount--;
        }
    }
}

int main() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);    
    
    int N;
    cin >>N;
    vector<int> nums;
    for(int i = 0; i <N; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    countingAndPrint(nums, nums.size());
    return 0;
}
