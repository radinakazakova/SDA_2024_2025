#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> nums(N);
    unordered_set<int> present;
    for(int i =0; i < N;i++)
    {
        cin >> nums[i];
        present.insert(nums[i]);
    }
    
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++)
    {
        int el;
        cin >> el;
        
        if(present.count(el))
        {
            int firstOccurence = std::lower_bound(nums.begin(), nums.end(), el) - nums.begin();
            int lastOccurence = std::upper_bound(nums.begin(), nums.end(), el) - nums.begin() -1;
            cout << firstOccurence << " " << lastOccurence << '\n';
        }
        else
        {
            int position = std::upper_bound(nums.begin(), nums.end(), el) - nums.begin();
            cout << position << '\n';
        }
    }
    return 0;
}
