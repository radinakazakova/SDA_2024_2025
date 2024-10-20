//Решение с insertion sort наобратно
//добавя се елемент в края и се премества по-напред, където му е мястото

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printMedian(vector<int>& nums)
{
    int size = nums.size();
    int mid = size / 2;
    
    if(!(size & 1))
    {
        double median = (nums[mid] + nums[mid - 1]) / 2.0;
        cout << median << '\n';
    }else
    {
        cout << nums[mid] << '\n';
    }
}

void insertNumInArray(vector<int>& nums, int element)
{
    nums.push_back(element);
    
    int idx = nums.size() - 1 - 1;
    
    while(idx >= 0 && nums[idx] > element)
    {
        nums[idx + 1] = nums[idx];
        idx--;
    }
    nums[idx + 1] = element;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;    
    vector<int> input;
    
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        insertNumInArray(input, num);
        
        printMedian(input);
    }
    return 0;
}
