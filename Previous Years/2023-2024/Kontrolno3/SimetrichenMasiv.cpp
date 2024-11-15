#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool isSymmetric(vector<int>& nums)
{
    stack<int> symmetry;
    for(auto num: nums)
    {
        if(num >0)
            symmetry.push(num);
        else
        {
            if(symmetry.empty() || symmetry.top() != -num)
                return false;
            else
                symmetry.pop();
        }
    }
    return symmetry.empty();
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i = 0; i < N;i++)
    {
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int j = 0; j < size;j++)
        {
            cin >> nums[j];
        }
        
        if(isSymmetric(nums))
            cout << "YES" <<'\n';
        else
            cout <<"NO"<<'\n';
    }
    return 0;
}
