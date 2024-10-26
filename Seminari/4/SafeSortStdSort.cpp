#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> nums(N);
    for(int i = 0; i < N; i++)
    {
       cin >> nums[i];
    }
    
    if (count(nums.begin(), nums.end(), "0") == N)
    {
        cout << 0 << endl;
        return 0;
    }
    
    std::sort(nums.begin(), nums.end(), [](const string& first, const string& second)
              {
                return first + second > second + first; //koq konkatenaciq e po-golqma
              });
    
    for (const string &s : nums)
    {
        cout << s;
    }

    cout << endl;
    return 0;
}
